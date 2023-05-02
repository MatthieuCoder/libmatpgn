add_library(libgame game.c round.c round.c san.c)
target_link_libraries(libgame libmem)
target_include_directories(libgame PRIVATE ${CMAKE_SOURCE_DIR} ${CMAKE_BINARY_DIR})
