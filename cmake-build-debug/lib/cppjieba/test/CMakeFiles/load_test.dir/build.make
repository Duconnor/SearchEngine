# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/duyx/CLionProjects/SearchEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug

# Include any dependencies generated for this target.
include lib/cppjieba/test/CMakeFiles/load_test.dir/depend.make

# Include the progress variables for this target.
include lib/cppjieba/test/CMakeFiles/load_test.dir/progress.make

# Include the compile flags for this target's objects.
include lib/cppjieba/test/CMakeFiles/load_test.dir/flags.make

lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o: lib/cppjieba/test/CMakeFiles/load_test.dir/flags.make
lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o: ../lib/cppjieba/test/load_test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o"
	cd /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/lib/cppjieba/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/load_test.dir/load_test.cpp.o -c /Users/duyx/CLionProjects/SearchEngine/lib/cppjieba/test/load_test.cpp

lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/load_test.dir/load_test.cpp.i"
	cd /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/lib/cppjieba/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duyx/CLionProjects/SearchEngine/lib/cppjieba/test/load_test.cpp > CMakeFiles/load_test.dir/load_test.cpp.i

lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/load_test.dir/load_test.cpp.s"
	cd /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/lib/cppjieba/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duyx/CLionProjects/SearchEngine/lib/cppjieba/test/load_test.cpp -o CMakeFiles/load_test.dir/load_test.cpp.s

lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.requires:

.PHONY : lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.requires

lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.provides: lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.requires
	$(MAKE) -f lib/cppjieba/test/CMakeFiles/load_test.dir/build.make lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.provides.build
.PHONY : lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.provides

lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.provides.build: lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o


# Object files for target load_test
load_test_OBJECTS = \
"CMakeFiles/load_test.dir/load_test.cpp.o"

# External object files for target load_test
load_test_EXTERNAL_OBJECTS =

lib/cppjieba/load_test: lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o
lib/cppjieba/load_test: lib/cppjieba/test/CMakeFiles/load_test.dir/build.make
lib/cppjieba/load_test: lib/cppjieba/test/CMakeFiles/load_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../load_test"
	cd /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/lib/cppjieba/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/load_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/cppjieba/test/CMakeFiles/load_test.dir/build: lib/cppjieba/load_test

.PHONY : lib/cppjieba/test/CMakeFiles/load_test.dir/build

lib/cppjieba/test/CMakeFiles/load_test.dir/requires: lib/cppjieba/test/CMakeFiles/load_test.dir/load_test.cpp.o.requires

.PHONY : lib/cppjieba/test/CMakeFiles/load_test.dir/requires

lib/cppjieba/test/CMakeFiles/load_test.dir/clean:
	cd /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/lib/cppjieba/test && $(CMAKE_COMMAND) -P CMakeFiles/load_test.dir/cmake_clean.cmake
.PHONY : lib/cppjieba/test/CMakeFiles/load_test.dir/clean

lib/cppjieba/test/CMakeFiles/load_test.dir/depend:
	cd /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/duyx/CLionProjects/SearchEngine /Users/duyx/CLionProjects/SearchEngine/lib/cppjieba/test /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/lib/cppjieba/test /Users/duyx/CLionProjects/SearchEngine/cmake-build-debug/lib/cppjieba/test/CMakeFiles/load_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/cppjieba/test/CMakeFiles/load_test.dir/depend
