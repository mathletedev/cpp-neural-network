#include <iostream>

#include "../include/matrix.hpp"

int main() {
	Matrix *matrix = new Matrix(4, 4);
	matrix->randomise();

	matrix->display();

	return 0;
}
