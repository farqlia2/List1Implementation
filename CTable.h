#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "ArrayUtils.h"

const std::string DEFAULT_NAME = "default";
const std::string SUFFIX = "_copy";
const int DEFAULT_LENGTH = 10;

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
    std::string getDebugInfo();
    void operator=(const CTable &other);
private:
	std::string name;
	int* array;
	int  length;
	void printInfo(const std::string& message);
};
