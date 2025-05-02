cmake_minimum_required(VERSION 3.10)
project(PureHook VERSION 1.0.0 LANGUAGES C CXX)

# Use C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(PUREHOOK_SOURCES
    src/PureHook.cpp
    src/Trampoline.cpp
    src/HookManager.cpp
    include/PureHook.h
    include/Trampoline.h
    include/HookManager.h
)

# Create the PureHook library
add_library(PureHook STATIC ${PUREHOOK_SOURCES})
target_include_directories(PureHook PUBLIC include)

# Optional: Add an example target if you have one
option(BUILD_EXAMPLE "Build example usage program" ON)

if(BUILD_EXAMPLE)
    add_executable(PureHookExample example/main.cpp)
    target_link_libraries(PureHookExample PRIVATE PureHook)
endif()
