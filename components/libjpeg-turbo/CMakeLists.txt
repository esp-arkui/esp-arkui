

set(TARGET_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../third_party/libjpeg-turbo/libjpeg-turbo-2.1.1)

set(SRCS 
${TARGET_DIR}/jcapimin.c
${TARGET_DIR}/jcapistd.c
${TARGET_DIR}/jccoefct.c
${TARGET_DIR}/jccolor.c
${TARGET_DIR}/jcdctmgr.c
${TARGET_DIR}/jchuff.c
${TARGET_DIR}/jcicc.c
${TARGET_DIR}/jcinit.c
${TARGET_DIR}/jcmainct.c
${TARGET_DIR}/jcmarker.c
${TARGET_DIR}/jcmaster.c
${TARGET_DIR}/jcomapi.c
${TARGET_DIR}/jcparam.c
${TARGET_DIR}/jcphuff.c
${TARGET_DIR}/jcprepct.c
${TARGET_DIR}/jcsample.c
${TARGET_DIR}/jctrans.c
${TARGET_DIR}/jdapimin.c
${TARGET_DIR}/jdapistd.c
${TARGET_DIR}/jdatadst.c
${TARGET_DIR}/jdatasrc.c
${TARGET_DIR}/jdcoefct.c
${TARGET_DIR}/jdcolor.c
${TARGET_DIR}/jddctmgr.c
${TARGET_DIR}/jdhuff.c
${TARGET_DIR}/jdicc.c
${TARGET_DIR}/jdinput.c
${TARGET_DIR}/jdmainct.c
${TARGET_DIR}/jdmarker.c
${TARGET_DIR}/jdmaster.c
${TARGET_DIR}/jdmerge.c
${TARGET_DIR}/jdphuff.c
${TARGET_DIR}/jdpostct.c
${TARGET_DIR}/jdsample.c
${TARGET_DIR}/jdtrans.c
${TARGET_DIR}/jerror.c
${TARGET_DIR}/jfdctflt.c
${TARGET_DIR}/jfdctfst.c
${TARGET_DIR}/jfdctint.c
${TARGET_DIR}/jidctflt.c
${TARGET_DIR}/jidctfst.c
${TARGET_DIR}/jidctint.c
${TARGET_DIR}/jidctred.c
${TARGET_DIR}/jmemmgr.c
${TARGET_DIR}/jmemnobs.c
${TARGET_DIR}/jquant1.c
${TARGET_DIR}/jquant2.c
${TARGET_DIR}/jutils.c
${TARGET_DIR}/jsimd_none.c
)

set(INCLUDE_DIRS 
${TARGET_DIR}
)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
)

