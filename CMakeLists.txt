cmake_minimum_required(VERSION 3.1.3)
project(matmat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_library(matmat matmat.cpp)

add_executable(matmat_exe main.cpp)
target_link_libraries(matmat_exe matmat)

# find_package(OpenMP)
# add_executable(dynamicsystems main.cpp)
# if(OPENMP_FOUND)
#   #target_compile_options(dynamicsystems PRIVATE ${OpenMP_CXX_FLAGS})
#   set(CMAKE_CXX_FLAGS ${OpenMP_CXX_FLAGS})
# endif()

# if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
#   target_compile_options(dynamicsystems PRIVATE "-std=c++11" "-qopt-report=5" "-qopt-report-phase=vec")
# endif()
