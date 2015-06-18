#ifndef VECTOR
#define VECTOR

struct vector {
	double x,y,z;
};

struct vector v_unit(struct vector v);

double v_magnitude(struct vector v);
struct vector v_cross (struct vector v1, struct vector v2);
double v_dot(struct vector v1, struct vector v2);
struct vector v_add(struct vector v1, struct vector v2);
struct vector v_sub(struct vector v1, struct vector v2);
struct vector v_scalar_mul(double a,struct vector F);
struct vector v_scalar_divide(double a,struct vector F);

struct vector v_grad(double (*sf)(struct vector v),struct vector cv);
double v_div(struct vector (*vf)(struct vector v),struct vector v);
struct vector v_curl(struct vector (*vf)(struct vector v),struct vector cv);

struct vector v_displacement(struct vector a, struct vector b);/* radius */

void v_print(char * vname, struct vector v);
void v_printe(char * vname, struct vector v);

#endif
