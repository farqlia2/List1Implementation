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

    static bool deallocate2DimArray(int** array2Dim, int rows, int cols);

    static bool is2DimArraySizeValid(int rows, int cols);
};


#endif //LIST1IMPLEMENTATION_ARRAY2DIMUTILS_H
