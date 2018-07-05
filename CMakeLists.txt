PROJECT(CPPJIEBA)

CMAKE_MINIMUM_REQUIRED (VERSION 2.6)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/deps
        ${PROJECT_SOURCE_DIR}/include)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "/usr/local/cppjieba" CACHE PATH "default install path" FORCE )
endif()

ADD_DEFINITIONS(-O3 -Wall -g)
IF(APPLE) # mac os
    ADD_DEFINITIONS(-std=c++0x)
endif()

add_compile_options(-std=c++11)

# cmake .. -DENC=GBK
# IF (DEFINED ENC)
#     ADD_DEFINITIONS(-DCPPJIEBA_${ENC})
# ENDIF()

ADD_SUBDIRECTORY(deps)

ENABLE_TESTING()
ADD_TEST(NAME ./test/test.run COMMAND ./test/test.run)
ADD_TEST(NAME ./load_test COMMAND ./load_test)
ADD_TEST(NAME ./demo COMMAND ./demo)

add_executable(SearchEngine main.cpp invertedlist.h invertedlist.cpp searchengine.h searchengine.cpp)
