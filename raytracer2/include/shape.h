#ifndef SHAPE_H
#define SHAPE_H

#include "geometry.h"
#include "colors.h"

typedef struct sphere{
	Point3D centre;
	float R;
	Color3f couleur;
}Sphere;

typedef struct cube{
	Point3D Pmin, Pmax;
	Color3f couleur;
}Cube;

Sphere createSphere(float Ox, float Oy, float Oz, float R, float r, float g, float b){
	Sphere sphere;
	sphere.centre = pointXYZ(Ox,Oy,Oz);
	sphere.R=r;
	sphere.couleur.r=r;
	sphere.couleur.g=g;
	sphere.couleur.b=b;
	return sphere;
}

Cube createCube(float Pminx, float Pminy, float Pminz, float Pmaxx, float Pmaxy, float Pmaxz, float r, float g, float b){
	Cube cube;
	cube.Pmin = pointXYZ(Pminx, Pminy, Pminz);
	cube.Pmax = pointXYZ(Pmaxx, Pmaxy, Pmaxz);
	cube.couleur.r=r;
	cube.couleur.g=g;
	cube.couleur.b=b;
	return cube;
}

#endif