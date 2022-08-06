cmake_minimum_required(VERSION 3.0)
project (jester CXX)

set (CMAKE_CXX_STANDARD 17)

find_package(Java REQUIRED)
find_package(JNI REQUIRED)

include_directories(${JNI_INCLUDE_DIRS})

add_executable(jester src/jester.cpp)
target_link_libraries(jester ${JNI_LIBRARIES})