#include <stdlib.h>
#include <stdio.h>
#include "../include/geometry.h"
#include "../include/colors.h"

/************** MAIN ***************/

int main(int argc, char **argv) {
	//printf("test\n");
	//Point3D A = pointXYZ(0.,0.,0.);
    //Vector3D B = vectorXYZ(1.,2.,0.);

    //printPoint3D(pointPlusVector(A,B));

	Vector3D v1 = vectorXYZ(0, 0, 0);
	Vector3D v1bis = vectorXYZ(1, 2, 0);
	printPoint3D(pointPlusVector(v1, v1bis));

	Vector3D v2 = vectorXYZ(0.5, 1.0, -2.0);
	Vector3D v2bis = vectorXYZ(0.2, -1.0, 0);
	printVector3D(addVectors(v2,v2bis));

	Vector3D v3 = vectorXYZ(0.5, 1.0, -2.0);
	Vector3D v3bis = vectorXYZ(0.2, -1.0, 0);
	printVector3D(subVectors(v3, v3bis));

	Vector3D v4 = vectorXYZ(0.5, 1.0, -2.0);
	printVector3D(multVector(v4, 2.0));
	printVector3D(multVector(v4, 0.0));
	printVector3D(divVector(v4, 2.0));
	printVector3D(divVector(v4, 0.0));

	Vector3D v5 = vectorXYZ(1.0, 0.0, 0.0);
	Vector3D v5bis = vectorXYZ(2.0, 0.0, 0.0);
	printf("%f\n", dot(v5, v5bis));

	Vector3D v5bisbis = vectorXYZ(0.0, 1.0, 0.0);
	printf("%f\n", dot(v5, v5bisbis));

	Vector3D v6 = vectorXYZ(2, 0, 0);
	printf("%f\n", norm(v6));
	Vector3D v7 = vectorXYZ(1, 1, 1);
	printf("%f\n", norm(v7));
	printVector3D(normalize(v7));
	Vector3D v8 = vectorXYZ(0,0,0);
	printf("%f\n",norm(v8));
	printVector3D(normalize(v8)); 

    return EXIT_SUCCESS;
}