#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "geometry.h"
#include "colors.h"
//#include "../include/shape.h"

typedef struct Ray{
	Point3D O;
	Vector3D dir;
}Ray;

typedef struct Intersection{	//un champ de position et un champ de couleurs
	Point3D intersection;
	Color3f couleur;
}Intersection;

Ray createRay(float Ox, float Oy, float Oz, float Vx, float Vy, float Vz){
	Ray ray;
	ray.O = pointXYZ(Ox,Oy,Oz);
	ray.dir = vectorXYZ(Vx,Vy,Vz);
	return ray;
}

/*int intersectsSphere(Ray r, Sphere s, Intersection* I);

int intersectsCube(Ray r, Cube s, Intersection* I);*/

#endif