#include "Utils.h"

void Utils::copyIntArray(int* destination, int* source, int size) {
	for (int i = 0; i < size; i++) {
		destination[i] = source[i];
	}
}