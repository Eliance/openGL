#include "geometry.h"
#include "colors.h"

typedef struct Ray{
	Point3D O;
	Vector3D dir;
}Ray;

typedef struct Intersection{
	Point3D intersection;
	Color3f colorsection;
}Intersection

Ray createRay(float Ox, float Oy, float Oz, float Vx, float Vy, float Vz){
	Ray ray;
	ray.O = pointXYZ(Ox,Oy,Oz);
	ray.dir = vectorXYZ(Vx,Vy,Vz);
	return ray;
}

int intersectsSphere(Ray r, Spere s, Intersection* I);

int intersectsCube(Ray r, Cube s, Intersection* I);