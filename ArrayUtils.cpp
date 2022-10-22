//
// Created by Lenovo on 16.10.2022.
//

#include "ArrayUtils.h"


void ArrayUtils::copyIntArray(int* destination, const int* source, int size) {
    for (int i = 0; i < size; i++) {
        destination[i] = source[i];
    }
}

void ArrayUtils::printIntArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "array[" << i << "] = " << array[i] << "\n";
    }
    std::cout << "\n";
}

bool ArrayUtils::isArraySizeValid(int size) {
    return size > 0;
}
void ArrayUtils::fillArray(int* array, int size, int fillValue) {
    for (int i = 0; i < size; i++) {
        array[i] = fillValue;
    }
}

bool ArrayUtils::allocateArray(int** array, int size) {
    bool isSizeValid = isArraySizeValid(size);
    if (isSizeValid) {
        (*array) = new int[size];
    }
    return isSizeValid;
}

void ArrayUtils::allocateArrayFill(int size, int fillValue){
    int* array;
    if (allocateArray(&array, size)) {
        fillArray(array, size, fillValue);
        ArrayUtils::printIntArray(array, size);
        delete[] array;
    }
}