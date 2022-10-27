//
// Created by Lenovo on 10/25/2022.
//

#ifndef LIST1IMPLEMENTATION_ARRAY3DIMUTILS_H
#define LIST1IMPLEMENTATION_ARRAY3DIMUTILS_H
#include "ArrayUtils.h"

class Array3DimUtils {
public:
    static bool create3DimArray(int xSize, int ySize, int zSize, int**** pointer);

    static bool is3DimArraySizeValid(int xSize, int ySize, int zSize);

    static bool change3DimArray(int xOldSize, int yOldSize, int zOldSize, int xNewSize,
                                int yNewSize, int zNewSize,  int**** pointer);

    static int smallerDim(int dim1, int dim2);

    static void delete3DimArray(int xSize, int ySize, int*** pointer);

    static void fill3DimArray(int xSize, int ySize, int zSize, int fillValue, int*** pointer);

    static double getMean3DimArray(int xSize, int ySize, int zSize, int*** pointer);
};


#endif //LIST1IMPLEMENTATION_ARRAY3DIMUTILS_H
