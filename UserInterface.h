//
// Created by julia on 10/19/2022.
//

#ifndef LIST1IMPLEMENTATION_USERINTERFACE_H
#define LIST1IMPLEMENTATION_USERINTERFACE_H
#include <iostream>
#include <vector>
#include "CTable.h"

class UserInterface {
public:
    UserInterface();
private:
    std::vector<CTable>* cTableVector;
};


#endif //LIST1IMPLEMENTATION_USERINTERFACE_H
