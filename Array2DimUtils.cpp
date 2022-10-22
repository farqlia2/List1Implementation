//
// Created by Lenovo on 16.10.2022.
//

#include "Array2DimUtils.h"

// z ** do tej funkcji przekazana by była kopia wskaźnika,
// i do tej kopii zostałby przypisany adres początku tablicy dwuwymiarowej
// jednak po zdjęciu tego wywołania ze stosu ta kopia zostaje usunięta,
// a oryginalny wskaznik w main ma wciąż przypisane jakieś śmieci
bool Array2DimUtils::allocate2DimArray(int*** array2Dim, int rows, int cols) {

    bool canBeAllocated = isArray2DimSizeValid(rows, cols);
    if (canBeAllocated) {
        (*array2Dim) = new int* [rows];
        for (int i = 0; i < rows; i++) {
            (*array2Dim)[i] = new int[cols];
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
    }
}

bool Array2DimUtils::deallocate2DimArray(int** array2Dim, int rows) {

    bool canBeDeallocated = rows > 0;
    if (canBeDeallocated) {
        for (int i = 0; i < rows; i++) {
            delete[] array2Dim[i];
        }
        delete[] array2Dim;
    }
    // TODO : is this correct
    return canBeDeallocated;
}

bool Array2DimUtils::isArray2DimSizeValid(int rows, int cols) {
    return (rows > 0 && cols > 0);
}