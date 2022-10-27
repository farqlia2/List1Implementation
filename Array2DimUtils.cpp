//
// Created by Lenovo on 16.10.2022.
//

#include "Array2DimUtils.h"

bool Array2DimUtils::allocate2DimArray(int*** array2Dim, int rows, int cols) {

    bool canBeAllocated = is2DimArraySizeValid(rows, cols);
    if (canBeAllocated) {
        (*array2Dim) = new int* [rows];
        for (int i = 0; i < rows; i++) {
            (*array2Dim)[i] = new int[cols];
        }
    }
    return canBeAllocated;
}

bool Array2DimUtils::deallocate2DimArray(int** array2Dim, int rows, int cols) {

    bool canBeDeallocated = is2DimArraySizeValid(rows, cols);
    if (canBeDeallocated) {
        for (int i = 0; i < rows; i++) {
            delete[] array2Dim[i];
        }
        delete[] array2Dim;
    }
    return canBeDeallocated;
}

bool Array2DimUtils::is2DimArraySizeValid(int rows, int cols) {
    return (rows > 0 && cols > 0);
}