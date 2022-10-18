//
// Created by Lenovo on 18.10.2022.
//

#include "Shareable.h"

Shareable::Shareable() {
    this->existingMembers = 1;
}

void Shareable::incrementShares(){
    this->existingMembers += 1;
    std::cout << "Current shares = " << existingMembers << "\n";
}

void Shareable::decrementShares(){
    this->existingMembers -= 1;
    std::cout << "Current shares = " << existingMembers << "\n";
}
bool Shareable::isShared(){
   return this->existingMembers > 1;
}