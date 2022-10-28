//
// Created by julia on 10/28/2022.
//

#include "Array4DimUtils.h"

bool Array4DimUtils::allocate4DimArray(int xSize, int ySize, int zSize, int qSize,
                       int***** pointer){

    bool canBeAllocated = xSize > 0 && ySize > 0 && zSize > 0 && qSize > 0;

    if (canBeAllocated){
        (*pointer) = new int***[xSize];
        for (int i = 0; i < xSize; i++){
            (*pointer)[i] = new int**[ySize];
            for (int j = 0; j < ySize; j++){
                (*pointer)[i][j] = new int*[zSize];
                for (int k = 0; k < zSize; k++){
                    (*pointer)[i][j][k] = new int[qSize];
                }
            }
        }
    }
    return canBeAllocated;

}