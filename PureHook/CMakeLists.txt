# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Set the project name
project(PureHook VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define include directories
include_directories(${PROJECT_SOURCE_DIR})

# Add the source files
add_library(PureHook STATIC
    PureHook.cpp
    Trampoline.cpp
    MemoryUtils.cpp
)

# Optional: If you're creating an executable for testing purposes
# add_executable(ExampleExample main.cpp)
# target_link_libraries(ExampleExample PureHook)

# Optionally set the installation path
install(TARGETS PureHook DESTINATION lib)
install(FILES PureHook.h DESTINATION include)
