cmake_minimum_required(VERSION 3.18.0)

project(Chess2LaTeX VERSION 1.0 LANGUAGES C)

add_subdirectory(libgame)
add_subdirectory(libmem)
add_subdirectory(libparse)
add_subdirectory(chess2latex)

add_subdirectory(packcc)
add_subdirectory(arena)
