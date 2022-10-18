//
// Created by Lenovo on 16.10.2022.
//

#ifndef LIST1IMPLEMENTATION_ARRAYUTILS_H
#define LIST1IMPLEMENTATION_ARRAYUTILS_H

#include <iostream>

class ArrayUtils {
public:
    static void fillArray(int* array, int size, int fillValue);

    // single pointer would populate an array, but would not change
    // the place to which the passed pointer points to - it is because
    // the local copy of the pointer is created and it is assigned the
    // address of the allocated array, but after the function is finished,
    // it is popped from the stack - it actually leads to memory leak.
    static bool allocateArray(int*& array, int size);

    static void allocateArrayFill(int size, int fillValue);

    static bool isArraySizeValid(int size);

    static void copyIntArray(int* destination, const int* source, int size);

    static void printIntArray(int* array, int size);

};


#endif //LIST1IMPLEMENTATION_ARRAYUTILS_H
