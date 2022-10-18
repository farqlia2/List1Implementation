//
// Created by Lenovo on 18.10.2022.
//

#ifndef LIST1IMPLEMENTATION_SHAREABLE_H
#define LIST1IMPLEMENTATION_SHAREABLE_H
#include <iostream>

class Shareable {
public:
    Shareable();
    void incrementShares();
    void decrementShares();
    bool isShared();
private:
    int existingMembers;
};


#endif //LIST1IMPLEMENTATION_SHAREABLE_H
