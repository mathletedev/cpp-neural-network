#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <random>
#include <time.h>
#include <vector>

class Matrix {
      public:
	Matrix(int rows, int cols);

	void randomise();

	void display();

      private:
	int rows;
	int cols;

	std::vector<std::vector<double>> data;
};

#endif
