

set(TARGET_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../third_party/icu)

set(SRCS 
${TARGET_DIR}/icu4c/source/common/cmemory.cpp
${TARGET_DIR}/icu4c/source/common/cstring.cpp
${TARGET_DIR}/icu4c/source/common/ubidi.cpp
${TARGET_DIR}/icu4c/source/common/ubidi_props.cpp
${TARGET_DIR}/icu4c/source/common/ubidiln.cpp
${TARGET_DIR}/icu4c/source/common/ubidiwrt.cpp
${TARGET_DIR}/icu4c/source/common/uchar.cpp
${TARGET_DIR}/icu4c/source/common/udataswp.cpp
${TARGET_DIR}/icu4c/source/common/uinvchar.cpp
${TARGET_DIR}/icu4c/source/common/ustring.cpp
${TARGET_DIR}/icu4c/source/common/utf_impl.cpp
${TARGET_DIR}/icu4c/source/common/ucptrie.cpp
${TARGET_DIR}/icu4c/source/common/utrie2.cpp
)

set(INCLUDE_DIRS 
${TARGET_DIR}/icu4c/source/common
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
)

