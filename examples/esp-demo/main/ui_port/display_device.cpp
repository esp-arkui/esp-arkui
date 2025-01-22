/*
 * Copyright (c) 2021 Bestechnic (Shanghai) Co., Ltd. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "display_device.h"
#include "components/root_view.h"
#include "draw/draw_utils.h"
#include "gfx_utils/graphic_log.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_rgb.h"
#ifdef CONFIG_IDF_TARGET_ESP32P4
#include "esp_lcd_mipi_dsi.h"
#endif

namespace OHOS {

extern "C" {
    extern esp_lcd_panel_handle_t lcd_handle;
    SemaphoreHandle_t lcd_BinarySemaphore;
#ifdef CONFIG_IDF_TARGET_ESP32P4
    IRAM_ATTR bool _dpi_panel_general_cb(esp_lcd_panel_handle_t panel, esp_lcd_dpi_panel_event_data_t *edata, void *user_ctx)
    {
        xSemaphoreGive(lcd_BinarySemaphore);
        return 0;
    }
#elif defined CONFIG_IDF_TARGET_ESP32S3
    static bool _dpi_panel_general_cb(esp_lcd_panel_handle_t panel_io, const esp_lcd_rgb_panel_event_data_t *edata, void *user_ctx)
    {
        BaseType_t need_yield = pdFALSE;
        xSemaphoreGive(lcd_BinarySemaphore);
        // xSemaphoreGiveFromISR(lcd_BinarySemaphore, &need_yield);
        return 0;
    }
    static uint8_t *lcd_frame_buf[CONFIG_BSP_LCD_RGB_BUFFER_NUMS] = { NULL };
static uint8_t draw_buf_index = 0;
#endif

}


DisplayDevice::DisplayDevice(): tftFb_(nullptr)
{

    #if CONFIG_BSP_LCD_RGB_BUFFER_NUMS == 1
    esp_lcd_rgb_panel_get_frame_buffer(lcd_handle, CONFIG_BSP_LCD_RGB_BUFFER_NUMS, (void **)&lcd_frame_buf[0]);
#elif CONFIG_BSP_LCD_RGB_BUFFER_NUMS == 2
    esp_lcd_rgb_panel_get_frame_buffer(lcd_handle, CONFIG_BSP_LCD_RGB_BUFFER_NUMS, (void **)&lcd_frame_buf[0], (void **)&lcd_frame_buf[1]);
#elif CONFIG_BSP_LCD_RGB_BUFFER_NUMS == 3
    esp_lcd_rgb_panel_get_frame_buffer(lcd_handle, CONFIG_BSP_LCD_RGB_BUFFER_NUMS, (void **)&lcd_frame_buf[0], (void **)&lcd_frame_buf[1], (void **)&lcd_frame_buf[2]);
#endif
    // draw_buf_index = CONFIG_BSP_LCD_RGB_BUFFER_NUMS - 1;
    // tftFb_ = lcd_frame_buf[draw_buf_index];

    tftFb_ = (uint8_t *)heap_caps_malloc(HORIZONTAL_RESOLUTION * VERTICAL_RESOLUTION * DrawUtils::GetPxSizeByColorMode(RGB565), MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (tftFb_ == nullptr) {
        GRAPHIC_LOGE("Failed to malloc tftFb_");
    }
    lcd_BinarySemaphore = xSemaphoreCreateBinary();
#ifdef CONFIG_IDF_TARGET_ESP32P4
    // esp_lcd_dpi_panel_get_frame_buffer(lcd_handle, 1, (void **)&tftFb_);
    esp_lcd_dpi_panel_event_callbacks_t cbs = {
        .on_color_trans_done = _dpi_panel_general_cb,
    };
    ESP_ERROR_CHECK(esp_lcd_dpi_panel_register_event_callbacks(lcd_handle, &cbs, NULL)); // Register callbacks
#elif defined CONFIG_IDF_TARGET_ESP32S3
    esp_lcd_rgb_panel_event_callbacks_t cbs = {
        .on_frame_buf_complete = _dpi_panel_general_cb,
    };
    ESP_ERROR_CHECK(esp_lcd_rgb_panel_register_event_callbacks(lcd_handle, &cbs, NULL));
#endif

}

DisplayDevice *DisplayDevice::GetInstance()
{
    static DisplayDevice instance;
    if (!instance.isRegister_) {
        instance.isRegister_ = true;

    }
    return &instance;
}

BufferInfo *DisplayDevice::GetFBBufferInfo()
{
    static BufferInfo *bufferInfo = nullptr;
    if (bufferInfo == nullptr) {
        bufferInfo = new BufferInfo;

        bufferInfo->rect = {0, 0, HORIZONTAL_RESOLUTION - 1, VERTICAL_RESOLUTION - 1};
#if CONFIG_BSP_LCD_COLOR_FORMAT_RGB888
        bufferInfo->mode = RGB888;
#else
        bufferInfo->mode = RGB565;
#endif
        bufferInfo->color = 0x44;
        bufferInfo->phyAddr = bufferInfo->virAddr = tftFb_;

        // 3: Shift right 3 bits
        bufferInfo->stride = HORIZONTAL_RESOLUTION * (DrawUtils::GetPxSizeByColorMode(bufferInfo->mode) >> 3);
        bufferInfo->width = HORIZONTAL_RESOLUTION;
        bufferInfo->height = VERTICAL_RESOLUTION;
    }
    return bufferInfo;
}

void DisplayDevice::Flush(const Rect &flushRect)
{
    uint32_t x = flushRect.GetLeft();
    uint32_t y = flushRect.GetTop();
    // printf("flushRect: %d %d %d %d, %p\n", x, y, flushRect.GetRight(), flushRect.GetBottom(), tftFb_);
    const uint8_t *dest = static_cast<uint8_t *>(tftFb_) + ((HORIZONTAL_RESOLUTION * y ) * DrawUtils::GetByteSizeByColorMode(RGB565));
    esp_lcd_panel_draw_bitmap(lcd_handle, 0, y, HORIZONTAL_RESOLUTION, flushRect.GetBottom() + 1, dest);
    xSemaphoreTake(lcd_BinarySemaphore, portMAX_DELAY);

}

} // namespace OHOS
