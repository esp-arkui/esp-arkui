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
#include "freertos/task.h"
#include "esp_heap_caps.h"
#include "ui_main.h"
#include "pthread.h"
#include "core/render_manager.h"
#include "common/graphic_startup.h"
#include "common/image_decode_ability.h"
#include "common/input_device_manager.h"
#include "common/task_manager.h"
#include "display_device.h"
#include "engines/gfx/gfx_engine_manager.h"
#include "font/ui_font.h"
#include "font/ui_font_header.h"
#include "font/ui_font_vector.h"
#include "gfx_utils/graphic_log.h"
#include "graphic_config.h"
#include "hal_tick.h"
#include "touch_input.h"

#include "js_ability.h"
#include "js_debugger_config.h"
#include "product_adapter.h"
// #include "ability_manager_interface.h"

#define ENABLE_FPS
#ifdef ENABLE_ACE
#include "product_adapter.h"
#endif

#define FONT_MEM_LEN (2*1024 * 1024)
#define osDelay(ms) vTaskDelay(pdMS_TO_TICKS(ms))



void SetJSDebuggerConfig(int32_t defaultHeapSize)
{
    const int16_t bytes = 1024;
    OHOS::ACELite::DebuggerConfig jsDebuggerConfig;
    jsDebuggerConfig.startDebuggerServer = false;
    jsDebuggerConfig.snapshotMode = false;
    jsDebuggerConfig.heapSize = defaultHeapSize * bytes;
    OHOS::ACELite::Debugger::GetInstance().ConfigEngineDebugger(jsDebuggerConfig);
}

// void InitPage(OHOS::MainWidget *mainWidget, int16_t jsWindowHeight, int16_t jsWindowWidth, int16_t childPageHeight)
// {
//     // QString jsBundlePath = SimulatorConfig::GetInstance().GetConfigValue(CONFIG_KEY_JSBUNDLE_PATH);
//     // if (jsBundlePath.isNull() || jsBundlePath.isEmpty()) {
//     //     jsBundlePath = "";
//     // } else {
//     //     QFileInfo *file = new QFileInfo(jsBundlePath);
//     //     if (file->exists() == false) {
//     //         jsBundlePath = "";
//     //     }
//     // }
//     // int16_t defaultHeapSize = DEFAULT_JSHEAP_SIZE; // KB
//     // QString jsHeapSize = SimulatorConfig::GetInstance().GetConfigValue(CONFIG_KEY_JSHEAP_SIZE);
//     // if (!jsHeapSize.isNull() && !jsHeapSize.isEmpty()) {
//     //     int tempSize = jsHeapSize.toInt();
//         // if (tempSize >= MIN_JSHEAP_SIZE && tempSize <= MAX_JSHEAP_SIZE) {
//     //         defaultHeapSize = tempSize;
//     //     }
//     // }
//     // ChildWidget *childWidget = new ChildWidget(mainWidget, jsBundlePath, QString::number(defaultHeapSize));
//     // childWidget->setGeometry(QRect(0, jsWindowHeight, jsWindowWidth, childPageHeight));
//     SetJSDebuggerConfig(64);// KB
//     // childWidget->StartApp(jsBundlePath.toStdString().c_str());
//     // start all necessary mock threads
//     mockServices_.StartAll();
//     const uint32_t breakTime = 30;
//     QThread::msleep(breakTime);
//     StartAbility(path, "com.app.example");
// }

static void TerminateInterface(uint32_t token, bool forceStop)
{
    (void)(forceStop);
    // TerminateAbility(token);
    printf("TerminateInterface token:%u\n", token);
}

static void RegisterTerminateHandler()
{
    OHOS::ACELite::ProductAdapter::RegTerminatingHandler(TerminateInterface);
}


static void InitFontEngine()
{
    uint8_t *g_fontMemBaseAddr = (uint8_t *)heap_caps_malloc(FONT_MEM_LEN, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if (g_fontMemBaseAddr == nullptr) {
        GRAPHIC_LOGE("InitFontEngine malloc fontMemBaseAddr failed");
        return;
    }
#if ENABLE_VECTOR_FONT
    GRAPHIC_LOGD("InitFontEngine fontMemSize: %u", FONT_MEM_LEN);
    OHOS::GraphicStartUp::InitFontEngine(reinterpret_cast<uintptr_t>(g_fontMemBaseAddr), FONT_MEM_LEN, VECTOR_FONT_DIR, DEFAULT_VECTOR_FONT_FILENAME);
#else
    BitmapFontInit();
    std::string dPath(_pgmptr);
    size_t len = dPath.size();
    size_t pos = dPath.find_last_of('\\');
    dPath.replace((pos + 1), (len - pos), "..\\..\\simulator\\font\\font.bin");
    OHOS::GraphicStartUp::InitFontEngine(reinterpret_cast<uintptr_t>(g_fontMemBaseAddr), FONT_MEM_LEN,
                                         dPath.c_str(), nullptr);
#endif

#if ENABLE_ICU
    uint8_t *g_icuMemBaseAddr = (uint8_t *)heap_caps_malloc(OHOS::SHAPING_WORD_DICT_LENGTH, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT);
    if ( g_icuMemBaseAddr == nullptr) {
        GRAPHIC_LOGE("InitFontEngine malloc icuMemBaseAddr failed");
        return;
    }
    OHOS::GraphicStartUp::InitLineBreakEngine(reinterpret_cast<uintptr_t>(g_icuMemBaseAddr), OHOS::SHAPING_WORD_DICT_LENGTH, VECTOR_FONT_DIR, DEFAULT_LINE_BREAK_RULE_FILENAME);
#endif
}

static void InitImageDecodeAbility()
{
    uint32_t imageType = OHOS::IMG_SUPPORT_BITMAP | OHOS::IMG_SUPPORT_JPEG | OHOS::IMG_SUPPORT_PNG;
    OHOS::ImageDecodeAbility::GetInstance().SetImageDecodeAbility(imageType);
}

static void InitHal()
{
    OHOS::DisplayDevice *display = OHOS::DisplayDevice::GetInstance();
    OHOS::BaseGfxEngine::InitGfxEngine(display);

    OHOS::TouchInput *touch = OHOS::TouchInput::GetInstance();
    OHOS::InputDeviceManager::GetInstance()->Add(touch);
}

void InitUiKit(void)
{
    OHOS::GraphicStartUp::Init();
    // init display/input device
    InitHal();
    // init font engine
    InitFontEngine();
    // init suppot image format
    InitImageDecodeAbility();
}

extern void RunApp();
// __attribute__((weak)) void RunApp(void)
// {
//     GRAPHIC_LOGI("RunApp default");
// }

#ifdef ENABLE_ACE
static void RenderTEHandler()
{
}
#endif

static constexpr uint32_t UI_MAIN_TASK_DELAY = 5000;
static constexpr uint32_t ONE_SECOND = 1000;

namespace OHOS {
namespace AbilitySlite {
extern void __abilityFeatureInitialize();
}
}

#if __cplusplus
extern "C" {
#endif
void SAMGR_Bootstrap();
#if __cplusplus
}
#endif

static void *UiMainTask(void *arg)
{
    (void)arg;
    OHOS::AbilitySlite::__abilityFeatureInitialize();
    SAMGR_Bootstrap();
    // (void)pthread_setname_np(pthread_self(), "UiMain");
    // osDelay(UI_MAIN_TASK_DELAY);

    InitUiKit();
    RegisterTerminateHandler();
    RunApp();

#ifdef ENABLE_ACE
    const ACELite::TEHandlingHooks hooks = {RenderTEHandler, nullptr};
    ACELite::ProductAdapter::RegTEHandlers(hooks);
#endif
#if ENABLE_FPS_SUPPORT
    uint32_t start = OHOS::HALTick::GetInstance().GetTime();
#endif
    while (1) {
#ifdef ENABLE_ACE
        // Here render all js app in the same task.
        ACELite::ProductAdapter::DispatchTEMessage();
#endif
#if FULLY_RENDER
        DisplayDevice::GetInstance()->UpdateFBBuffer();
#endif
        uint32_t temp = OHOS::HALTick::GetInstance().GetTime();
        OHOS::TaskManager::GetInstance()->TaskHandler();
        uint32_t time = OHOS::HALTick::GetInstance().GetElapseTime(temp);
        if (time < OHOS::DEFAULT_TASK_PERIOD) {
            osDelay(OHOS::DEFAULT_TASK_PERIOD - time);
        }
#if ENABLE_FPS_SUPPORT
        if (OHOS::HALTick::GetInstance().GetElapseTime(start) >= ONE_SECOND) {
            GRAPHIC_LOGD("%u fps", (uint32_t)OHOS::RenderManager::GetInstance().GetFPS());
            start = OHOS::HALTick::GetInstance().GetTime();
        }
#endif
    }
    return nullptr;
}

#define UI_THREAD_STACK_SIZE (1024 * 32)
void UiMain(void)
{
    struct sched_param param = {0};

    pthread_t thread;
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setstacksize(&attr, UI_THREAD_STACK_SIZE);
    param.sched_priority = 15; // 15: UiMainTask priority
    // pthread_attr_setschedparam(&attr, &param);
    // (void)pthread_attr_setinheritsched(&attr, PTHREAD_EXPLICIT_SCHED);
    if (pthread_create(&thread, &attr, UiMainTask, nullptr) != 0) {
        GRAPHIC_LOGE("Failed to create UiMainTask");
    }
}
