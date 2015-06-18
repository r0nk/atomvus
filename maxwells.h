#ifndef MAXWELLS
#define MAXWELLS

#include "vector.h"
#include "particle.h"


struct vector lorentz(int q, struct vector v, struct vector E, struct vector B);
struct vector coulombs(struct particle p1, struct particle p2);
struct vector biotsavart(struct particle p1, struct particle p2);

#endif
