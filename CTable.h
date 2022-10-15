#pragma once
#include "Utils.h"
#include <string>
#include <iostream>

const std::string NAME = "name";
const std::string SUFFIX = "_copy";
const int LENGTH = 10;

class CTable {
public:
	CTable();
	CTable(std::string name, int tableLength);
	CTable(CTable& other);
	~CTable();
	void setName(std::string name);
	bool setNewLength(int newLength);
	CTable* clone();

	void printDebugInfo();
private:
	std::string name;
	int* array;
	int  length;
	void printName(std::string message);
};