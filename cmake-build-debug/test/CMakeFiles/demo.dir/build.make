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
CMAKE_SOURCE_DIR = /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug

# Include any dependencies generated for this target.
include test/CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/demo.dir/flags.make

test/CMakeFiles/demo.dir/demo.cpp.o: test/CMakeFiles/demo.dir/flags.make
test/CMakeFiles/demo.dir/demo.cpp.o: ../test/demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/demo.dir/demo.cpp.o"
	cd /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/demo.cpp.o -c /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/test/demo.cpp

test/CMakeFiles/demo.dir/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/demo.cpp.i"
	cd /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/test/demo.cpp > CMakeFiles/demo.dir/demo.cpp.i

test/CMakeFiles/demo.dir/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/demo.cpp.s"
	cd /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/test && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/test/demo.cpp -o CMakeFiles/demo.dir/demo.cpp.s

test/CMakeFiles/demo.dir/demo.cpp.o.requires:

.PHONY : test/CMakeFiles/demo.dir/demo.cpp.o.requires

test/CMakeFiles/demo.dir/demo.cpp.o.provides: test/CMakeFiles/demo.dir/demo.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/demo.dir/build.make test/CMakeFiles/demo.dir/demo.cpp.o.provides.build
.PHONY : test/CMakeFiles/demo.dir/demo.cpp.o.provides

test/CMakeFiles/demo.dir/demo.cpp.o.provides.build: test/CMakeFiles/demo.dir/demo.cpp.o


# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/demo.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: test/CMakeFiles/demo.dir/demo.cpp.o
demo: test/CMakeFiles/demo.dir/build.make
demo: test/CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../demo"
	cd /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/demo.dir/build: demo

.PHONY : test/CMakeFiles/demo.dir/build

test/CMakeFiles/demo.dir/requires: test/CMakeFiles/demo.dir/demo.cpp.o.requires

.PHONY : test/CMakeFiles/demo.dir/requires

test/CMakeFiles/demo.dir/clean:
	cd /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/test && $(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/demo.dir/clean

test/CMakeFiles/demo.dir/depend:
	cd /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/test /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/test /Users/duyx/CLionProjects/SearchEngineWithJieba/cppjieba/cmake-build-debug/test/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/demo.dir/depend

