cmake_minimum_required(VERSION 3.21)
project(OpenCvFukSakeWork)

set(CMAKE_CXX_STANDARD 14)


add_executable(OpenCvFukSakeWork
        Chapter1.hpp
        Chapter2.hpp
        Chapter3.hpp
        Chapter4.hpp
        Chapter5.hpp
        Chapter6.hpp
        Chapter7.hpp
        Chapter8.hpp
        Source.cpp
        utils.hpp
        VirtualPainter.hpp)

# OPENCV
# Find Package
set(OpenCV_DIR "C:/opencv/build")
option(OpenCV_STATIC OFF)
find_package(OpenCV REQUIRED)

# Set Static Link Runtime Library
if (OpenCV_STATIC)
    foreach (flag_var
            CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO)
        if (${flag_var} MATCHES "/MD")
            string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
        endif ()
    endforeach ()
endif ()

if (OpenCV_FOUND)
    # Additional Include Directories
    include_directories(${OpenCV_INCLUDE_DIRS})

    # Additional Library Directories

    link_directories(${OpenCV_LIB_DIR})

    # Additional Dependencies
    target_link_libraries(project ${OpenCV_LIBS})
endif ()