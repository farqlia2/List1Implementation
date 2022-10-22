//
// Created by Lenovo on 16.10.2022.
//

#ifndef LIST1IMPLEMENTATION_ARRAY2DIMUTILS_H
#define LIST1IMPLEMENTATION_ARRAY2DIMUTILS_H
#include "Global.h"
#include <iostream>
#include "ArrayUtils.h"

class Array2DimUtils {
public:
    static bool allocate2DimArray(int*** array2Dim, int rows, int cols);

    static void print2DimArray(int** array2Dim, int rows, int cols);

    static void fill2DimArray(int** array2Dim, int rows, int cols,
                              int fillValue);

    static bool deallocate2DimArray(int** array2Dim, int rows);

    static bool isArray2DimSizeValid(int rows, int cols);
};


#endif //LIST1IMPLEMENTATION_ARRAY2DIMUTILS_H
