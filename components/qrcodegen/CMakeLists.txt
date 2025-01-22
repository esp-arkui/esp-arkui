

set(TARGET_DIR ${ARKUILIB_DIR}/third_party/qrcodegen)

set(SRCS 
${TARGET_DIR}/cpp/qrcodegen.cpp
)

set(INCLUDE_DIRS 
${TARGET_DIR}/cpp
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
)

target_compile_options(${COMPONENT_LIB} PRIVATE -fexceptions)