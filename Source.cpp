// komendy prekompilatora
// tam, gdzie DEBUG zamien na true
// przed oddaniem dajemy false
#include "Constants.h"
#include "CTable.h"
#include "ArrayUtils.h"
#include "Array2DimUtils.h"
#include "Global.h"
#include "Array3DimUtils.h"

/*
If (DEBUG) => jakies cout i dalej
*/

void modCTable(CTable table, int newLength);

void modCTable(CTable *table, int newLength);

void allocateArrayFill34(int size);

CTable createNewCTable();

CTable* createNewPointerCTable();

void testScopeOfObjects();

void modifyInt(int& anInt);
void modifyCopyInt(int anInt);

int main() {
    if (DEBUG) std::cout << "Enter main\n";

    /*
    CTable* aTable = new CTable;
    aTable->displayTable();

    CTable* cT1 = new CTable("c_table_1", ARRAY_SIZE);

    cT1->fillTable(FILL_VALUE);
    cT1->displayTable();

    CTable* cT2 = new CTable(*cT1);
    CTable* cT3 = new CTable(*cT1);
    CTable* cT4 = new CTable(*cT1);

    delete cT1;

    cT2->displayTable();

    cT4->setNewLength(NEW_CTABLE_LENGTH);
    cT4->fillTable(0);
    cT4->displayTable();

    cT2->displayTable();

    delete cT2;
    delete cT3;

    cT4->displayTable();

    delete cT4;*/

    int*** pointer;

    std::cout << Array3DimUtils::create3DimArray(0, 5, 6, &pointer) << "\n";
    std::cout << Array3DimUtils::create3DimArray(3, 5, 6, &pointer) << "\n";
    Array3DimUtils::fill3DimArray(3, 5, 6, 55, pointer);

    pointer[0][4][5] = 0;
    std::cout << Array3DimUtils::getMean3DimArray(3, 5, 6, pointer) << "\n";

    std::cout << Array3DimUtils::change3DimArray(3, 5, 6, 1, 2, 3, &pointer) << "\n";

    Array3DimUtils::fill3DimArray(1, 2, 3, 0, pointer);
    pointer[0][1][1] = 6;

    std::cout << Array3DimUtils::getMean3DimArray(1, 2, 3, pointer) << "\n";

    Array3DimUtils::delete3DimArray(1, 2, pointer);

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

void allocateArrayFill34(int size){
    ArrayUtils::allocateArrayFill(size, FILL_VALUE);
}

void modifyInt(int& anInt){
    std::cout << "anInt = " << anInt << ", address = " << &anInt << "\n";
    anInt = 4;
}
void modifyCopyInt(int anInt){
    std::cout << "anInt = " << anInt << ", address = " << &anInt << "\n";
    anInt = 4;
}