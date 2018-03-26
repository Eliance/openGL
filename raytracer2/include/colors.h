#ifndef colors_h
#define colors_h

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

/******* STRUCTURES ET VARIABLES *******/

/* STRUCTURES */

typedef struct Color3f{
	float r;
	float g;
	float b;
} Color3f;

/* VARIABLES */




/********** PROTOTYPES *********/

/* Fonction somme deux couleurs */
Color3f addColors(Color3f c1, Color3f c2);

/* Fonction qui soustrait deux couleurs */
Color3f subColors(Color3f c1, Color3f c2);

/* Fonction qui multiplie deux couleurs */
Color3f multColors(Color3f c1, Color3f c2);

/* Fonction qui divise deux couleurs */
Color3f divColors(Color3f c1, Color3f c2);

/* Fonction qui multiplie une couleur par un scalaire */
Color3f multColor(Color3f c, float a);

/* Fonction qui divise une couleur par un scalaire */
Color3f divColor(Color3f c, float a);

#endif