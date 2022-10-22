// komendy prekompilatora
// tam, gdzie DEBUG zamien na true
// przed oddaniem dajemy false
#include "Constants.h"
#include "CTable.h"
#include "ArrayUtils.h"
#include "Array2DimUtils.h"
#include "Global.h"

/*
If (DEBUG) => jakies cout i dalej
*/

void modCTable(CTable table, int newLength);

void modCTable(CTable *table, int newLength);

void allocateArrayFill34(int size);

void triangleMatrix(int*** matrix, int size);

int main() {

    int** matrix;
    triangleMatrix(&matrix, MATRIX_SIZE);

    allocateArrayFill34(ARRAY_SIZE);

    int** pointer2DArray;
    if (Array2DimUtils::allocate2DimArray(&pointer2DArray, ROWS, COLS)){
        if (DEBUG) Array2DimUtils::fill2DimArray(pointer2DArray, ROWS, COLS, FILL_VALUE);
        if (DEBUG) Array2DimUtils::print2DimArray(pointer2DArray, ROWS, COLS);
        Array2DimUtils::deallocate2DimArray(pointer2DArray, ROWS);
        if (DEBUG) {
            std::cout << "After deallocating\n";
            ArrayUtils::printIntArray(pointer2DArray[1], COLS);
        }
    }


    if (DEBUG) std::cout << "pointer2DArray = " << pointer2DArray << "\n";

    CTable nonParamCTable;
    CTable paramCTable (CTABLE_NAME, CTABLE_LENGTH);
    CTable copyParamCTable (paramCTable);

    if (DEBUG) std::cout << "Print objects\n";
    std::cout << paramCTable.getDebugInfo();
    std::cout << copyParamCTable.getDebugInfo();

    if (DEBUG) std::cout << "Change the length and the name of an array\n";
    paramCTable.setNewLength(NEW_CTABLE_LENGTH);
    std::cout << &NEW_CTABLE_LENGTH << "\n";
    paramCTable.setName(NEW_CTABLE_NAME);
    if (DEBUG) std::cout << "\n";

    if (DEBUG) std::cout << "Does the change affect copy?\n";
    std::cout << paramCTable.getDebugInfo();
    std::cout << copyParamCTable.getDebugInfo();
    if (DEBUG) std::cout << "\n";

    CTable* cloneCTable = paramCTable.clone();
    if (DEBUG) {
        std::cout << "Cloned CTable\n";
        std::cout << cloneCTable->getDebugInfo();
    }
    if (DEBUG) std::cout << "\n";

    modCTable(nonParamCTable, NEW_CTABLE_LENGTH);
    modCTable(&nonParamCTable, NEW_CTABLE_LENGTH);

    std::cout << "Allocate static array: \n";
    CTable cTableStaticArray[SIZE];

    if (DEBUG) std::cout << "\nAllocate dynamic array: \n";
    CTable* cTableDynamicArray;

    // The default constructor is called for each 'slot'
    cTableDynamicArray = new CTable[SIZE];

    if (DEBUG) std::cout << "\nDeallocate dynamic array: \n";
    delete [] cTableDynamicArray;

    if (DEBUG) std::cout << "\nTest dynamic allocation with a vector\n";
    std::vector<CTable> vector;
    for (int i = 0; i < VECTOR_LENGTH; i++){
        vector.push_back(CTable(CTABLE_NAMES[i],CTABLE_LENGTHS[i]));
    }

    if (DEBUG) std::cout << "\n";
}

void modCTable(CTable table, int newLength){
    table.setNewLength(newLength);
}

void modCTable(CTable *table, int newLength){
    table->setNewLength(newLength);
}

void allocateArrayFill34(int size){
    ArrayUtils::allocateArrayFill(size, FILL_VALUE);
}

void triangleMatrix(int*** matrix, int size){

    if (Array2DimUtils::allocate2DimArray(matrix, size, size)){
        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                (*matrix)[i][j] = (j <= i) ? 1 : 0;
            }
        }
        Array2DimUtils::print2DimArray(*matrix, size, size);
    }

}