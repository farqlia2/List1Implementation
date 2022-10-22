#include "CTable.h"

CTable::CTable(std::string name, int tableLength) {
	this->name = name;
	this->length = tableLength;
	this->array = new int[tableLength];
    printInfo(PARAMETRIC_MESSAGE);
}

CTable::CTable() {
	this->name = DEFAULT_NAME;
	this->length = DEFAULT_LENGTH;
	this->array = new int[DEFAULT_LENGTH];
    printInfo(DEFAULT_MESSAGE);
}
// copy constructor should be used
// if we have some dynamic memory allocated, or we don't
// want to copy some fields
CTable::CTable(const CTable& other) {
	this->name = other.name + SUFFIX;
	this->length = other.length;
	this->array = new int[other.length];
	ArrayUtils::copyIntArray(array, other.array, length);
    printInfo(COPY_MESSAGE);
}
void CTable::setName(std::string name){
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

// TODO : it makes sense for this exercise to print things out, but in general it is bad
std::string CTable::getDebugInfo() {
    std::stringstream lengthString, arrayAddress, addressString;
    lengthString << length;
    arrayAddress << &array;
    addressString << this;
	return "My name is " + name
		+ ", length = " + lengthString.str() + ", array = " +
		arrayAddress.str() + ", address = " + addressString.str() + "\n";
}