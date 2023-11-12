#include "../include/matrix.hpp"

Matrix::Matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	this->data.assign(rows, std::vector<double>(cols, 0));
}

void Matrix::randomise() {
	std::uniform_real_distribution<double> urd(-1, 1);
	std::default_random_engine dre(time(NULL));

	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			this->data[i][j] = urd(dre);
	}
}

void Matrix::display() {
	for (int i = 0; i < this->rows; ++i) {
		for (int j = 0; j < this->cols; ++j)
			std::cout << this->data[i][j] << "\t\t";
		std::cout << std::endl;
	}
}
