cmake_minimum_required(VERSION 3.23)
project(List1Implementation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(List1Implementation
        Array2DimUtils.cpp
        Array2DimUtils.h
        ArrayUtils.cpp
        ArrayUtils.h
        Constants.h
        CTable.cpp
        CTable.h
        Global.h
        Source.cpp UserInterface.cpp UserInterface.h
        Array3DimUtils.cpp Array3DimUtils.h)
