// komendy prekompilatora
// tam, gdzie DEBUG zamien na true
// przed oddaniem dajemy false
#define DEBUG true
#include <iostream>
//#include "Constants.h"

int FILL_VALUE = 34;
int ARRAY_SIZE = 10;

int ROWS = 5;
int COLS = 4;

/*
If (DEBUG) => jakies cout i dalej
*/

// --- EXERCISE 1 ---

void fillArray(int* array, int size, int fillValue);

void printArray(int* array, int size);

bool allocateArray(int* array, int size);

void allocateArrayFill(int size, int fillValue);

// ??
void allocateArrayFill34();

// --- EXERCISE 2 ---

// to to ma byc potrojny
bool allocateArray2Dim(int** array2Dim, int rows, int cols);

void print2DimArray(int** array2Dim, int rows, int cols);

bool deallocateArray2Dim(int** array2Dim, int rows, int cols);

bool isSize2DimValid(int rows, int cols);

int main() {

	allocateArrayFill(ARRAY_SIZE, FILL_VALUE);

	int** array2Dim = NULL;
	if (allocateArray2Dim(array2Dim, ROWS, COLS)){
		print2DimArray(array2Dim, ROWS, COLS);
	}

	deallocateArray2Dim(array2Dim, ROWS, COLS);

	// Vector<CTable>
	

}

void fillArray(int* array, int size, int fillValue) {

	for (int i = 0; i < size; i++) {
		array[i] = fillValue;
	}

}

bool allocateArray(int* array, int size) {
	bool isSizeValid = size > 0;
	if (isSizeValid) {
		array = new int[size];
	}
	return isSizeValid;
}

void printArray(int* array, int size) {

	for (int i = 0; i < size; i++) {
		std::cout << "array[" << i << "] = " << array[i] << "\n";
	}
	std::cout << "\n";
}

void allocateArrayFill(int size, int fillValue){
	
	int* array = NULL;
	if (allocateArray(array, size)) {
		fillArray(array, size, fillValue);
		if (DEBUG) printArray(array, size);
		delete[] array;
	}
}

void allocateArrayFill34(){}

bool allocateArray2Dim(int** array2Dim, int rows, int cols) {

	bool canBeAllocated = isSize2DimValid(rows, cols);
	if (canBeAllocated) {
		array2Dim = new int* [rows];
		for (int i = 0; i < rows; i++) {
			array2Dim[i] = new int[cols];
		}
	}
	return canBeAllocated;
}

void print2DimArray(int** array2Dim, int rows, int cols) {

	for (int i = 0; i < rows; i++) {
		printArray(array2Dim[i], cols);
		std::cout << "\n";
	}

}

bool deallocateArray2Dim(int** array2Dim, int rows, int cols) {

	bool couldBeAllocated = isSize2DimValid(rows, cols);
	if (couldBeAllocated) {
		for (int i = 0; i < rows; i++) {
			delete[] array2Dim[i];
		}
		delete[] array2Dim;
	}
	return couldBeAllocated;
}

bool isSize2DimValid(int rows, int cols) {
	return rows > 0 && cols < 0;
}