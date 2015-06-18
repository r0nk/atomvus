#include <stdio.h>

#include "maxwells.h"
#include "particle.h"
#include "physics.h"
#include "newton.h"
#include "vector.h"

struct particle ions[N_IONS];

void init_physics()
{
	int i;
	for(i=0;i<N_IONS;i++){
		ions[i].location.x=0;
		ions[i].location.y=(i*5);
		ions[i].location.z=0;
		ions[i].mass=1;
		ions[i].charge=-500;
		ions[i].velocity=(struct vector){i*0.03,0,0};
	}
}

void dump_state()
{
	int i;
	printf("--- IONS ---\n");
	for(i=0;i<N_IONS;i++){
		printf("[%i]\n",i);
		v_print("location",ions[i].location);
		v_printe("velocity",ions[i].velocity);
		v_printe("acceleration",ions[i].accel);
	}
	printf("-----------\n");
}

void calculate_acceleration(struct particle * p)
{
	struct vector fv = {0,0,0};
	int i;
	for(i=0;i<N_IONS;i++){
		fv = v_add(fv,gravitation(ions[i],*p));
		fv = v_add(fv,coulombs(ions[i],*p));
		fv = v_add(fv,biotsavart(ions[i],*p));
	}
	/* because f/m=a */
	fv.x/=p->mass;
	fv.y/=p->mass;
	fv.z/=p->mass;
	p->accel = fv;
}

void apply_vel(struct particle * p)
{
	p->velocity = v_add(p->accel,p->velocity);
	p->location = v_add(p->location,p->velocity);
}

void physics_tick(double dt)
{
	int i;
	for(i=0;i<N_IONS;i++)
		calculate_acceleration(&ions[i]);
	for(i=0;i<N_IONS;i++)
		apply_vel(&ions[i]);
}
