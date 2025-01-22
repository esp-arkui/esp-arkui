

set(TARGET_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../third_party/zlib)

set(SRCS 
${TARGET_DIR}/adler32.c
${TARGET_DIR}/compress.c
${TARGET_DIR}/crc32.c
${TARGET_DIR}/deflate.c
${TARGET_DIR}/infback.c
${TARGET_DIR}/inffast.c
${TARGET_DIR}/inflate.c
${TARGET_DIR}/inftrees.c
${TARGET_DIR}/trees.c
${TARGET_DIR}/uncompr.c
${TARGET_DIR}/zutil.c
)

set(INCLUDE_DIRS 
${TARGET_DIR}
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
)

