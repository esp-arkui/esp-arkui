

set(TARGET_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../third_party/bounds_checking_function)

set(SRCS 
"${TARGET_DIR}/src/fscanf_s.c"
"${TARGET_DIR}/src/fwscanf_s.c"
"${TARGET_DIR}/src/gets_s.c"
"${TARGET_DIR}/src/memcpy_s.c"
"${TARGET_DIR}/src/memmove_s.c"
"${TARGET_DIR}/src/memset_s.c"
"${TARGET_DIR}/src/scanf_s.c"
"${TARGET_DIR}/src/securecutil.c"
"${TARGET_DIR}/src/secureinput_a.c"
"${TARGET_DIR}/src/secureinput_w.c"
"${TARGET_DIR}/src/secureprintoutput_a.c"
"${TARGET_DIR}/src/secureprintoutput_w.c"
"${TARGET_DIR}/src/snprintf_s.c"
"${TARGET_DIR}/src/sprintf_s.c"
"${TARGET_DIR}/src/sscanf_s.c"
"${TARGET_DIR}/src/strcat_s.c"
"${TARGET_DIR}/src/strcpy_s.c"
"${TARGET_DIR}/src/strncat_s.c"
"${TARGET_DIR}/src/strncpy_s.c"
"${TARGET_DIR}/src/strtok_s.c"
"${TARGET_DIR}/src/swprintf_s.c"
"${TARGET_DIR}/src/swscanf_s.c"
"${TARGET_DIR}/src/vfscanf_s.c"
"${TARGET_DIR}/src/vfwscanf_s.c"
"${TARGET_DIR}/src/vscanf_s.c"
"${TARGET_DIR}/src/vsnprintf_s.c"
"${TARGET_DIR}/src/vsprintf_s.c"
"${TARGET_DIR}/src/vsscanf_s.c"
"${TARGET_DIR}/src/vswprintf_s.c"
"${TARGET_DIR}/src/vswscanf_s.c"
"${TARGET_DIR}/src/vwscanf_s.c"
"${TARGET_DIR}/src/wcscat_s.c"
"${TARGET_DIR}/src/wcscpy_s.c"
"${TARGET_DIR}/src/wcsncat_s.c"
"${TARGET_DIR}/src/wcsncpy_s.c"
"${TARGET_DIR}/src/wcstok_s.c"
"${TARGET_DIR}/src/wmemcpy_s.c"
"${TARGET_DIR}/src/wmemmove_s.c"
"${TARGET_DIR}/src/wscanf_s.c"
)

set(INCLUDE_DIRS 
${TARGET_DIR}/include
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
)

# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unused-value)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-comment)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-parentheses)

target_compile_definitions(${COMPONENT_LIB} PUBLIC 
_INC_STRING_S
_INC_WCHAR_S
_SECIMP=//
_STDIO_S_DEFINED
_INC_STDIO_S
_INC_STDLIB_S
_INC_MEMORY_S
)
