# CMake generated Testfile for 
# Source directory: /Users/duyx/ClionProjects/SearchEngine
# Build directory: /Users/duyx/ClionProjects/SearchEngine/cmake-build-debug
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(./test/test.run "./test/test.run")
add_test(./load_test "./load_test")
add_test(./demo "./demo")
subdirs("deps")
