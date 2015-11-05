#ifndef CMATHS_H
#define CMATHS_H

#include <math.h>

//////////////////////////////////////
//The Vector3D Struct
//////////////////////////////////////
typedef struct Vector3D					// expanded 3D vector struct
{
    Vector3D() {}	// constructor
    Vector3D (float new_x, float new_y, float new_z) // initialize constructor
    {x = new_x; y = new_y; z = new_z;}
    // overload + operator so that we easier can add vectors
    Vector3D operator+(Vector3D vVector) {return Vector3D(vVector.x+x, vVector.y+y, vVector.z+z);}
    // overload - operator that we easier can subtract vectors
    Vector3D operator-(Vector3D vVector) {return Vector3D(x-vVector.x, y-vVector.y, z-vVector.z);}
    // overload * operator that we easier can multiply by scalars
    Vector3D operator*(float number)	 {return Vector3D(x*number, y*number, z*number);}
    // overload / operator that we easier can divide by a scalar
    Vector3D operator/(float number)	 {return Vector3D(x/number, y/number, z/number);}

    float x, y, z;						// 3D vector coordinates
}Vector3D;

#endif // CMATHS_H
