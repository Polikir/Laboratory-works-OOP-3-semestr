# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kirillgolubev/CLionProjects/sem_3_laba2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kirillgolubev/CLionProjects/sem_3_laba2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TOMOKA.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/TOMOKA.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TOMOKA.dir/flags.make

CMakeFiles/TOMOKA.dir/main.cpp.o: CMakeFiles/TOMOKA.dir/flags.make
CMakeFiles/TOMOKA.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kirillgolubev/CLionProjects/sem_3_laba2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TOMOKA.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TOMOKA.dir/main.cpp.o -c /Users/kirillgolubev/CLionProjects/sem_3_laba2/main.cpp

CMakeFiles/TOMOKA.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TOMOKA.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kirillgolubev/CLionProjects/sem_3_laba2/main.cpp > CMakeFiles/TOMOKA.dir/main.cpp.i

CMakeFiles/TOMOKA.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TOMOKA.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kirillgolubev/CLionProjects/sem_3_laba2/main.cpp -o CMakeFiles/TOMOKA.dir/main.cpp.s

# Object files for target TOMOKA
TOMOKA_OBJECTS = \
"CMakeFiles/TOMOKA.dir/main.cpp.o"

# External object files for target TOMOKA
TOMOKA_EXTERNAL_OBJECTS =

TOMOKA: CMakeFiles/TOMOKA.dir/main.cpp.o
TOMOKA: CMakeFiles/TOMOKA.dir/build.make
TOMOKA: /opt/homebrew/lib/libsfml-graphics.2.5.1.dylib
TOMOKA: /opt/homebrew/lib/libsfml-audio.2.5.1.dylib
TOMOKA: /opt/homebrew/lib/libsfml-network.2.5.1.dylib
TOMOKA: /opt/homebrew/lib/libsfml-window.2.5.1.dylib
TOMOKA: /opt/homebrew/lib/libsfml-system.2.5.1.dylib
TOMOKA: CMakeFiles/TOMOKA.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kirillgolubev/CLionProjects/sem_3_laba2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TOMOKA"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TOMOKA.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TOMOKA.dir/build: TOMOKA
.PHONY : CMakeFiles/TOMOKA.dir/build

CMakeFiles/TOMOKA.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TOMOKA.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TOMOKA.dir/clean

CMakeFiles/TOMOKA.dir/depend:
	cd /Users/kirillgolubev/CLionProjects/sem_3_laba2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kirillgolubev/CLionProjects/sem_3_laba2 /Users/kirillgolubev/CLionProjects/sem_3_laba2 /Users/kirillgolubev/CLionProjects/sem_3_laba2/cmake-build-debug /Users/kirillgolubev/CLionProjects/sem_3_laba2/cmake-build-debug /Users/kirillgolubev/CLionProjects/sem_3_laba2/cmake-build-debug/CMakeFiles/TOMOKA.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TOMOKA.dir/depend

