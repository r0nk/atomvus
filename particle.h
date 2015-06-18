#ifndef ION
#define ION 1
#include "vector.h"

struct particle {
	double mass;
	double charge;
	struct vector l;/* location */
	struct vector velocity;
	struct vector accel;
};

#endif
