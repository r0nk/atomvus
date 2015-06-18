#ifndef ION
#define ION 1
#include "vector.h"

struct particle {
	 long double mass;
	 long double charge;
	struct vector location;
	struct vector velocity;
	struct vector accel;
};

#endif
