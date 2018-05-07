#include <stdlib.h>
#include <stdio.h>
#include "../include/shape.h"
#include "../include/geometry.h"
#include "../include/colors.h"
#include "../include/raytracer.h"



/************** MAIN ***************/

int main(int argc, char **argv) {
	Ray ray = createRay(0,0,0, 1, 1, 1);
	Cube cube = createCube(100,100,100,200,200,200,255,0,0);
	//Intersection I;
	//printf("%d",intersectsCube(ray, cube, &I));

    return EXIT_SUCCESS;
}