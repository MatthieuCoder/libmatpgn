
add_custom_command(
    OUTPUT parser.c parser.h
    COMMAND ${CMAKE_BINARY_DIR}/packcc/packcc ARGS -o parser ${CMAKE_CURRENT_SOURCE_DIR}/parser.peg
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/parser.peg
    VERBATIM

    DEPENDS ${CMAKE_BINARY_DIR}/packcc/packcc
)

add_library(libparse system.c parser.c)
target_include_directories(libparse BEFORE PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
target_include_directories(libparse PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
target_link_libraries(libparse libmem)
target_link_libraries(libparse libgame)