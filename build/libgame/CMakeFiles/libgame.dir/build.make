# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/matthieup/chess2latex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/matthieup/chess2latex/build

# Include any dependencies generated for this target.
include libgame/CMakeFiles/libgame.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libgame/CMakeFiles/libgame.dir/compiler_depend.make

# Include the progress variables for this target.
include libgame/CMakeFiles/libgame.dir/progress.make

# Include the compile flags for this target's objects.
include libgame/CMakeFiles/libgame.dir/flags.make

libgame/CMakeFiles/libgame.dir/game.c.o: libgame/CMakeFiles/libgame.dir/flags.make
libgame/CMakeFiles/libgame.dir/game.c.o: /home/matthieup/chess2latex/libgame/game.c
libgame/CMakeFiles/libgame.dir/game.c.o: libgame/CMakeFiles/libgame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthieup/chess2latex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libgame/CMakeFiles/libgame.dir/game.c.o"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libgame/CMakeFiles/libgame.dir/game.c.o -MF CMakeFiles/libgame.dir/game.c.o.d -o CMakeFiles/libgame.dir/game.c.o -c /home/matthieup/chess2latex/libgame/game.c

libgame/CMakeFiles/libgame.dir/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgame.dir/game.c.i"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matthieup/chess2latex/libgame/game.c > CMakeFiles/libgame.dir/game.c.i

libgame/CMakeFiles/libgame.dir/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgame.dir/game.c.s"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matthieup/chess2latex/libgame/game.c -o CMakeFiles/libgame.dir/game.c.s

libgame/CMakeFiles/libgame.dir/round.c.o: libgame/CMakeFiles/libgame.dir/flags.make
libgame/CMakeFiles/libgame.dir/round.c.o: /home/matthieup/chess2latex/libgame/round.c
libgame/CMakeFiles/libgame.dir/round.c.o: libgame/CMakeFiles/libgame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthieup/chess2latex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object libgame/CMakeFiles/libgame.dir/round.c.o"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libgame/CMakeFiles/libgame.dir/round.c.o -MF CMakeFiles/libgame.dir/round.c.o.d -o CMakeFiles/libgame.dir/round.c.o -c /home/matthieup/chess2latex/libgame/round.c

libgame/CMakeFiles/libgame.dir/round.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgame.dir/round.c.i"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matthieup/chess2latex/libgame/round.c > CMakeFiles/libgame.dir/round.c.i

libgame/CMakeFiles/libgame.dir/round.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgame.dir/round.c.s"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matthieup/chess2latex/libgame/round.c -o CMakeFiles/libgame.dir/round.c.s

libgame/CMakeFiles/libgame.dir/san.c.o: libgame/CMakeFiles/libgame.dir/flags.make
libgame/CMakeFiles/libgame.dir/san.c.o: /home/matthieup/chess2latex/libgame/san.c
libgame/CMakeFiles/libgame.dir/san.c.o: libgame/CMakeFiles/libgame.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/matthieup/chess2latex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object libgame/CMakeFiles/libgame.dir/san.c.o"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT libgame/CMakeFiles/libgame.dir/san.c.o -MF CMakeFiles/libgame.dir/san.c.o.d -o CMakeFiles/libgame.dir/san.c.o -c /home/matthieup/chess2latex/libgame/san.c

libgame/CMakeFiles/libgame.dir/san.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/libgame.dir/san.c.i"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/matthieup/chess2latex/libgame/san.c > CMakeFiles/libgame.dir/san.c.i

libgame/CMakeFiles/libgame.dir/san.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/libgame.dir/san.c.s"
	cd /home/matthieup/chess2latex/build/libgame && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/matthieup/chess2latex/libgame/san.c -o CMakeFiles/libgame.dir/san.c.s

# Object files for target libgame
libgame_OBJECTS = \
"CMakeFiles/libgame.dir/game.c.o" \
"CMakeFiles/libgame.dir/round.c.o" \
"CMakeFiles/libgame.dir/san.c.o"

# External object files for target libgame
libgame_EXTERNAL_OBJECTS =

libgame/liblibgame.a: libgame/CMakeFiles/libgame.dir/game.c.o
libgame/liblibgame.a: libgame/CMakeFiles/libgame.dir/round.c.o
libgame/liblibgame.a: libgame/CMakeFiles/libgame.dir/san.c.o
libgame/liblibgame.a: libgame/CMakeFiles/libgame.dir/build.make
libgame/liblibgame.a: libgame/CMakeFiles/libgame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/matthieup/chess2latex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library liblibgame.a"
	cd /home/matthieup/chess2latex/build/libgame && $(CMAKE_COMMAND) -P CMakeFiles/libgame.dir/cmake_clean_target.cmake
	cd /home/matthieup/chess2latex/build/libgame && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libgame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libgame/CMakeFiles/libgame.dir/build: libgame/liblibgame.a
.PHONY : libgame/CMakeFiles/libgame.dir/build

libgame/CMakeFiles/libgame.dir/clean:
	cd /home/matthieup/chess2latex/build/libgame && $(CMAKE_COMMAND) -P CMakeFiles/libgame.dir/cmake_clean.cmake
.PHONY : libgame/CMakeFiles/libgame.dir/clean

libgame/CMakeFiles/libgame.dir/depend:
	cd /home/matthieup/chess2latex/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/matthieup/chess2latex /home/matthieup/chess2latex/libgame /home/matthieup/chess2latex/build /home/matthieup/chess2latex/build/libgame /home/matthieup/chess2latex/build/libgame/CMakeFiles/libgame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libgame/CMakeFiles/libgame.dir/depend

