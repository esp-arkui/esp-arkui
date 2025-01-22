
#Get Python
idf_build_get_property(python PYTHON)

message(STATUS "Install libpng")

set(LIB_DIR ${ARKUILIB_DIR}/third_party/libpng)
execute_process(COMMAND ${python} ${LIB_DIR}/install.py --source-dir ${LIB_DIR} --gen-dir ${LIB_DIR} OUTPUT_QUIET)

