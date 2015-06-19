#include <stdio.h>
#include <stdlib.h>
#include "maxwells.h"
#include "particle.h"
#include "physics.h"
#include "newton.h"
#include "vector.h"
#include "callbacks.h"

struct particle ions[N_IONS];

/*nuclions serve as our 'cheat' to get around having to simulate
  the strong force, the plan is to implement the strong force later on*/
struct particle nuclion(int atom_number)
{
	atom_number++;
	struct particle e;
	printf("an: %i\n",atom_number);
	e.mass   = 1836*atom_number;
	e.charge = 50000*atom_number;
	return e;
}

struct particle electron(){
	struct particle e;
	e.mass   = 1;
	e.charge = -50000;
	return e;
}

struct particle proton(){
	struct particle p;
	p.mass   = 1836;
	p.charge = 50000;
	return p;
}

struct particle neutron(){
	struct particle p;
	p.mass   = 1836;
	p.charge = 0;
	return p;
}

void init_physics()
{
	ions[0] = proton();
	ions[1] = electron();
	ions[0].location = (struct vector) {0,0,0};
	ions[0].velocity=(struct vector){0,0,0};
	ions[1].location = (struct vector) {0,20,0};
	ions[1].velocity=(struct vector){0.15,0,0};
}

/*
void init_physics()
{
#define RANDO ((rand()%100)-50)
	int i;
	for(i=0;i<N_IONS;i++){
		switch(rand()%8){
			case 0:
				ions[i] = nuclion(rand()%9);
				break;
			default:
				ions[i] = electron();
				break;
		}
		ions[i].location = (struct vector) {RANDO,RANDO,RANDO};
		ions[i].velocity=(struct vector){0,0,0};
	}
}
*/

void dump_state()
{
	int i;
	printf("--- IONS ---\n");
	for(i=0;i<N_IONS;i++){
		printf("[%i]\n",i);
		printf("charge %Lf \n",ions[i].charge);
		printf("mass %Lf \n",ions[i].mass);
		v_print("location",ions[i].location);
		v_printe("velocity",ions[i].velocity);
		v_printe("acceleration",ions[i].accel);
	}
	printf("-----------\n");
}

void calculate_acceleration(struct particle * p,double dt)
{
	struct vector fv = {0,0,0};
	int i;
	for(i=0;i<N_IONS;i++){
		fv = v_add(fv,gravitation(ions[i],*p));
		fv = v_add(fv,coulombs(ions[i],*p));
//		fv = v_add(fv,biotsavart(ions[i],*p));
	}
	/* because f/m=a */
	fv.x/=p->mass;
	fv.y/=p->mass;
	fv.z/=p->mass;
	p->accel = v_scalar_mul(dt,fv);
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
		calculate_acceleration(&ions[i],dt);
	for(i=0;i<N_IONS;i++)
		apply_vel(&ions[i]);
	if(keys['P'])
		dump_state();
}
