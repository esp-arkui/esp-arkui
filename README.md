# ESP-ArkUI

移植 Open Harmony arkui 子系统到 esp-idf 的仓库

## Demo 编译（[ESP32-P4-Function-EV-Board](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32p4/esp32-p4-function-ev-board/index.html)）

1. 下载源码

    ```shell
    mkdir arkui
    cd arkui
    repo init -u https://github.com/esp-arkui/manifest.git
    repo sync
    ```

2. 编译demo

   ```shell
   cd esp-arkui/examples/esp-demo
   idf.py flash
   ```

   

## 引用到自己的工程

需要修改工程的 CMakeLists.txt，下面是一个例子：
```cmake
# The following lines of boilerplate have to be in your project's CMakeLists
# in this exact order for cmake to work correctly
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)
add_compile_options(-fdiagnostics-color=always)
add_compile_definitions(HORIZONTAL_RESOLUTION=720 VERTICAL_RESOLUTION=1280) # Set resolution of screen

# Download arkui before build
set(ARKUILIB_DIR ${CMAKE_CURRENT_LIST_DIR}/arkui-lib)
message(STATUS "Install ArkUILib in ${ARKUILIB_DIR}")
execute_process(
    COMMAND bash -c "
    if [ ! -d \"${ARKUILIB_DIR}\" ]; then
        mkdir -p ${ARKUILIB_DIR}
        cd ${ARKUILIB_DIR}
        repo init -u https://github.com/esp-arkui/manifest.git
        repo sync | tee repo_sync.log
    else
        echo \"Directory ${ARKUILIB_DIR} already exists. Skipping initialization and sync.\"
    fi
    "
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

set(EXTRA_COMPONENT_DIRS ${ARKUILIB_DIR}/esp-arkui/components)

project(your_project)

```

## UI 开发工具

下载 DevEco Studio ：https://developer.huawei.com/consumer/cn/deveco-studio/
