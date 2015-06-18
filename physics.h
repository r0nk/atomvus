#ifndef PHYSICS
#define PHYSICS
#include "particle.h"

#define N_IONS 3
extern struct particle ions[N_IONS];

void init_physics();
void dump_state();
void physics_tick(double dt);

#endif
