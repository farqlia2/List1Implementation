#include "Utils.h"

void Utils::copyIntArray(int* destination, const int* source, int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}

void Utils::printIntArray(int *array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "array[" << i << "] = " << array[i] << "\n";
    }
    std::cout << "\n";
}