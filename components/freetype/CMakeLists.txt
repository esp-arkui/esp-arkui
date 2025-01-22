

set(TARGET_DIR ${CMAKE_CURRENT_LIST_DIR}/../../../third_party/freetype/out/freetype)

set(SRCS 
"${TARGET_DIR}/src/autofit/autofit.c"
"${TARGET_DIR}/src/base/ftbase.c"
"${TARGET_DIR}/src/base/ftbbox.c"
"${TARGET_DIR}/src/base/ftbdf.c"
"${TARGET_DIR}/src/base/ftbitmap.c"
"${TARGET_DIR}/src/base/ftcid.c"
"${TARGET_DIR}/src/base/ftdebug.c"
"${TARGET_DIR}/src/base/ftfstype.c"
"${TARGET_DIR}/src/base/ftgasp.c"
"${TARGET_DIR}/src/base/ftglyph.c"
"${TARGET_DIR}/src/base/ftgxval.c"
"${TARGET_DIR}/src/base/ftinit.c"
"${TARGET_DIR}/src/base/ftmm.c"
"${TARGET_DIR}/src/base/ftotval.c"
"${TARGET_DIR}/src/base/ftpatent.c"
"${TARGET_DIR}/src/base/ftpfr.c"
"${TARGET_DIR}/src/base/ftstroke.c"
"${TARGET_DIR}/src/base/ftsynth.c"
"${TARGET_DIR}/src/base/ftsystem.c"
"${TARGET_DIR}/src/base/fttype1.c"
"${TARGET_DIR}/src/base/ftwinfnt.c"
"${TARGET_DIR}/src/bdf/bdf.c"
"${TARGET_DIR}/src/cache/ftcache.c"
"${TARGET_DIR}/src/cff/cff.c"
"${TARGET_DIR}/src/cid/type1cid.c"
"${TARGET_DIR}/src/gzip/ftgzip.c"
"${TARGET_DIR}/src/lzw/ftlzw.c"
"${TARGET_DIR}/src/pcf/pcf.c"
"${TARGET_DIR}/src/pfr/pfr.c"
"${TARGET_DIR}/src/psaux/psaux.c"
"${TARGET_DIR}/src/pshinter/pshinter.c"
"${TARGET_DIR}/src/psnames/psmodule.c"
"${TARGET_DIR}/src/raster/raster.c"
"${TARGET_DIR}/src/sdf/ftbsdf.c"
"${TARGET_DIR}/src/sdf/ftsdf.c"
"${TARGET_DIR}/src/sdf/ftsdfcommon.c"
"${TARGET_DIR}/src/sdf/ftsdfrend.c"
"${TARGET_DIR}/src/sfnt/sfnt.c"
"${TARGET_DIR}/src/smooth/smooth.c"
"${TARGET_DIR}/src/svg/ftsvg.c"
"${TARGET_DIR}/src/truetype/truetype.c"
"${TARGET_DIR}/src/type1/type1.c"
"${TARGET_DIR}/src/type42/type42.c"
"${TARGET_DIR}/src/winfonts/winfnt.c"

)

set(INCLUDE_DIRS 
${TARGET_DIR}/include
${TARGET_DIR}/src/base

)


idf_component_register(
    SRCS ${SRCS}
    INCLUDE_DIRS ${INCLUDE_DIRS}
    REQUIRES zlib libpng
)

# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-unused-value)
# target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-comment)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-error=dangling-pointer)

target_compile_definitions(${COMPONENT_LIB} PRIVATE 
FT_CONFIG_OPTION_USE_PNG
FT_CONFIG_OPTION_SYSTEM_ZLIB
FT2_BUILD_LIBRARY
)
