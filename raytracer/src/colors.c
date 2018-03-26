#include <colors.h>
#include <math.h>
#include <stdio.h>

Color3f addColors(Color3f c1, Color3f c2){
    Color3f color;
    color.r = c1.r + c2.r;
    color.v = c1.v + c2.v;
    color.b = c1.b + c2.b;
    return color;
}


Color3f subColors(Color3f c1, Color3f c2){
    Color3f color;
    color.r = c1.r - c2.r;
    color.v = c1.v - c2.v;
    color.b = c1.b - c2.b;
    return color;
}

Color3f multColors(Color3f c1, Color3f c2){
    Color3f color;
    color.r = c1.r * c2.r;
    color.v = c1.v * c2.v;
    color.b = c1.b * c2.b;
    return color;
}

Color3f divColors(Color3f c1, Color3f c2){
    Color3f color;
    if (c2.r==0.0 || c2.v==0.0 || c2.b==0.0){
	printf("Error, division par 0"); 
	return color;
    }
    color.r = c1.r / c2.r;
    color.v = c1.v / c2.v;
    color.b = c1.b / c2.b;
    return color;
}

Color3f multColor(Color3f c1, float a){
    Color3f color;
    color.r = c1.r*a;
    color.v = c1.v*a;
    color.b = c1.b*a;
    return color;
}

Color3f divColor(Color3f c1, float a){
    Color3f color;
    if (a==0.0){
	printf("Error, division par 0"); 
	return color;
    }

    color.r = c1.r/a;
    color.v = c1.v/a;
    color.b = c1.b/a;
    return color;
}








