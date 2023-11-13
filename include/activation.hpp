#ifndef ACTIVATION_HPP
#define ACTIVATION_HPP

#include <cmath>

struct Activation {
	double (*function)(double);
	double (*derivative)(double);
};

extern Activation sigmoid;

#endif
