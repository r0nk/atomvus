#include <math.h>
#include <stdio.h>

#include "vector.h"
#include "maxwells.h"

const double ke = 8.987551E-9; /* Coulomb's constant */
const double km = 1.000000E-7; /* magnetic constant */
const double e0 = 8.854187E-12;/* permittivity of free space */
const double u0 = 1.256637E-6; /* permeability of free space */

/* F = q(E + (v X B)) */
struct vector lorentz(int q, struct vector v, struct vector E, struct vector B)
{
	struct vector F;
	F = v_add(E,v_cross(v,B));
	F = v_scalar_mul(q,F);
	return F;
}

struct vector coulombs(struct particle a, struct particle b)
{
	struct vector E = {0,0,0};
	double q = a.charge * b.charge;
	struct vector r = v_sub(b.l,a.l);
	struct vector u = v_unit(r);
	
	double mr = v_magnitude(r);
	mr*=mr;

	if(mr==0)/* we don't wana divide by 0 */
		return (struct vector){0,0,0};
	r.x = u.x/mr;
	r.y = u.y/mr;
	r.z = u.z/mr;

	E.x = ke * q * r.x;
	E.y = ke * q * r.y;
	E.z = ke * q * r.z;

	return E;
}

struct vector biotsavart(struct particle a, struct particle b)
{
	struct vector B = {0,0,0};
	double q = a.charge * b.charge;
	struct vector r = v_sub(b.l,a.l);
	struct vector u = v_unit(r);
	
	double mr = v_magnitude(r);
	mr*=mr;

	if(mr==0)/* we don't wana divide by 0 */
		return (struct vector){0,0,0};
	r.x = u.x/mr;
	r.y = u.y/mr;
	r.z = u.z/mr;

	B = v_cross( r, v_scalar_mul( q*km, b.velocity ) );

	return B;
}
