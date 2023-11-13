#ifndef NETWORK_HPP
#define NETWORK_HPP

#include "activation.hpp"
#include "matrix.hpp"

#include <stdexcept>
#include <vector>

class Network {
      public:
	Network(std::vector<int> layers, Activation activation,
		double learning_rate);

	std::vector<double> feed_forward(std::vector<double> inputs);
	void back_propogate(std::vector<double> outputs,
			    std::vector<double> targets);
	void train(std::vector<std::vector<double>> inputs,
		   std::vector<std::vector<double>> targets, int epochs);

      private:
	std::vector<int> layers;
	std::vector<Matrix *> weights;
	std::vector<Matrix *> biases;
	std::vector<Matrix *> data;
	Activation activation;
	double learning_rate;
};

#endif
