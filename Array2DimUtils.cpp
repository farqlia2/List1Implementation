//
// Created by Lenovo on 16.10.2022.
//

#include "Array2DimUtils.h"

// z ** do tej funkcji przekazana by była kopia wskaźnika,
// i do tej kopii zostałby przypisany adres początku tablicy dwuwymiarowej
// jednak po zdjęciu tego wywołania ze stosu ta kopia zostaje usunięta,
// a oryginalny wskaznik w main ma wciąż przypisane jakieś śmieci
bool Array2DimUtils::allocate2DimArray(int*** array2Dim, int rows, int cols) {

    bool canBeAllocated = is2DimArraySizeValid(rows, cols);
    if (canBeAllocated) {
        (*array2Dim) = new int* [rows];
        if (DEBUG) std::cout << "array2Dim = " << array2Dim << "\n";
        for (int i = 0; i < rows; i++) {
            (*array2Dim)[i] = new int[cols];
            if (DEBUG) std::cout << "array2Dim[" << i << "] = " << array2Dim[i] << "\n";
        }
    }
    return canBeAllocated;
}

void Array2DimUtils::fill2DimArray(int** array2Dim, int rows, int cols,
                                   int fillValue){
    for (int i = 0; i < rows; i++){
        ArrayUtils::fillArray(array2Dim[i], cols, fillValue);
    }
}

void Array2DimUtils::print2DimArray(int** array2Dim, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        ArrayUtils::printIntArray(array2Dim[i], cols);
        std::cout << "\n";
    }
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