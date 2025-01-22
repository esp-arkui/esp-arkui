#include <errno.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "nvs_flash.h"
#include "nvs.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_check.h"
#include "esp_memory_utils.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include "esp_vfs_dev.h"
#include "esp_console.h"
#include "linenoise/linenoise.h"
#include "bsp/display.h"
#include "bsp/touch.h"
#include "esp_vfs.h"
#include "esp_vfs_fat.h"
#include "esp_err.h"
#include "ui_port/ui_main.h"
#include "bsp/esp32_p4_function_ev_board.h"

static const char *TAG = "main";
#define PROMPT_STR CONFIG_IDF_TARGET

static void fs_init()
{
    const esp_vfs_fat_mount_config_t mount_config = {
        .max_files = 4,
        .format_if_mount_failed = false,
        .allocation_unit_size = CONFIG_WL_SECTOR_SIZE,
        .use_one_fat = false,
    };

    char *base_path = CONFIG_BSP_SD_MOUNT_POINT;
    ESP_LOGI(TAG, "Mounting FAT filesystem in read/write mode");
    static wl_handle_t wl_handle = WL_INVALID_HANDLE;
    esp_err_t err = esp_vfs_fat_spiflash_mount_rw_wl(base_path, "storage", &mount_config, &wl_handle);

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to mount FATFS (%s)", esp_err_to_name(err));
        return;
    }
    // bsp_sdcard_mount(); // 挂载SD卡

    {
        DIR *dir;
        struct dirent *entry;

        // 打开目录
        dir = opendir(base_path);
        if (dir == NULL) {
            fprintf(stderr, "Cannot open directory: %s\n", strerror(errno));
            return;
        }

        // 读取目录项
        while ((entry = readdir(dir)) != NULL) {
            printf("%s\n", entry->d_name);
        }

        // 关闭目录
        if (closedir(dir) == -1) {
            fprintf(stderr, "Cannot close directory: %s\n", strerror(errno));
            return;
        }

        return;
    }
}

// implementation for js_app_host.h: LP_TaskBegin
void LP_TaskBegin() {
}

// implementation for js_app_host.h: LP_TaskEnd
void LP_TaskEnd() {
}


static void initialize_nvs(void)
{
    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }
    ESP_ERROR_CHECK(err);
}

struct console_args {
    int argc;
    char **argv;
};

static void lvgljs_task(void *arg)
{
    struct console_args *args = arg;
    int tjs_render_init(int argc, char **argv);
    tjs_render_init(args->argc, args->argv);
    ESP_LOGW(TAG, "lvgljs task exit");
    vTaskDelete(NULL);
}

static int run_lvgljs(int argc, char **argv)
{
    static struct console_args args;
    args.argc = argc;
    args.argv = argv;

#define STACK_SIZE 2000 * 1024
    uint8_t *sleep_stack = (uint8_t *)heap_caps_malloc(STACK_SIZE, MALLOC_CAP_SPIRAM);
    static StaticTask_t sleep_task;

    ESP_LOGI(TAG, "Creating lvgljs task with stack %uB@%p", STACK_SIZE, sleep_stack);
    xTaskCreateStaticPinnedToCore((void *)lvgljs_task, "lvgljs", STACK_SIZE, &args, 1, sleep_stack, &sleep_task, 0);
    vTaskDelay(portMAX_DELAY);
#undef STACK_SIZE
    return 0;
}

static void register_command(void)
{

    // char *argv[] = {"lvgljs", "run", "/demo/calculator/index.js"};
    // tjs_render_init(3, argv);

    const esp_console_cmd_t cmd = {
        .command = "lvgljs",
        .help = "LVGL JavaScript Runtime",
        .hint = NULL,
        .func = &run_lvgljs,
    };
    ESP_ERROR_CHECK(esp_console_cmd_register(&cmd));
}

static void initialize_console(void)
{
    esp_console_repl_t *repl = NULL;
    esp_console_repl_config_t repl_config = ESP_CONSOLE_REPL_CONFIG_DEFAULT();
    // repl_config.task_stack_size = 100 * 1024;
    /* Prompt to be printed before each line.
     * This can be customized, made dynamic, etc.
     */
    repl_config.prompt = PROMPT_STR ">";
    repl_config.max_cmdline_length = 128;

    repl_config.history_save_path = "/demo/history.txt";
    ESP_LOGI(TAG, "Command history enabled");

    /* Register commands */
    esp_console_register_help_command();
    register_command();

#if defined(CONFIG_ESP_CONSOLE_UART_DEFAULT) || defined(CONFIG_ESP_CONSOLE_UART_CUSTOM)
    esp_console_dev_uart_config_t hw_config = ESP_CONSOLE_DEV_UART_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_console_new_repl_uart(&hw_config, &repl_config, &repl));

#elif defined(CONFIG_ESP_CONSOLE_USB_CDC)
    esp_console_dev_usb_cdc_config_t hw_config = ESP_CONSOLE_DEV_CDC_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_console_new_repl_usb_cdc(&hw_config, &repl_config, &repl));

#elif defined(CONFIG_ESP_CONSOLE_USB_SERIAL_JTAG)
    esp_console_dev_usb_serial_jtag_config_t hw_config = ESP_CONSOLE_DEV_USB_SERIAL_JTAG_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_console_new_repl_usb_serial_jtag(&hw_config, &repl_config, &repl));

#else
#error Unsupported console type
#endif

    ESP_ERROR_CHECK(esp_console_start_repl(repl));
}
uint32_t g_usable_size_cnt = 0;
uint32_t g_malloc_cnt = 0;
uint32_t g_realloc_cnt = 0;
uint32_t g_calloc_cnt = 0;
uint32_t g_free_cnt = 0;

static void fail_cb(size_t size, uint32_t caps, const char *function_name)
{
    ESP_LOGE(TAG, "Alloc failed: s:%d, cap:%x, f:%s\n", size, caps, function_name);
}

esp_lcd_panel_handle_t lcd_handle;
esp_lcd_touch_handle_t tp;

void app_main(void)
{

    heap_caps_register_failed_alloc_callback(fail_cb);
    gpio_config_t io_conf = {
        .intr_type = GPIO_INTR_DISABLE,
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = (1ULL << 5),
        .pull_down_en = 0,
        .pull_up_en = 0,
    };
    gpio_config(&io_conf);

    void stat_init(void);
    // stat_init();
    // esp_cpu_set_watchpoint(0, (void *)0x484225dc, 4, ESP_CPU_WATCHPOINT_STORE);

    esp_lcd_panel_io_handle_t lcd_io_handle;
    ESP_ERROR_CHECK(bsp_display_new(NULL, &lcd_handle, &lcd_io_handle));

    ESP_ERROR_CHECK(bsp_touch_new(NULL, &tp));

    bsp_display_backlight_on();

    fs_init();

    initialize_nvs();
    // initialize_console();

    UiMain();

}
