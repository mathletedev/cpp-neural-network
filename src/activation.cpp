#include "../include/activation.hpp"

Activation sigmoid = {[](double x) { return 1 / (1 + std::exp(-x)); },
		      [](double x) { return x * (1 - x); }};
