#include "CTable.h"

CTable::CTable(std::string name, int tableLength) {
	this->name = name;
	this->length = tableLength;
	this->array = new int[tableLength];
	printName((std::string &)"parametric");
}

CTable::CTable() {
	this->name = NAME;
	this->length = LENGTH;
	this->array = new int[LENGTH];
	printName((std::string &)"non-parametric");
}

CTable::CTable(CTable& other) {
	this->name = other.name + SUFFIX;
	this->length = other.length;
	this->array = new int[other.length];
	Utils::copyIntArray(array, other.array, length);
	printName((std::string &)"copy");
}
void CTable::setName(std::string name) {
	this->name = name;
}
bool CTable::setNewLength(int newLength) {
	bool isSizeValid = newLength > 0;
	if (isSizeValid) {
		int* newArray = new int[newLength];
		Utils::copyIntArray(newArray, this->array, (newLength < length) ? newLength : length);
		delete[] array;
		this->array = newArray;
	}
	return isSizeValid;
}

CTable* CTable::clone(){
	return new CTable(*this);
}

CTable::~CTable() {
	delete[] array;
	printName((std::string &) "deleting");
}

void CTable::printName(std::string& message) {
	std::cout << message << ": " << this->name << "\n";
}

void CTable::printDebugInfo() {
	std::cout << "My name is" << name
		<< ", length = " << length << ", array = " << 
		array << ", address = " << this << "\n";
}