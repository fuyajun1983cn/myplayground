#ifndef MATH_3D_H
#define MATH_3D_H
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>


//usefull constants
#define M3D_PI (3.14159265358979323846)

typedef glm::vec2 FYJVector2D;
typedef glm::vec3 FYJVector3D;
typedef glm::vec4 FYJVector4D;

//#define FYJVectorNormalize(x)  glm::normalize(x)

inline FYJVector3D FYJVectorNormalize(FYJVector3D d)
{
	FYJVector3D temp;
	float c = sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
	temp.x = (float)d.x/c;
	temp.y = (float)d.y/c;
	temp.z = (float)d.z/c;

	return temp;
}

inline bool FYJVectorCloseEnough(const float fCandidate, const float fCompare, const float fEpsilon)
    {
    return (fabs(fCandidate - fCompare) < fEpsilon);
    }
    
inline bool FYJVectorCloseEnough(const double dCandidate, const double dCompare, const double dEpsilon)
    {
    return (fabs(dCandidate - dCompare) < dEpsilon);
    }    


#endif
