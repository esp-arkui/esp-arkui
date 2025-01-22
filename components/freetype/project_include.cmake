
#Get Python
idf_build_get_property(python PYTHON)

message(STATUS "Install freetype")

set(LIB_DIR ${ARKUILIB_DIR}/third_party/freetype)
execute_process(COMMAND mkdir -p ${LIB_DIR}/out/freetype OUTPUT_QUIET)
execute_process(COMMAND ${python} ${LIB_DIR}/install.py --source-dir ${LIB_DIR}/ --gen-dir ${LIB_DIR}/out OUTPUT_QUIET)

