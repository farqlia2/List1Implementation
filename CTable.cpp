#include "CTable.h"

CTable::CTable(std::string name, int tableLength) {
	this->name = name;
	this->length = tableLength;
	this->array = new int[tableLength];
    printInfo(PARAMETRIC_MESSAGE);
}

CTable::CTable() {
	this->name = NAME;
	this->length = LENGTH;
	this->array = new int[LENGTH];
    printInfo(DEFAULT_MESSAGE);
}

CTable::CTable(const CTable& other) {
	this->name = other.name + SUFFIX;
	this->length = other.length;
	this->array = new int[other.length];
	ArrayUtils::copyIntArray(array, other.array, length);
    printInfo(COPY_MESSAGE);
}
void CTable::setName(std::string name) {
	this->name = name;
}
bool CTable::setNewLength(int newLength) {
    // Can the new size be smaller than the current one?
	bool isSizeValid = newLength > 0;
	if (isSizeValid) {
		int* newArray = new int[newLength];
		ArrayUtils::copyIntArray(newArray, this->array,
                            (newLength < length) ? newLength : length);
		delete[] array;
		this->array = newArray;
        this->length = newLength;
	}
	return isSizeValid;
}

CTable* CTable::clone(){
	return new CTable(*this);
}

// In our case destructor is useful for
// deallocating dynamic memory
CTable::~CTable() {
	delete[] array;
    printInfo(DELETE_MESSAGE);
}

void CTable::printInfo(const std::string& message) {
	std::cout << message << ": " << this->name << "\n";
}

void CTable::printDebugInfo() {
	std::cout << "My name is " << name
		<< ", length = " << length << ", array = " << 
		array << ", address = " << this << "\n";
}