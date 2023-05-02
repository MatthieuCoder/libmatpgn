add_library(libmem kv.c vector.c)
target_include_directories(libmem PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
