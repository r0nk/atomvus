#ifndef POLY
#define POLY

#include "vector.h"

typedef struct vector point;

struct vertice { 
	struct vector p;/*position*/
	struct vector n;/*normal*/
	struct vector c;/*color*/
};

struct polygon{
	struct vertice v[3];
};

struct model{
	unsigned int cardinality; 
	struct polygon *poly;
};

#endif
