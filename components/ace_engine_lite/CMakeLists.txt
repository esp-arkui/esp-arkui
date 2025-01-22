

set(TARGET_DIR ${ARKUILIB_DIR}/foundation/arkui/ace_engine_lite)

set(SRCS 
${TARGET_DIR}/frameworks/src/core/animation/transition_impl.cpp
${TARGET_DIR}/frameworks/native_engine/async/js_async_work.cpp
${TARGET_DIR}/frameworks/native_engine/async/message_queue_utils.cpp
${TARGET_DIR}/frameworks/common/log/ace_log.cpp
${TARGET_DIR}/frameworks/common/memory/ace_mem_base.cpp
${TARGET_DIR}/frameworks/src/core/base/dft_impl.cpp
${TARGET_DIR}/frameworks/src/core/base/async_task_manager.cpp
${TARGET_DIR}/frameworks/common/memory/cache/cache_manager.cpp
${TARGET_DIR}/frameworks/src/core/base/dfx_assist.cpp
${TARGET_DIR}/frameworks/src/core/base/event_util.cpp
${TARGET_DIR}/frameworks/src/core/base/js_debugger_config.cpp
${TARGET_DIR}/frameworks/src/core/base/js_fwk_common.cpp
${TARGET_DIR}/frameworks/src/core/base/key_parser.cpp
${TARGET_DIR}/frameworks/src/core/base/lazy_load_manager.cpp
${TARGET_DIR}/frameworks/src/core/base/lazy_load_watcher.cpp
${TARGET_DIR}/frameworks/src/core/base/locale_util.cpp
${TARGET_DIR}/frameworks/common/memory/mem_proc.cpp
${TARGET_DIR}/frameworks/common/memory/memory_heap.cpp
${TARGET_DIR}/frameworks/src/core/base/number_parser.cpp
${TARGET_DIR}/frameworks/src/core/base/product_adapter.cpp
${TARGET_DIR}/frameworks/src/core/base/string_util.cpp
${TARGET_DIR}/frameworks/src/core/base/system_info.cpp
${TARGET_DIR}/frameworks/src/core/base/time_util.cpp
${TARGET_DIR}/frameworks/src/core/components/analog_clock_component.cpp
${TARGET_DIR}/frameworks/src/core/components/camera_component.cpp
${TARGET_DIR}/frameworks/src/core/components/canvas_component.cpp
${TARGET_DIR}/frameworks/src/core/components/chart_component.cpp
${TARGET_DIR}/frameworks/src/core/components/circle_progress_component.cpp
${TARGET_DIR}/frameworks/src/core/components/clock_hand_component.cpp
${TARGET_DIR}/frameworks/src/core/components/component.cpp
${TARGET_DIR}/frameworks/src/core/components/component_utils.cpp
${TARGET_DIR}/frameworks/src/core/components/div_component.cpp
${TARGET_DIR}/frameworks/src/core/components/event_listener.cpp
${TARGET_DIR}/frameworks/src/core/components/horizon_progress_component.cpp
${TARGET_DIR}/frameworks/src/core/components/image_animator_component.cpp
${TARGET_DIR}/frameworks/src/core/components/image_component.cpp
${TARGET_DIR}/frameworks/src/core/components/input_button_component.cpp
${TARGET_DIR}/frameworks/src/core/components/input_checkbox_component.cpp
${TARGET_DIR}/frameworks/src/core/components/input_edittext_component.cpp
${TARGET_DIR}/frameworks/src/core/components/input_radio_component.cpp
${TARGET_DIR}/frameworks/src/core/components/list_adapter.cpp
${TARGET_DIR}/frameworks/src/core/components/list_component.cpp
${TARGET_DIR}/frameworks/src/core/components/marquee_component.cpp
${TARGET_DIR}/frameworks/src/core/components/panel_view.cpp
${TARGET_DIR}/frameworks/src/core/components/picker_view_component.cpp
${TARGET_DIR}/frameworks/src/core/components/qrcode_component.cpp
${TARGET_DIR}/frameworks/src/core/components/scroll_layer.cpp
${TARGET_DIR}/frameworks/src/core/components/slider_component.cpp
${TARGET_DIR}/frameworks/src/core/components/stack_component.cpp
${TARGET_DIR}/frameworks/src/core/components/swiper_component.cpp
${TARGET_DIR}/frameworks/src/core/components/switch_component.cpp
${TARGET_DIR}/frameworks/src/core/components/tab_bar_component.cpp
${TARGET_DIR}/frameworks/src/core/components/tab_content_component.cpp
${TARGET_DIR}/frameworks/src/core/components/tabs_component.cpp
${TARGET_DIR}/frameworks/src/core/components/text_component.cpp
${TARGET_DIR}/frameworks/src/core/components/video_component.cpp
${TARGET_DIR}/frameworks/src/core/components/video_view.cpp
# ${TARGET_DIR}/frameworks/src/core/context/ace_ability.cpp
${TARGET_DIR}/frameworks/src/core/context/ace_event_error_code.cpp
${TARGET_DIR}/frameworks/src/core/context/fatal_handler.cpp
${TARGET_DIR}/frameworks/src/core/context/js_ability.cpp
${TARGET_DIR}/frameworks/src/core/context/js_ability_impl.cpp
${TARGET_DIR}/frameworks/src/core/context/js_app_context.cpp
${TARGET_DIR}/frameworks/src/core/context/js_app_environment.cpp
${TARGET_DIR}/frameworks/src/core/context/js_framework_raw.cpp
${TARGET_DIR}/frameworks/src/core/context/js_profiler.cpp
${TARGET_DIR}/frameworks/src/core/context/js_timer_list.cpp
${TARGET_DIR}/frameworks/src/core/context/slite_ace_ability.cpp
${TARGET_DIR}/frameworks/src/core/dialog/js_dialog.cpp
${TARGET_DIR}/frameworks/src/core/directive/descriptor_utils.cpp
${TARGET_DIR}/frameworks/src/core/directive/directive_watcher_callback.cpp
${TARGET_DIR}/frameworks/native_engine/jsi/jsi.cpp
${TARGET_DIR}/frameworks/src/core/modules/app_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/dfx_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/dialog_module.cpp
${TARGET_DIR}/frameworks/module_manager/module_manager.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/app_data_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/cjson_parser.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/console_log_impl.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/console_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/date_time_format_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/intl_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/localization_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/number_format_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/image_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/preset_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/profiler_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/render_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/require_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/timer_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/syscap_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/version_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/router_module.cpp
${TARGET_DIR}/frameworks/src/core/modules/sample_module.cpp
${TARGET_DIR}/frameworks/src/core/resource/video_muted_image_res.cpp
${TARGET_DIR}/frameworks/src/core/resource/video_play_image_res.cpp
${TARGET_DIR}/frameworks/src/core/router/js_page_state.cpp
${TARGET_DIR}/frameworks/src/core/router/js_page_state_machine.cpp
${TARGET_DIR}/frameworks/src/core/router/js_router.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/app_style.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/app_style_item.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/app_style_list.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/app_style_manager.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/app_style_sheet.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/condition_arbitrator.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/link_queue.cpp
${TARGET_DIR}/frameworks/src/core/stylemgr/link_stack.cpp
${TARGET_DIR}/frameworks/src/core/wrapper/js.cpp
${TARGET_DIR}/frameworks/targets/platform_adapter.cpp
# targets/simulator/utils/js_heap_stats_dumper.cpp
# targets/simulator/utils/js_heap_stats_writer.cpp
# targets/simulator/mock/hal_sys_param.cpp
# targets/simulator/mock/message_queue_utils.cpp # the mocked message queue
# targets/simulator/mock/mock_services.cpp # the mocked message queue
# targets/simulator/mock/bms_interfaces/bundle_manager_mock.cpp # mock some BMS interfaces
# targets/simulator/mock/jsthread/js_thread.cpp
# targets/simulator/mock/vsyncthread/vsync_dispatch_manager.cpp
# targets/simulator/mock/vsyncthread/vsync_thread.cpp
# targets/simulator/mock/amsthread/ams_thread.cpp
# targets/simulator/mock/timerthread/timer_thread.cpp
# targets/simulator/mock/global_impl_mock.cpp
# targets/simulator/mock/ability_lite/slite/ability_saved_data.cpp
${TARGET_DIR}/frameworks/src/core/modules/presets/test/unittest/common/app_data_module_tdd_test.cpp
${TARGET_DIR}/../../../commonlibrary/utils_lite/timer_task/src/nativeapi_timer_task.c
# ${TARGET_DIR}/../../../commonlibrary/utils_lite/js/builtin/deviceinfokit/src/nativeapi_deviceinfo.cpp

${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/ability_info.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/ability_info_utils.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/bundle_info.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/bundle_info_utils.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/element_name.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/module_info.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/module_info_utils.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/slite/bundle_manager.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/slite/bundle_manager_inner.cpp
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/src/slite/bundlems_slite_client.cpp

)

set(INCLUDE_DIRS 
${TARGET_DIR}/../../bundlemanager/bundle_framework_lite/services/bundlemgr_lite/include
${TARGET_DIR}/../../bundlemanager/bundle_framework_lite/interfaces/inner_api/bundlemgr_lite
${TARGET_DIR}/../../bundlemanager/bundle_framework_lite/interfaces/inner_api/bundlemgr_lite/slite
${TARGET_DIR}/../../bundlemanager/bundle_framework_lite/interfaces/kits/bundle_lite
${TARGET_DIR}/../../../commonlibrary/utils_lite/timer_task/include
# ${TARGET_DIR}/../../../commonlibrary/utils_lite/js/builtin/deviceinfokit/include
# ${TARGET_DIR}/../../../commonlibrary/utils_lite/js/builtin/common/include
${TARGET_DIR}/../../../base/global/resource_management_lite/interfaces/inner_api/include
${TARGET_DIR}/../../../base/global/i18n_lite/interfaces/kits/i18n/include
${TARGET_DIR}/../../../base/global/i18n_lite/frameworks/i18n/include
${TARGET_DIR}/frameworks/include/base
${TARGET_DIR}/frameworks/include/context
${TARGET_DIR}/frameworks/include/resource

${TARGET_DIR}/interfaces/inner_api/builtin/base
${TARGET_DIR}/interfaces/inner_api/builtin/async
${TARGET_DIR}/interfaces/inner_api/builtin/jsi
# ${TARGET_DIR}/interfaces/inner_api/builtin

${TARGET_DIR}/test/moduletest/common
${TARGET_DIR}/frameworks/common/utils
${TARGET_DIR}/frameworks/common/log
${TARGET_DIR}/frameworks/common/memory
${TARGET_DIR}/frameworks/src/core
${TARGET_DIR}/frameworks/src/core/base
${TARGET_DIR}/frameworks/src/core/router
${TARGET_DIR}/frameworks/src/core/context
${TARGET_DIR}/frameworks/src/core/components
${TARGET_DIR}/frameworks/src/core/modules
${TARGET_DIR}/frameworks/src/core/animation
${TARGET_DIR}/frameworks/src/core/directive
${TARGET_DIR}/frameworks/targets/liteos_m
${TARGET_DIR}/frameworks/targets
${TARGET_DIR}/frameworks/module_manager
${TARGET_DIR}/frameworks/native_engine/jsi
${TARGET_DIR}/frameworks/native_engine

)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
    REQUIRES ui_lite jerryscript json ability_lite porting 
)

target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-missing-field-initializers)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unknown-pragmas)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-copy)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-enum-enum-conversion)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-enum-float-conversion)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-write-strings)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-format)


target_compile_definitions(${COMPONENT_LIB} PUBLIC 
FEATURE_ACELITE_HI_LOG_PRINTF=0
FEATURE_ACELITE_MC_LOG_PRINTF=0
ENABLE_OHOS_ACELITE_PRODUCT_CONFIG=1
JS_ENGINE_EXTERNAL_CONTEXT=1
)

target_compile_definitions(${COMPONENT_LIB} PRIVATE 
FEATURE_INTL_MODULE=0
FEATURE_NUMBER_FORMAT=0
FEATURE_DATE_FORMAT=0
FEATURE_SYSCAP_MODULE=0
FEATURE_ACELITE_DFX_MODULE=0
SCREENSIZE_SPECIFIED=1
)
