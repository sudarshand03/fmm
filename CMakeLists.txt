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

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Gather all source files
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Create the main executable
add_executable(FMMProject ${SOURCES})

# ----------------------------------------------------------------------------
# Add Tests Automatically
# ----------------------------------------------------------------------------
# Find all test files in the `tests/` folder
file(GLOB TEST_FILES "${PROJECT_SOURCE_DIR}/tests/*.cpp")

# Loop through all test files and create separate executables
foreach(TEST_FILE ${TEST_FILES})
    # Extract the file name without extension
    get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)

    # Add an executable for each test
    add_executable(${TEST_NAME} ${TEST_FILE})

    # Print message to confirm test is added
    message(STATUS "Added test: ${TEST_NAME}")
endforeach()

# install(TARGETS FMMProject RUNTIME DESTINATION bin)

message(STATUS "Configuration complete. Build type: ${CMAKE_BUILD_TYPE}")
