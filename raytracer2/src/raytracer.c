#include "../include/raytracer.h"

int intersectsSphere(Ray r, Sphere s, Intersection* I){
	float a = pow(r.dir.x,2) + pow(r.dir.y,2) + pow(r.dir.z,2);
	float b = 2*(r.dir.x*(r.O.x-s.centre.x) + r.dir.y*(r.O.y-s.centre.y) + r.dir.z*(r.O.z-s.centre.z));
	float c = pow((r.O.x-s.centre.x),2) + pow((r.O.y-s.centre.y),2) + pow((r.O.z-s.centre.z),2) - pow(s.R,2);
	float delta=pow(b,2)-4*a*c;
	if (delta<0){
		return 0;
	}
	else {
		float t1 = (-b-sqrt(delta))/2*a;
		float t2 = (-b+sqrt(delta))/2*a;
		float t;
		if (norm(multVector(r.dir,t1)) < norm(multVector(r.dir,t2)) ){
				t=t1;
		}
		else { t=t2; }
		I->intersection = pointPlusVector(r.O, multVector(r.dir,t));
		I->couleur = s.couleur;
		return 1;
	}
}


int intersectsCube(Ray r, Cube c, Intersection* I){
	float t;
	Point3D M,M2;
	I->couleur = c.couleur;
	
	//test face 1
	t=(c.Pmin.x-r.O.x)/r.dir.x;
	M = pointPlusVector(r.O, multVector(r.dir, t));
	if (M.y >= c.Pmin.y && M.y <= c.Pmax.y && M.z >= c.Pmin.z && M.z <= c.Pmax.z){
		I->intersection = M;
	}
	//test face 2
	t=(c.Pmax.x-r.O.x)/r.dir.x;
	M2 = pointPlusVector(r.O, multVector(r.dir, t));
	if (M2.y >= c.Pmin.y && M2.y <= c.Pmax.y && M2.z >= c.Pmin.z && M2.z <= c.Pmax.z){
		if (norm(vector(r.O, M2)) < norm(vector(r.O, M))){
			I->intersection = M2;
			M=M2;
		}
	}
	//test face 3
	t=(c.Pmin.y-r.O.y)/r.dir.y;
	M2 = pointPlusVector(r.O, multVector(r.dir, t));
	if (M2.x >= c.Pmin.x && M2.x <= c.Pmax.x && M2.z >= c.Pmin.z && M2.z <= c.Pmax.z){
		if (norm(vector(r.O, M2)) < norm(vector(r.O, M))){
			I->intersection = M2;
			M=M2;
		}
	}
	//test face 4
	t=(c.Pmax.y-r.O.y)/r.dir.y;
	M2 = pointPlusVector(r.O, multVector(r.dir, t));
	if (M2.x >= c.Pmin.x && M2.x <= c.Pmax.x && M2.z >= c.Pmin.z && M2.z <= c.Pmax.z){
		if (norm(vector(r.O, M2)) < norm(vector(r.O, M))){
			I->intersection = M2;
			M=M2;
		}
	}
	//test face 5
	t=(c.Pmin.z-r.O.z)/r.dir.z;
	M2 = pointPlusVector(r.O, multVector(r.dir, t));
	if (M2.y >= c.Pmin.y && M2.y <= c.Pmax.y && M2.x >= c.Pmin.x && M2.x <= c.Pmax.x){
		if (norm(vector(r.O, M2)) < norm(vector(r.O, M))){
			I->intersection = M2;
			M=M2;
		}
	}
	//test face 6
	t=(c.Pmax.z-r.O.z)/r.dir.z;
	M2 = pointPlusVector(r.O, multVector(r.dir, t));
	if (M2.y >= c.Pmin.y && M2.y <= c.Pmax.y && M2.x >= c.Pmin.x && M2.x <= c.Pmax.x){
		if (norm(vector(r.O, M2)) < norm(vector(r.O, M))){
			I->intersection = M2;
			M=M2;
		}
	}
	if (&(I->intersection)==NULL){return 0;}
	else { return 1; }

}