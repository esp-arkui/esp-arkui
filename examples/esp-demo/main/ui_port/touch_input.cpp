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
#include "touch_input.h"
#include "gfx_utils/graphic_log.h"
#include "graphic_config.h"
#include "esp_lcd_touch.h"

namespace OHOS {
TouchInput *TouchInput::GetInstance()
{
    static TouchInput instance;
    if (!instance.init) {
        instance.init = true;
    }
    return &instance;
}

extern "C" {
    extern esp_lcd_touch_handle_t tp;
}

bool TouchInput::Read(DeviceData &data)
{
    {
        assert(tp);

        static uint16_t touchpad_x, touchpad_y;
        uint16_t tx, ty;
        uint8_t touchpad_cnt = 0;
        /* Read data from touch controller into memory */
        esp_lcd_touch_read_data(tp);

        /* Read data from touch controller */
        bool touchpad_pressed = esp_lcd_touch_get_coordinates(tp, &tx, &ty, NULL, &touchpad_cnt, 1);
        if (touchpad_pressed && touchpad_cnt > 0) {
            touchpad_x = tx;
            touchpad_y = ty;
            data.state = STATE_PRESS;
        } else {
            data.state = STATE_RELEASE;
        }

        data.point.x = touchpad_x;
        data.point.y = touchpad_y;
    }


    // GRAPHIC_LOGD("Touch {%d, %d} %d", data.point.x, data.point.y, data.state);


    return false;
}
} // namespace OHOS
