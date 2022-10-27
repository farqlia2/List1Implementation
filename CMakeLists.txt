cmake_minimum_required(VERSION 3.23)
project(List1Implementation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(List1Implementation
        Constants.h
        CTable.cpp
        CTable.h
        Source.cpp
        ArrayUtils.cpp ArrayUtils.h Array2DimUtils.cpp Array2DimUtils.h Global.h Array3DimUtils.cpp Array3DimUtils.h
        Shareable.h Shareable.cpp)
