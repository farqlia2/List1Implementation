//
// Created by julia on 10/19/2022.
//
#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include "CTable.h"

const std::string N_OF_INSTANCES = "number of instances";
const std::string CTABLE_INDEX = "index of ctable object";
const std::string S_NEW_CTABLE_LENGTH = "new length of CTable";
const std::string OPTION = "option";

enum Option {
    setCTableLength = 1, displayInstances = 2,
    addCloneOf = 3
};


class UserInterface {
public:
    bool initializeCTablesHandler();
    void displayInstances();
    bool setNewLengthForInstance();
    bool addCloneOf();
    bool execute();
    ~UserInterface();
private:
    std::vector<CTable>* cTablesVector;
    int getNumberFromUser(const std::string& message);
    bool isIndexValid(int index);
    bool isNOfInstancesValid(int value);
};