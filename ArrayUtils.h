//
// Created by Lenovo on 16.10.2022.
//

#ifndef LIST1IMPLEMENTATION_ARRAYUTILS_H
#define LIST1IMPLEMENTATION_ARRAYUTILS_H

#include <iostream>

// allocator do macierzy intow ktory ma 4 wymiary, to nie moze byc w alokatorze
// ampersand

class ArrayUtils {
public:
    static void fillArray(int* array, int size, int fillValue);

    static bool allocateArray(int** array, int size);

    static void allocateArrayFill(int size, int fillValue);

    static bool isArraySizeValid(int size);

    static void copyIntArray(int* destination, const int* source, int size);

    static void printIntArray(int* array, int size);

};

#endif //LIST1IMPLEMENTATION_ARRAYUTILS_H
