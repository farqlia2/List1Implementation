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

void allocateArrayFillGlobal();

CTable createNewCTable();

CTable* createNewPointerCTable();

void testScopeOfObjects();

int main() {
    if (DEBUG) std::cout << "Enter main\n";

    if (EXERCISE == 1){
        std::cout << "Exercise 1 Solution: \n";

        allocateArrayFillGlobal();
    }

    else if (EXERCISE == 2){
        std::cout << "Exercise 2 Solution: \n";

        int **array2Dim = NULL;
        if (Array2DimUtils::allocate2DimArray(&array2Dim, ROWS, COLS)) {
            Array2DimUtils::print2DimArray(array2Dim, ROWS, COLS);
        }

        Array2DimUtils::deallocate2DimArray(&array2Dim, ROWS);

        if (DEBUG)
            std::cout << "&array2Dim = " << &array2Dim << ", array2Dim = "
                      << array2Dim << "\n";
    }
	else if (EXERCISE == 3){


	std::cout << "Exercise 3 Solution: \n";

	CTable cTableDefault;

    if (DEBUG) cTableDefault.printDebugInfo();

	CTable cTableParam(CTABLE_NAME, CTABLE_LENGTH);

	if (DEBUG) cTableParam.printDebugInfo();

	CTable cTableCopy(cTableParam);

	if (DEBUG) cTableCopy.printDebugInfo();

    if (DEBUG) std::cout << "\nTries to change the name and double the length\n";
    cTableParam.setName(NEW_CTABLE_NAME);
    cTableParam.setNewLength(2 * CTABLE_LENGTH);

    if (DEBUG) {
        cTableParam.printDebugInfo();
        std::cout << "Does the change affect copy?\n";
        cTableCopy.printDebugInfo();
    }

    cTableParam.setNewLength(0);
    if (DEBUG) {
        std::cout << "\nTries to set length = 0:\n";
        cTableParam.printDebugInfo();
    }

    cTableParam.setNewLength(NEGATIVE_VALUE);
    if (DEBUG) {
        std::cout << "Tries to set length = " << NEGATIVE_VALUE << "\n";
        cTableParam.printDebugInfo();
    }

    if (DEBUG) std::cout << "\nTries to set dynamic objects\n";
    CTable* dynamicCTable = new CTable(DYNAMIC_CTABLE_NAME, LENGTH);
    CTable* copyOfDynamicTable = dynamicCTable->clone();

    if (DEBUG) {
        dynamicCTable->printDebugInfo();
        copyOfDynamicTable->printDebugInfo();
    }

    if (DEBUG) std::cout << "\nTries to modify an instance\n";
    if (DEBUG) std::cout << "Pass by value\n";
    modCTable(cTableDefault, CTABLE_LENGTH);
    if (DEBUG) cTableDefault.printDebugInfo();

    if (DEBUG) std::cout << "Pass by reference\n";
    modCTable(&cTableDefault, CTABLE_LENGTH);
    if (DEBUG) cTableDefault.printDebugInfo();

    delete dynamicCTable;
    delete copyOfDynamicTable;
    }

    // int defaultSize = 10;

    else {


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


    // Interestingly we don't have a copy created here
    modCTable(CTable("created_in_fly", 10), 20);

    CTable cTable;

    // Here the copy is created
    modCTable(cTable, 20);
    cTable.printDebugInfo();

    modCTable(&cTable, 20);
    cTable.printDebugInfo();

    CTable cTableFromFunc = createNewCTable();

    cTableFromFunc.printDebugInfo();

    CTable* ptrCTable = createNewPointerCTable();

    ptrCTable->printDebugInfo();

    delete ptrCTable;


    testScopeOfObjects();

    }

    if (DEBUG) std::cout << "Exit main\n";

}

void modCTable(CTable table, int newLength){
    table.setNewLength(newLength);
}

void modCTable(CTable *table, int newLength){
    table->setNewLength(newLength);
}

// It looks like the object created here is local to the function
// from which this function was created
CTable createNewCTable(){
    CTable tb ("object_ctable", ARRAY_SIZE);
    tb.printDebugInfo();
    return tb;
}

CTable* createNewPointerCTable(){
    CTable* ptrCTable = new CTable("pointer_ctable", ARRAY_SIZE);
    ptrCTable->printDebugInfo();
    return ptrCTable;
}

void testScopeOfObjects(){

    std::cout << "Enter testScopeOfObjects\n";

    CTable cTableFromFunc = createNewCTable();

    cTableFromFunc.printDebugInfo();

    CTable* ptrCTable = createNewPointerCTable();

    ptrCTable->printDebugInfo();

    delete ptrCTable;

    std::cout << "Exit testScopeOfObjects\n";
}

void allocateArrayFillGlobal(){
    ArrayUtils::allocateArrayFill(ARRAY_SIZE, FILL_VALUE);
}