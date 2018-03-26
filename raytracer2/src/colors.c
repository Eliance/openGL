#include "../include/colors.h"

Color3f addColors(Color3f c1, Color3f c2){
	Color3f tmp;

	tmp.r = c1.r + c2.r;
	tmp.g = c1.g + c2.g;
	tmp.b = c1.b + c2.b;

	return tmp;
}

Color3f subColors(Color3f c1, Color3f c2){
	Color3f tmp;

	tmp.r = c1.r - c2.r;
	tmp.g = c1.g - c2.g;
	tmp.b = c1.b - c2.b;

	return tmp;
}

Color3f multColors(Color3f c1, Color3f c2){
	Color3f tmp;

	tmp.r = c1.r * c2.r;
	tmp.g = c1.g * c2.g;
	tmp.b = c1.b * c2.b;

	return tmp;
}

Color3f divColors(Color3f c1, Color3f c2){
	Color3f tmp;

	tmp.r = c1.r / c2.r;
	tmp.g = c1.g / c2.g;
	tmp.b = c1.b / c2.b;

	return tmp;
}

Color3f multColor(Color3f c, float a){
	Color3f tmp;

	tmp.r = c.r * a;
	tmp.g = c.g * a;
	tmp.b = c.b * a;

	return tmp;
}

Color3f divColor(Color3f c, float a){
	Color3f tmp;

	tmp.r = c.r / a;
	tmp.g = c.g / a;
	tmp.b = c.b / a;

	return tmp;
}



