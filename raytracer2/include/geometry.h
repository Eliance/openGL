#ifndef geometry_h
#define geometry_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/******* STRUCTURES ET VARIABLES *******/

/* STRUCTURES */
typedef struct vec3{
	float x;
	float y;
	float z;
} Point3D, Vector3D;


/* VARIABLES */




/********** PROTOTYPES *********/

/* Fonction qui construit un point(x,y,z) */
Point3D pointXYZ(float x, float y, float z);

/* Fonction qui construit un vecteur(x,y,z) */
Vector3D vectorXYZ(float x, float y, float z);

/* Fonction qui construit le vecteur AB(B - A)*/
Vector3D vector(Point3D A, Point3D B);

/* Fonctino qui contruit la translation du point p par le vecteur v */
Point3D pointPlusVector(Point3D P, Vector3D V);

/* Fonction qui additionne deux vecteurs */
Vector3D addVectors(Vector3D A, Vector3D B);

/* Fonction qui soustrait deux vecteurs */
Vector3D subVectors(Vector3D A, Vector3D B);

/* Fonction qui multiplie 1 vecteur par un flottant */
Vector3D multVector(Vector3D V, float a);

/* Fonction qui divise 1 vecteur par un flottant */
Vector3D divVector(Vector3D V, float a);

/* Fonction qui calcule le produit scalaire de deux vecteurs */
float dot(Vector3D A, Vector3D B);

/* Fonction qui calcule la norme d'un vecteur */
float norm(Vector3D A);

/* Fonction qui calcule et renvoie le vecteur normalisé passé en paramètre */
Vector3D normalize(Vector3D A);

/* Fonction qui affiche le contenu du vecteur passé en paramètre */
void printVector3D(Vector3D v);

/* Fonction qui affiche le contenu du point passé en paramètre */
void printPoint3D(Point3D p);

/* Fonction qui retourne 1 si le point p est sur la droite Ov de direction v et de point de départ o passés en paramètres */
int pointOnRay(Point3D p, Point3D o, Vector3D v);



#endif