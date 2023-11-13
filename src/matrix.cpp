#include "../include/matrix.hpp"

Matrix::Matrix(int rows, int cols, bool random = 0) {
	this->rows = rows;
	this->cols = cols;

	this->data.assign(rows, std::vector<double>(cols, 0));

	if (!random)
		return;

	std::uniform_real_distribution<double> urd(-1, 1);
	std::default_random_engine dre(time(NULL));

	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j)
			this->data[i][j] = urd(dre);
	}
}

Matrix::Matrix(std::vector<std::vector<double>> data) {
	this->rows = data.size();
	this->cols = data[0].size();
	this->data = data;
}

Matrix *Matrix::multiply(Matrix *other) {
	if (this->cols != other->rows)
		throw std::invalid_argument("incorrect dimensions");

	Matrix *res = new Matrix(this->rows, other->cols);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < other->cols; ++j) {
			double sum = 0;
			for (int k = 0; k < this->cols; ++k)
				sum += this->data[i][k] * other->data[k][j];

			res->data[i][j] = sum;
		}
	}

	return res;
}

Matrix *Matrix::multiply(double x) {
	Matrix *res = new Matrix(this->rows, this->cols);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			res->data[i][j] = this->data[i][j] * x;
	}

	return res;
}

Matrix *Matrix::add(Matrix *other) {
	if (this->rows != other->rows || this->cols != other->cols)
		throw std::invalid_argument("incorrect dimensions");

	Matrix *res = new Matrix(this->rows, this->cols);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			res->data[i][j] = this->data[i][j] + other->data[i][j];
	}

	return res;
}

Matrix *Matrix::hadamard(Matrix *other) {
	if (this->rows != other->rows || this->cols != other->cols)
		throw std::invalid_argument("incorrect dimensions");

	Matrix *res = new Matrix(this->rows, this->cols);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			res->data[i][j] = this->data[i][j] * other->data[i][j];
	}

	return res;
}

Matrix *Matrix::map(double (*f)(double)) {
	Matrix *res = new Matrix(this->rows, this->cols);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			res->data[i][j] = f(this->data[i][j]);
	}

	return res;
}

Matrix *Matrix::transpose() {
	Matrix *res = new Matrix(this->cols, this->rows);

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			res->data[j][i] = this->data[i][j];
	}

	return res;
}

std::vector<double> Matrix::outputs() { return this->data[0]; }

void Matrix::display() {
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			std::cout << this->data[i][j] << "\t\t";
		std::cout << std::endl;
	}
}
