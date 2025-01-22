

set(SRCS 
kal/kal.c
log.c
js-port/jerry_console.c
js-port/jerry_util.c
)

set(INCLUDE_DIRS 
.
kal
js-port
# /home/zhouli/work/ark_simulator/third_party/jerryscript/jerry-ext/include
# /home/zhouli/work/ark_simulator/third_party/jerryscript/jerry-core/include
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}

    PRIV_REQUIRES jerryscript
)

target_compile_definitions(${COMPONENT_LIB} PUBLIC 

HILOG_MODULE_APP="app"
HILOG_MODULE_SAMGR="samgr"
HILOG_MODULE_AAFWK="aafwk"
HILOG_MODULE_ACE="ace"
)
