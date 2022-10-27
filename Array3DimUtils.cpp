//
// Created by Lenovo on 10/25/2022.
//

#include "Array3DimUtils.h"
bool Array3DimUtils::create3DimArray(int xSize, int ySize, int zSize, int**** pointer){

    bool canBeAllocated = is3DimArraySizeValid(xSize, ySize, zSize);
    if (canBeAllocated){
        (*pointer) = new int**[xSize];
        for (int i = 0; i < xSize; i++){
            (*pointer)[i] = new int*[ySize];
            for (int j = 0; j < ySize; j++) {
                (*pointer)[i][j] = new int[zSize];
            }
        }
    }
    return canBeAllocated;
}

bool Array3DimUtils::is3DimArraySizeValid(int xSize, int ySize, int zSize){
    return xSize > 0 && ySize > 0 && zSize > 0;
}

bool Array3DimUtils::change3DimArray(int xOldSize, int yOldSize, int zOldSize, int xNewSize, int yNewSize, int zNewSize, int**** pointer){

    bool canBeAllocatedAgain = is3DimArraySizeValid(xNewSize, yNewSize, zNewSize) &&
            is3DimArraySizeValid(xOldSize, yOldSize, zOldSize);

    int*** newPointer;

    if (canBeAllocatedAgain){
        create3DimArray(xNewSize, yNewSize, zNewSize, &newPointer);
        for (int i = 0; i < smallerDim(xOldSize, xNewSize); i++){
            for (int j = 0; j < smallerDim(yNewSize, yOldSize); j++){
                ArrayUtils::copyIntArray(newPointer[i][j],
                                         (*pointer)[i][j],
                                         smallerDim(zNewSize, zOldSize));
            }
        }
        delete3DimArray(xOldSize, yOldSize, *pointer);
        (*pointer) = newPointer;
    }
    return canBeAllocatedAgain;
}

int Array3DimUtils::smallerDim(int dim1, int dim2){
    return (dim1 < dim2) ? dim1 : dim2;
}
void Array3DimUtils::delete3DimArray(int xSize, int ySize, int*** pointer){

    for (int i = 0; i < xSize; i++){
        for (int j = 0; j < ySize; j++){
            delete [] (pointer)[i][j];
        }
        delete [] (pointer)[i];
    }
    delete [] pointer;

}

void Array3DimUtils::fill3DimArray(int xSize, int ySize, int zSize, int fillValue, int*** pointer){

    bool couldBeAllocated = is3DimArraySizeValid(xSize, ySize, zSize);

    if (couldBeAllocated){
        for (int i = 0; i < xSize; i++){
            for (int j = 0; j < ySize; j++){
                for (int k = 0; k < zSize; k++){
                    pointer[i][j][k] = fillValue;
                }
            }
        }
    }

}

double Array3DimUtils::getMean3DimArray(int xSize, int ySize, int zSize, int*** pointer){

    bool couldBeAllocated = is3DimArraySizeValid(xSize, ySize, zSize);

    long double sum = 0;

    if (couldBeAllocated){
        for (int i = 0; i < xSize; i++){
            for (int j = 0; j < ySize; j++){
                for (int k = 0; k < zSize; k++){
                    sum += pointer[i][j][k];
                }
            }
        }
    }
    return (sum / (long double)(xSize * ySize * zSize));

}