cmake_minimum_required(VERSION 2.8)

project(librevpi_test)

add_subdirectory(external/librevpi)

add_executable(librevpi_test main.c )

target_include_directories(librevpi PUBLIC external/librevpi/include)

target_link_libraries(librevpi_test librevpi)

install(TARGETS librevpi_test DESTINATION bin)
