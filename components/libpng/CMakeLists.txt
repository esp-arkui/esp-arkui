

set(TARGET_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../third_party/libpng/libpng-1.6.38)

set(SRCS 
${TARGET_DIR}/png.c
${TARGET_DIR}/pngerror.c
${TARGET_DIR}/pngget.c
${TARGET_DIR}/pngmem.c
${TARGET_DIR}/pngpread.c
${TARGET_DIR}/pngread.c
${TARGET_DIR}/pngrio.c
${TARGET_DIR}/pngrtran.c
${TARGET_DIR}/pngrutil.c
${TARGET_DIR}/pngset.c
${TARGET_DIR}/pngtrans.c
${TARGET_DIR}/pngwio.c
${TARGET_DIR}/pngwrite.c
${TARGET_DIR}/pngwtran.c
${TARGET_DIR}/pngwutil.c
)

set(INCLUDE_DIRS 
${TARGET_DIR}
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
    REQUIRES zlib
)

target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-error=maybe-uninitialized)

