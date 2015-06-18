#ifndef GAME
#define GAME 1
#include "vector.h"
#include "poly.h"
#include "particle.h"

int init_game();

struct entity 
{
	struct model model;
	struct particle particle;
};

#endif
