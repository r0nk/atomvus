#include <math.h>
#include <stdio.h>

#include "vector.h"

struct vector v_cross(struct vector u, struct vector v)
{
	struct vector vec;
	vec.x = (u.y*v.z) - (u.z*v.y);
	vec.y = (u.z*v.x) - (u.x*v.z);
	vec.z = (u.x*v.y) - (u.y*v.x);
	return vec;
}

double v_dot(struct vector v1, struct vector v2)
{
	double ret=0;
	ret+=(v1.x*v2.x);
	ret+=(v1.y*v2.y);
	ret+=(v1.z*v2.z);
	return ret;
}

struct vector v_add(struct vector v1, struct vector v2)
{
	struct vector v;
	v.x = v1.x + v2.x;
	v.y = v1.y + v2.y;
	v.z = v1.z + v2.z;
	return v;
}

struct vector v_sub(struct vector v1, struct vector v2)
{
	struct vector v;
	v.x = v1.x - v2.x;
	v.y = v1.y - v2.y;
	v.z = v1.z - v2.z;
	return v;
}

struct vector v_scalar_mul(double a,struct vector v1)
{
	struct vector v;
	v.x = v1.x * a;
	v.y = v1.y * a;
	v.z = v1.z * a;
	return v;
}

struct vector v_scalar_divide(double a,struct vector v1)
{
	struct vector v;
	v.x = v1.x / a;
	v.y = v1.y / a;
	v.z = v1.z / a;
	return v;
}

/*
struct vector v_grad(double (*sf)(struct vector v),struct vector cv)
{
	struct vector v,tv = {0,0,0};
	double L = limit(0);

	v.x = sf(cv);
	v.y = sf(cv);
	v.z = sf(cv);

	cv.x+=L;
	tv.x =sf(cv);
	cv.x-=L;

	cv.y+=L;
	tv.y =sf(cv);
	cv.y-=L;

	cv.z+=L;
	tv.z =sf(cv);
	//cv.z-=L;// we dont need to.

	v = v_sub(tv,v);
	v = v_scalar_divide(L,v);
	return v;
}
*/

/*
struct vector v_del(struct vector (*vf)(struct vector v),struct vector cv)
{

	struct vector v,tv = {0,0,0};
	double L = limit(0);

	v = vf(cv);

	cv.x+=L;
	tv.x =vf(cv).x;
	cv.x-=L;

	cv.y+=L;
	tv.y =vf(cv).y;
	cv.y-=L;

	cv.z+=L;
	tv.z =vf(cv).z;
	//cv.z-=L;// we dont need to.

	v = v_sub(tv,v);
	v = v_scalar_divide(L,v);
	return v;
}
*/

/*
double v_div(struct vector (*vf)(struct vector v),struct vector cv)
{
	double ret;
	struct vector v;
	v = v_del(vf,cv);
	ret = v.x+v.y+v.z;
	return ret;
}
*/

/*
struct vector v_curl(struct vector (*vf)(struct vector v),struct vector cv)
{
	struct vector v,tv = {0,0,0};
	tv = vf(cv);
	v = v_del(vf,cv);
	tv = v_cross(v,tv);
	return v;
}
*/

struct vector v_displacement(struct vector a, struct vector b)
{
	struct vector v = {0,0,0};
	v.x = (b.x-a.x)?(b.x-a.x)/fabs(b.x-a.x):0;
	v.y = (b.y-a.y)?(b.y-a.y)/fabs(b.y-a.y):0;
	v.z = (b.z-a.z)?(b.z-a.z)/fabs(b.z-a.z):0;
	return v;
}

double v_magnitude(struct vector v)
{
	return sqrt((v.x*v.x)+(v.y*v.y)+(v.z*v.z));
}

struct vector v_unit(struct vector v)
{
	double m=v_magnitude(v);
	if(m==0)
		return (struct vector) {0,0,0};
	v.x/=m;
	v.y/=m;
	v.z/=m;
	return v;
}

void v_print(char * vname, struct vector v)
{
	printf("%s\n",vname);
	printf(" x: %f\n",v.x);
	printf(" y: %f\n",v.y);
	printf(" z: %f\n",v.z);
}

void v_printe(char * vname, struct vector v)
{
	printf("%s\n",vname);
	printf(" x: %e\n",v.x);
	printf(" y: %e\n",v.y);
	printf(" z: %e\n",v.z);
}

