cmake_minimum_required(VERSION 3.10)
project(FMMProject VERSION 1.0 LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally enable OpenMP if available
find_package(OpenMP)
if(OPENMP_FOUND)
    message(STATUS "OpenMP found; enabling OpenMP flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
else()
    message(WARNING "OpenMP not found. Continuing without OpenMP support.")
endif()

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(FMMProject ${SOURCES})

add_executable(testvec tests/testvec.cpp)


install(TARGETS FMMProject RUNTIME DESTINATION bin)

message(STATUS "Configuration complete. Build type: ${CMAKE_BUILD_TYPE}")
