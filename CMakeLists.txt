cmake_minimum_required(VERSION 3.15)
project(HelloFFmpeg)

# C++ Standard configuration
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Conan configuration
find_package(ffmpeg REQUIRED)
find_package(AWSSDK REQUIRED COMPONENTS s3)
find_package(Protobuf REQUIRED)

# Define executable
add_executable(hello_ffmpeg src/main.cpp)

# Link with FFMPEG, AWS SDK, and Protobuf
target_link_libraries(hello_ffmpeg ffmpeg::ffmpeg AWS::aws-sdk-cpp-core AWS::aws-sdk-cpp-s3 protobuf::libprotobuf)
