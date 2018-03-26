#include <stdio.h>
#include <math.h>
#include <geometry.h>

Point3D pointXYZ(float x, float y, float z){
    Point3D point;
    point.x=x;
    point.y=y;
    point.z=z;
    return  point;
}

Vector3D vectorXYZ(float x, float y, float z){
    Vector3D vec;
    vec.x=x;
    vec.y=y;
    vec.z=z;
    return  vec;
}

Vector3D vector(Point3D A, Point3D B){
    Vector3D vec;
    vec.x=B.x - A.x;
    vec.y=B.y - A.y;
    vec.z=B.z - A.z;
    return vec;
}

Point3D pointPlusVector(Point3D P, Vector3D V){
    Point3D point;
    point.x=P.x + V.x;
    point.y=P.y + V.y;
    point.z=P.z + V.z;
    return point;
}


Vector3D addVectors(Vector3D A, Vector3D B){
    Vector3D vec;
    vec.x=B.x + A.x;
    vec.y=B.y + A.y;
    vec.z=B.z + A.z;
    return vec;
}

Vector3D subVectors(Vector3D A, Vector3D B){
    Vector3D vec;
    vec.x=A.x - B.x;
    vec.y=A.y - B.y;
    vec.z=A.z - B.z;
    return vec;
}

Vector3D multVector(Vector3D V, float a){
    V.x=a*V.x;
    V.y=a*V.y;
    V.z=a*V.z;
    return V;
}

Vector3D divVector(Vector3D V, float a){
    V.x=V.x/a;
    V.y=V.y/a;
    V.z=V.z/a;
    return V;
}

float dot(Vector3D A, Vector3D B){
    return A.x*B.x + A.y*B.y + A.z*B.z;
}

float norm(Vector3D A){
    double X=A.x, Y=A.y, Z=A.z;
    double a=pow(X,2) + pow(Y,2) + pow(Z,2);
    a=pow(a, 1/2);
    return a;
}

/*Vector3D normalize(Vector3D A){
    return divVector(A, norm(A));
}*/

void printVector3D(Vector3D v){
	printf("(%f, %f, %f)",v.x,v.y,v.z);
}

void printPoint3D(Point3D p){
	printf("(%f, %f, %f)",p.x,p.y,p.z);
}



