//
// Created by Lenovo on 16.10.2022.
//

#include "Array2DimUtils.h"

bool Array2DimUtils::allocate2DimArray(int**& array2Dim, int rows, int cols) {

    bool canBeAllocated = isArray2DimSizeValid(rows, cols);
    if (canBeAllocated) {
        array2Dim = new int* [rows];
        if (DEBUG) std::cout << "array2Dim = " << array2Dim << "\n";
        for (int i = 0; i < rows; i++) {
            array2Dim[i] = new int[cols];
            if (DEBUG) std::cout << "array2Dim[" << i << "] = " << array2Dim[i] << "\n";
        }

    }
    return canBeAllocated;
}

void Array2DimUtils::print2DimArray(int** array2Dim, int rows, int cols) {

    for (int i = 0; i < rows; i++) {
        ArrayUtils::printIntArray(array2Dim[i], cols);
        std::cout << "\n";
    }

}

bool Array2DimUtils::deallocate2DimArray(int**& array2Dim, int rows) {

    bool canBeDeallocated = array2Dim != NULL;
    if (canBeDeallocated) {
        for (int i = 0; i < rows; i++) {
            delete[] array2Dim[i];
        }
        delete[] array2Dim;
    }
    array2Dim = NULL;
    return canBeDeallocated;
}

bool Array2DimUtils::isArray2DimSizeValid(int rows, int cols) {
    return (rows > 0 && cols > 0);
}