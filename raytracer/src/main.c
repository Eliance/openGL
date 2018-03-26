#include <stdlib.h>
#include <stdio.h>
#include <geometry.h>
#include <colors.h>
#include <math.h>

int main(int argc, char **argv){
    Point3D A = pointXYZ(0.,0.,0.);
    Vector3D B = vectorXYZ(1.,2.,0.);
    
    printPoint3D(pointPlusVector(A,B));
    return EXIT_SUCCESS;
}
