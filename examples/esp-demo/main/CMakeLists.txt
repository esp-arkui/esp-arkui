
file(GLOB_RECURSE c_srcs "./*.c")
file(GLOB_RECURSE cpp_srcs "./*.cpp")


idf_component_register(
    SRCS ${c_srcs} ${cpp_srcs}
    INCLUDE_DIRS . ui_port)


target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-format -Wno-error=unknown-pragmas)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-deprecated-enum-float-conversion)


# Note: you must have a partition named the first argument (here it's "littlefs")
# in your partition table csv file.
if(NOT CMAKE_HOST_SYSTEM_NAME STREQUAL "Windows")
fatfs_create_spiflash_image(storage "../rootfs" FLASH_IN_PROJECT)
else()
    fail_at_build_time(littlefs "Windows does not support LittleFS partition generation")
endif()
