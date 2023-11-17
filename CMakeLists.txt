cmake_minimum_required(VERSION 3.23)
project(Open23)

set(CMAKE_CXX_STANDARD 23)

set(ENV{OPENCV_DIR} "C:\\tools\\opencv\\build")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(openf main.cpp)
set(OpenCV_LIBS opencv_core opencv_imgproc opencv_highgui opencv_imgcodecs)
target_link_libraries(openf ${OpenCV_LIBS})