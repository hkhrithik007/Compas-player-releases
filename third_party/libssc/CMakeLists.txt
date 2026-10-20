cmake_minimum_required(VERSION 3.16)
project(ssc_encoder VERSION 0.1.0 LANGUAGES C)

include(GNUInstallDirs)
find_package(Threads REQUIRED)

# The translation preserves ARM's integer wrap and eight-byte state slots.
# Disable alias-based optimizations because the recovered state is byte-addressed.
add_library(ssc_native OBJECT ssc_native.c)
target_compile_features(ssc_native PRIVATE c_std_11)
target_compile_options(ssc_native PRIVATE
    -O2 -fwrapv -fno-strict-aliasing -fvisibility=hidden
    -include "${CMAKE_CURRENT_SOURCE_DIR}/ssc_native_rename.h"
    -Werror=int-conversion -Werror=incompatible-pointer-types)
set_target_properties(ssc_native PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(ssc SHARED ssc_encoder_wrapper.c $<TARGET_OBJECTS:ssc_native>)
target_include_directories(ssc PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_link_libraries(ssc PRIVATE Threads::Threads)
target_compile_features(ssc PRIVATE c_std_11)
target_compile_options(ssc PRIVATE -Wall -Wextra -Werror -fvisibility=hidden)
set_target_properties(ssc PROPERTIES VERSION ${PROJECT_VERSION} SOVERSION 0)

configure_file(ssc.pc.in ssc.pc @ONLY)
install(TARGETS ssc LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(FILES ssc_encoder.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/ssc.pc" DESTINATION ${CMAKE_INSTALL_LIBDIR}/pkgconfig)
