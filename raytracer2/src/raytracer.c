int intersectsSphere(Ray r, Spere s, Intersection* I){
	float a = pow(r.dir.x,2) + pow(r.dir.y,2) + pow(r.dir.z,2);
	float b = 2*(r.dir.x*(r.O.x-s.O.x) + r.dir.y*(r.O.y-s.O.y) + r.dir.z*(r.O.z-s.O.z));
	float c = pow((r.O.x-s.O.x),2) + pow((r.O.y-s.O.y),2) + pow((r.O.z-s.O.z),2) - pow(s.R,2);
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


int intersectsCube(Ray r, Spere s, Intersection* I);