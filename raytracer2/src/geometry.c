#include "../include/geometry.h"

/* REPONSE A LA QUESTION 6 : Un produit scalaire donne la projection d'un vecteur sur un axe */

/********** FONCTIONS **********/

Point3D pointXYZ(float x, float y, float z){
	Point3D tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;

	return tmp;
}

Vector3D vectorXYZ(float x, float y, float z){
	Vector3D tmp;

	tmp.x = x;
	tmp.y = y;
	tmp.z = z;

	return tmp;
}

Vector3D vector(Point3D A, Point3D B){
 	Vector3D tmp;

 	tmp.x = (A.x)-(B.x);
 	tmp.y = (A.y)-(B.y);
 	tmp.z = (A.z)-(B.z);

 	return tmp;
}

Point3D pointPlusVector(Point3D P, Vector3D V){
	Point3D tmp;

	tmp.x = P.x + V.x;
	tmp.y = P.y + V.y;
	tmp.z = P.z + V.z;

	return tmp;
}

Vector3D addVectors(Vector3D A, Vector3D B){
	Vector3D tmp;

	tmp.x = A.x + B.x;
	tmp.y = A.y + B.y;
	tmp.z = A.z + B.z;

	return tmp;
}

Vector3D subVectors(Vector3D A, Vector3D B){
	Vector3D tmp;

	tmp.x = A.x - B.x;
	tmp.y = A.y - B.y;
	tmp.z = A.z - B.z;

	return tmp;
}

Vector3D multVector(Vector3D V, float a){
	Vector3D tmp;

	tmp.x = V.x*a;
	tmp.y = V.y*a;
	tmp.z = V.z*a;

	return tmp;
}

Vector3D divVector(Vector3D V, float a){
	Vector3D tmp;

	tmp.x = V.x/a;
	tmp.y = V.y/a;
	tmp.z = V.z/a;

	return tmp;
}

float dot(Vector3D A, Vector3D B){
	float tmp;

	tmp = A.x*B.x + A.y*B.y + A.z*B.z;

	return tmp;
}

float norm(Vector3D A){
	float tmp;

	tmp = sqrt(powl(A.x,2)+powl(A.y,2)+powl(A.z,2));

	return tmp;
}

Vector3D normalize(Vector3D A){
	Vector3D tmp;

	tmp.x = A.x/norm(A);
	tmp.y = A.y/norm(A);
	tmp.z = A.z/norm(A);

	return tmp;
}

void printVector3D(Vector3D v){
	printf("v(%f,%f,%f)\n", v.x, v.y, v.z);
}

void printPoint3D(Point3D p){
	printf("p(%f,%f,%f)\n", p.x, p.y, p.z);
}

/* Un point P est sur un rayon/une droite
ssi il existe un t appartenant à R tels que les coordonnées (x,y,z) du point P vérifient l'équation :
x(t) = x * t + Ox 
y(t) = y * t + Oy 
z(t) = z * t + Oz
Avec direction D(x,y,z) de la droite/du rayon et un point origine du rayon O(Ox, Oy, Oz) 
*/
/*
P se trouve sur une sphère si ses coordonnées vérifient :
x² + y² + z² = R² 	avec R le rayon de la sphère
Soit avec les coordonnées si dessus :
(x²+y²+z²)*t² + 2*(x * Ox + y * Oy + z * Oz)*t + (Ox² + Oy² + Oz² - R²) = 0
*/

/* Fonction qui retourne 1 si le point p est sur la droite Ov de direction v et de point de départ o passés en paramètres */
int pointOnRay(Point3D p, Point3D o, Vector3D v){
	float t1, t2, t3;

	t1 = (p.x - o.x) / v.x;
	t2 = (p.y - o.y) / v.y;
	t3 = (p.z - o.z) / v.z;

	if(t1 == t2 && t2 == t3 && t1 == t3){
		return 1;
	}
	else{
		return 0;
	}
}

/* Fonction qui retourne 1 si le point p est sur la sphère de rayon r passés en paramètres */
int pointOnSphere(Point3D p, float r){
	int c = sqrt(powl(p.x,2) + powl(p.y,2) + powl(p.z,2));

	if(powl(r,2) == c){
		return 1;
	}
	else{
		return 0;
	}
}

//http://homeomath2.imingo.net/equplan.htm

/*
P se trouve sur un cube si ses coordonnées vérifient pour chaque inéquation de la forme :
ax + by + cz + d ≥ 0 pour chacune des faces du cube (soit 6 inéquations correspondant aux équations de plan des faces)
où a, b, c sont les coordonnées du vecteur normal au plan,
d qui s'obtient à partir de ces précédentes coordonnées et celles du point de départ,
et x, y, z les coordonnées d'un point quelconque effectivement sur ce plan
*/


/*int pointOnCube(Point3D p, Point3D Pmin, Point3D Pmax){
	Vector3D diagonale = vectorXYZ(Pmin, Pmax);
	Vector3D 
	if (dot(Vector3D A, Vector3D B) == 0){

	}
}*/
