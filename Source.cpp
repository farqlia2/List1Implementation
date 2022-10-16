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

int main() {

	std::cout << "Exercise 1 Solution: \n";

	ArrayUtils::allocateArrayFill(ARRAY_SIZE, FILL_VALUE);

	std::cout << "Exercise 2 Solution: \n";

	int** array2Dim = NULL;
	if (Array2DimUtils::allocate2DimArray(&array2Dim, ROWS, COLS)){
		Array2DimUtils::print2DimArray(array2Dim, ROWS, COLS);
	}

	Array2DimUtils::deallocate2DimArray(&array2Dim, ROWS);

	if (DEBUG) std::cout << "&array2Dim = " << &array2Dim << ", array2Dim = "
		<< array2Dim << "\n";
	
	std::cout << "Exercise 3 Solution: \n";

	CTable cTableDefault;

    if (DEBUG) cTableDefault.printDebugInfo();

	CTable cTableParam(CTABLE_NAME, CTABLE_LENGTH);

	if (DEBUG) cTableParam.printDebugInfo();

	CTable cTableCopy(cTableParam);

	if (DEBUG) cTableCopy.printDebugInfo();

    if (DEBUG) std::cout << "Tries to change the name and double the length\n";
    cTableParam.setName(NEW_CTABLE_NAME);
    cTableParam.setNewLength(2 * CTABLE_LENGTH);

    if (DEBUG) {
        cTableParam.printDebugInfo();
        std::cout << "Does the change affect copy?\n";
        cTableCopy.printDebugInfo();
    }

    cTableParam.setNewLength(0);
    if (DEBUG) {
        std::cout << "Tries to set length = 0:\n";
        cTableParam.printDebugInfo();
    }

    cTableParam.setNewLength(-1 * CTABLE_LENGTH);
    if (DEBUG) {
        std::cout << "Tries to set length = " << -1 * CTABLE_LENGTH << "\n";
        cTableParam.printDebugInfo();
    }

    CTable * dynamicCTable = new CTable(DYNAMIC_CTABLE_NAME, LENGTH);
    CTable* copyOfDynamicTable = dynamicCTable->clone();

    if (DEBUG) {
        dynamicCTable->printDebugInfo();
        copyOfDynamicTable->printDebugInfo();
    }

    if (DEBUG) std::cout << "Tries to modify an instance\n";
    if (DEBUG) std::cout << "Pass by value\n";
    modCTable(cTableDefault, CTABLE_LENGTH);
    if (DEBUG) cTableDefault.printDebugInfo();

    if (DEBUG) std::cout << "Pass by reference\n";
    modCTable(&cTableDefault, CTABLE_LENGTH);
    if (DEBUG) cTableDefault.printDebugInfo();

    delete dynamicCTable;
    delete copyOfDynamicTable;

    int defaultSize = 10;

    std::vector<CTable> cTableVector;
    int length = 5;
    int lengths[] = {1, 2, 3, 4, 5};
    std::string names[] = {"T1", "T2", "T3", "T4", "T5"};

    for (int i = 0; i < length; i++){
        std::cout << "Inserting element, i = " << i << "\n";
        cTableVector.push_back(CTable(names[i], lengths[i]));
    }

    for (CTable & i : cTableVector){
        i.printDebugInfo();
    }

}

void modCTable(CTable table, int newLength){
    table.setNewLength(newLength);
}

void modCTable(CTable *table, int newLength){
    table->setNewLength(newLength);
}