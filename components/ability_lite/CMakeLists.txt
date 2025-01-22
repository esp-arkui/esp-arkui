

set(TARGET_DIR ${ARKUILIB_DIR}/foundation/ability/ability_lite)

set(SRCS 

${TARGET_DIR}/services/abilitymgr_lite/src/slite/ability_list.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/ability_mgr_service_slite.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/ability_record.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/ability_record_manager.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/ability_record_observer_manager.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/ability_thread.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/ability_thread_loader.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/bms_helper.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/js_ability_thread.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/native_ability_thread.cpp
${TARGET_DIR}/services/abilitymgr_lite/src/slite/slite_ability_loader.cpp

${TARGET_DIR}/frameworks/want_lite/src/want.cpp

${TARGET_DIR}/frameworks/abilitymgr_lite/src/slite/ability_manager_client.cpp
${TARGET_DIR}/frameworks/abilitymgr_lite/src/slite/ability_manager.cpp
${TARGET_DIR}/frameworks/abilitymgr_lite/src/slite/ability_manager_client.cpp
${TARGET_DIR}/frameworks/abilitymgr_lite/src/slite/ability_manager_inner.cpp
${TARGET_DIR}/frameworks/abilitymgr_lite/src/slite/ability_record_state_data.cpp
${TARGET_DIR}/frameworks/abilitymgr_lite/src/slite/abilityms_slite_client.cpp
${TARGET_DIR}/frameworks/abilitymgr_lite/src/slite/mission_info.cpp

${TARGET_DIR}/frameworks/ability_lite/src/slite/ability_saved_data.cpp
${TARGET_DIR}/frameworks/ability_lite/src/slite/lite_context.cpp
${TARGET_DIR}/frameworks/ability_lite/src/slite/slite_ability.cpp

${TARGET_DIR}/../../../base/global/resource_management_lite/frameworks/resmgr_lite/src/global.c
${TARGET_DIR}/../../../base/global/resource_management_lite/frameworks/resmgr_lite/src/global_utils.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/source/samgr_lite.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/source/common.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/source/feature.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/source/iunknown.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/source/message.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/source/service.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/source/task_manager.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/registry/service_registry.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/adapter/esp-idf/memory_adapter.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/adapter/esp-idf/queue_adapter.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/adapter/esp-idf/thread_adapter.c
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/adapter/esp-idf/time_adapter.c

)

set(INCLUDE_DIRS 
${TARGET_DIR}/../../../commonlibrary/utils_lite/timer_task/include
${TARGET_DIR}/../../../base/global/resource_management_lite/frameworks/resmgr_lite/include
${TARGET_DIR}/../../../base/global/resource_management_lite/interfaces/inner_api/include
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/frameworks/bundle_lite/include
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/interfaces/kits/bundle_lite
${TARGET_DIR}/../../../foundation/bundlemanager/bundle_framework_lite/utils/bundle_lite
${TARGET_DIR}/../../../commonlibrary/utils_lite/include
${TARGET_DIR}/services/abilitymgr_lite/include/util
${TARGET_DIR}/services/abilitymgr_lite/include/slite
${TARGET_DIR}/frameworks/ability_lite/include
${TARGET_DIR}/frameworks/abilitymgr_lite/include
${TARGET_DIR}/frameworks/abilitymgr_lite/include/slite
${TARGET_DIR}/interfaces/kits/ability_lite/slite
${TARGET_DIR}/interfaces/kits/ability_lite
${TARGET_DIR}/interfaces/kits/want_lite
${TARGET_DIR}/frameworks/want_lite/include
${TARGET_DIR}/interfaces/inner_api/abilitymgr_lite
${TARGET_DIR}/interfaces/inner_api/abilitymgr_lite/slite


${TARGET_DIR}/../../arkui/ace_engine_lite/interfaces/inner_api/builtin/async
${TARGET_DIR}/../../arkui/ace_engine_lite/frameworks/include/context
${TARGET_DIR}/../../arkui/ace_engine_lite/frameworks/src/core/context
${TARGET_DIR}/../../arkui/ace_engine_lite/interfaces/inner_api/builtin/jsi
${TARGET_DIR}/../../arkui/ace_engine_lite/frameworks/include/base
${TARGET_DIR}/../../arkui/ace_engine_lite/interfaces/inner_api/builtin/base
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/interfaces/kits/samgr
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/interfaces/kits/registry
# /home/zhouli/work/ark_simulator/foundation/bundlemanager/bundle_framework_lite/utils/bundle_lite/utils_list.h
# /home/zhouli/work/ark_simulator/commonlibrary/utils_lite/include/utils_list.h
${TARGET_DIR}/../../../commonlibrary/utils_lite/memory/include
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/adapter
${TARGET_DIR}/../../../foundation/systemabilitymgr/samgr_lite/samgr/registry
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
    REQUIRES bounds_checking_function porting
)

# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-missing-field-initializers)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unknown-pragmas)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-copy)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-enum-enum-conversion)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-enum-float-conversion)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-write-strings)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-format)

target_compile_definitions(${COMPONENT_LIB} PRIVATE 
__LITEOS_M__
ABILITY_LIST_CAPACITY=10
TASK_STACK_SIZE=30*1024
NATIVE_TASK_STACK_SIZE=30*1024
AMS_TASK_STACK_SIZE=20*1024
SHARED_TASK_STACK_SIZE=4096

)
