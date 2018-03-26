typedef struct Vec3{
    float x,y,z;
}Point3D,Vector3D;

Point3D pointXYZ(float x, float y, float z);

Vector3D vectorXYZ(float x, float y, float z);

Vector3D vector(Point3D A, Point3D B);

Point3D pointPlusVector(Point3D P, Vector3D V);

Vector3D addVectors(Vector3D A, Vector3D B);

Vector3D subVectors(Vector3D A, Vector3D B);

Vector3D multVector(Vector3D V, float a);

Vector3D divVector(Vector3D V, float a);

float dot(Vector3D A, Vector3D B);

float norm(Vector3D A);

Vector3D normalize(Vector3D A);

void printVector3D(Vector3D v);

void printPoint3D(Point3D p);




