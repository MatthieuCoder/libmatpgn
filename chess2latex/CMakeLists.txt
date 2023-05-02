add_executable(chess2latex main.c)
target_include_directories(chess2latex PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
target_link_libraries(chess2latex libparse)