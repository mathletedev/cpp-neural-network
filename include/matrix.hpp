#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <random>
#include <stdexcept>
#include <time.h>
#include <vector>

class Matrix {
      public:
	Matrix(int rows, int cols, bool random);
	Matrix(std::vector<std::vector<double>> data);

	Matrix *multiply(Matrix *other);
	Matrix *multiply(double x);
	Matrix *add(Matrix *other);
	Matrix *hadamard(Matrix *other);
	Matrix *map(double (*f)(double));
	Matrix *transpose();

	std::vector<double> outputs();

	void display();

      private:
	int rows;
	int cols;

	std::vector<std::vector<double>> data;
};

#endif
