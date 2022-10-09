cmake_minimum_required(VERSION 3.12)
project("problems")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -O3")
add_subdirectory("luogu")
#add_subdirectory("leetcode")

set(SUBFOLDER "leetcode")
file(GLOB NOTES ${SUBFOLDER}/*.cpp)
foreach(FILEPATH ${NOTES} )
    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" BASENAME ${FILEPATH})
    add_executable(${BASENAME} ${FILEPATH})
endforeach( )
include_directories(
    /usr/local/include/opencv4
)
find_library(LZ4_LIBRARIES NAMES liblz4.dylib HINTS "lz4/lib")
find_package(FLANN REQUIRED)
find_package(PCL REQUIRED)
find_package(OpenCV REQUIRED)
add_executable(main main.cpp)

target_link_libraries(main  ${OpenCV_LIBRARIES}  ${PCL_LIBRARIES} )