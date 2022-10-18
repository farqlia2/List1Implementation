#pragma once
#include <string>
#include <iostream>
#include "ArrayUtils.h"

const std::string NAME = "default";
const std::string SUFFIX = "_copy";
const int LENGTH = 10;

const std::string DEFAULT_MESSAGE = "default";
const std::string PARAMETRIC_MESSAGE = "parametric";
const std::string COPY_MESSAGE = "copy";
const std::string DELETE_MESSAGE = "deleting";

class CTable {
public:
	CTable();
	CTable(std::string name, int tableLength);
	CTable(const CTable& other);
	~CTable();
	void setName(std::string name);
	bool setNewLength(int newLength);
	CTable* clone();
	void printDebugInfo();
private:
	std::string name;
	int* array;
	int  length;
	void printInfo(const std::string& message);
};
