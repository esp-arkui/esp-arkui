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

#include <cstring>
#include <stdio.h>

#include "ability_info.h"
#include "ability_manager.h"
#include "element_name.h"
#include "module_info.h"
#include "want.h"
#include "ace_log.h"
#include "global.h"

#define LAUNCHER_BUNDLE_NAME "com.huawei.launcher"
#define JS_BUNDLE_NAME "com.app.music_player"
#define JS_APP_PATH "/rootfs/showcase" // "/data/js"

#define CHECK_ERR(ret) \
    if (ret != 0) { \
        HILOG_ERROR("ability_js", "%s:%d", __FILE__, __LINE__); \
    } \

#define CHECK_ERR_TRUE(ret) \
    if (ret) { \
        HILOG_ERROR("ability_js", "%s:%d", __FILE__, __LINE__); \
    } \



static int StartJSApp()
{
    GLOBAL_ConfigLanguage("zh-CN");

    Want want = {nullptr};
    ElementName element = {nullptr};
    SetElementBundleName(&element, JS_BUNDLE_NAME);
    SetWantElement(&want, element);
    SetWantData(&want, JS_APP_PATH, strlen(JS_APP_PATH) + 1);
    CHECK_ERR(StartAbility(&want));
    ClearElement(&element);
    ClearWant(&want);
    printf("STUB %s:%d\n", __FILE__, __LINE__);
    return 0;
}

void RunApp(void)
{
    HILOG_INFO("ability_js", "ability_js - RunApp");
    StartJSApp();
}
