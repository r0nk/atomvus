#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#include "newton.h"
#include "particle.h"
#include "vector.h"

const double G = 6.673E-11; /* gravitational constant */

struct vector gravitation (struct particle a, struct particle b)
{
	struct vector F = {0,0,0};
	double m = a.mass * b.mass;
	struct vector u = v_displacement(a.location,b.location);
	struct vector r = v_sub(b.location,a.location);
	F.x =  -G * (m / (r.x)?fabs(r.x*r.x):1 ) * u.x;
	F.y =  -G * (m / (r.y)?fabs(r.y*r.y):1 ) * u.y;
	F.z =  -G * (m / (r.z)?fabs(r.z*r.z):1 ) * u.z;
	return F;
}
