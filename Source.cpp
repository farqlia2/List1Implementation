// komendy prekompilatora
// tam, gdzie DEBUG zamien na true
// przed oddaniem dajemy false
#define DEBUG true
#include "Constants.h"
#include "CTable.h"

/*
If (DEBUG) => jakies cout i dalej
*/

// --- EXERCISE 1 ---

void fillArray(int* array, int size, int fillValue);

void printArray(int* array, int size);

// single pointer would populate an array, but would not change
// the place to which the passed pointer points to - it is because
// the local copy of the pointer is created and it is assigned the 
// address of the allocated array, but after the function is finished, 
// it is popped from the stack - it actually leads to memory leak.
bool allocateArray(int** array, int size);

void allocateArrayFill(int size, int fillValue);

bool isArraySizeValid(int size);

// ??
void allocateArrayFill34();

// --- EXERCISE 2 ---

// This has to be triple pointer - the reason is the same as for 
// the 1-dim array
bool allocate2DimArray(int*** array2Dim, int rows, int cols);

void print2DimArray(int** array2Dim, int rows, int cols);

bool deallocate2DimArray(int*** array2Dim, int rows);

bool isArray2DimSizeValid(int rows, int cols);

int main() {
	/*
	std::cout << "Exercise 1 Solution: \n";

	allocateArrayFill(ARRAY_SIZE, FILL_VALUE);

	std::cout << "Exercise 2 Solution: \n";

	int** array2Dim = NULL;
	if (allocate2DimArray(&array2Dim, ROWS, COLS)){
		print2DimArray(array2Dim, ROWS, COLS);
	}

	deallocate2DimArray(&array2Dim, ROWS);

	if (DEBUG) std::cout << "&array2Dim = " << &array2Dim << ", array2Dim = "
		<< array2Dim << "\n";

	*/

	// Vector<CTable>
	
	// Default constructors are called without parenthesis!!
	CTable cTable1;

	if (DEBUG) cTable1.printDebugInfo();

	CTable cTable2("random_table", 10);

	if (DEBUG) cTable2.printDebugInfo();

	CTable cTable3(cTable2);

	if (DEBUG) cTable3.printDebugInfo();

    CTable * dynamicTable = new CTable("Pippi", 30);

    if (DEBUG) {
        std::cout << "Dynamic CTable\n";
        dynamicTable->printDebugInfo();
    }

    CTable* clonedTable = dynamicTable->clone();

    if (DEBUG) {
        std::cout << "Cloned Dynamic CTable\n";
        clonedTable->printDebugInfo();
    }

    delete dynamicTable;
    delete clonedTable;

}

bool isArraySizeValid(int size) {
	return size > 0;
}
void fillArray(int* array, int size, int fillValue) {

	for (int i = 0; i < size; i++) {
		(array)[i] = fillValue;
	}
}

bool allocateArray(int** array, int size) {
	bool isSizeValid = isArraySizeValid(size);
	if (isSizeValid) {
		(*array) = new int[size];
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
	if (allocateArray(&array, size)) {
		fillArray(array, size, fillValue);
		printArray(array, size);
		delete[] array;
	}
}

void allocateArrayFill34(){}


bool allocate2DimArray(int*** array2Dim, int rows, int cols) {

	bool canBeAllocated = isArray2DimSizeValid(rows, cols);
	if (canBeAllocated) {
		(*array2Dim) = new int* [rows];
		if (DEBUG) std::cout << "*array2Dim = " << *array2Dim << "\n";
		for (int i = 0; i < rows; i++) {
			(*array2Dim)[i] = new int[cols];
			if (DEBUG) std::cout << "**array2Dim = " << (*array2Dim)[i] << "\n";
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

bool deallocate2DimArray(int*** array2Dim, int rows) {
	
	bool canBeDeallocated = (*array2Dim) != NULL;
	if (canBeDeallocated) {
		for (int i = 0; i < rows; i++) {
			delete[] (*array2Dim)[i];
		}
		delete[] (*array2Dim);
	}
	(*array2Dim) = NULL;
	return canBeDeallocated;
}

bool isArray2DimSizeValid(int rows, int cols) {
	return (rows > 0 && cols > 0) && (isArraySizeValid(rows * cols));
}
