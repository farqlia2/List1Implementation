//
// Created by julia on 10/19/2022.
//

#include "UserInterface.h"

bool UserInterface::initializeCTablesHandler(){
    int nOfInstances = getNumberFromUser(N_OF_INSTANCES);
    bool canBeCreated = isNOfInstancesValid(nOfInstances);
    if (canBeCreated){
        cTablesVector = new std::vector<CTable>(nOfInstances);
    } else {
        cTablesVector = NULL;
    }
    return canBeCreated;
}

bool UserInterface::isIndexValid(int index){
    return index >= 0;
}

bool UserInterface::isNOfInstancesValid(int value){
    return value > 0;
}

int UserInterface::getNumberFromUser(const std::string& message){
    std::cout << "Enter " << message << ": " << " (default is 0)\n";
    std::string userNumber;
    int value;
    std::getline(std::cin, userNumber);
    std::stringstream(userNumber) >> value;
    return value;
}

void UserInterface::displayInstances(){
    for (CTable& cTable : *cTablesVector){
        cTable.printDebugInfo();
    }
}
UserInterface::~UserInterface(){
    delete cTablesVector;
}

bool UserInterface::setNewLengthForInstance(){
    int index = getNumberFromUser(CTABLE_INDEX);
    bool canBeAccessed = isIndexValid(index);
    if (canBeAccessed){
        int newLength = getNumberFromUser(S_NEW_CTABLE_LENGTH);
        if ((*cTablesVector)[index].setNewLength(newLength)){
            return true;
        }
    }
    return false;
}

bool UserInterface::execute(){

    std::cout << "Options: change length (1), display instances (2),"
                 " add clone (3)\n";
    int userOption = getNumberFromUser(OPTION);

    switch (userOption){
        case Option::setCTableLength:
            setNewLengthForInstance();
            break;
        case Option::displayInstances:
            displayInstances();
            break;
        case Option::addCloneOf:
            addCloneOf();
            break;
        default:
            return false;
    }
    return true;
}

bool UserInterface::addCloneOf(){

    int index = getNumberFromUser(CTABLE_INDEX);
    bool canBeAccessed = isIndexValid(index);
    if (canBeAccessed){
        cTablesVector->push_back((*cTablesVector)[index]);
    }
    return canBeAccessed;
}