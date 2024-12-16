cmake_minimum_required(VERSION 3.8)
project(vision-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_library(reader src/image_reader.cpp)

add_executable(main src/main.cpp src/image_reader.cpp)
target_include_directories(main PUBLIC reader)
target_link_libraries(main ${OpenCV_LIBS})