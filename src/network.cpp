#include "../include/network.hpp"

Network::Network(std::vector<int> layers, Activation activation,
		 double learning_rate) {
	this->layers = layers;
	this->activation = activation;
	this->learning_rate = learning_rate;

	for (int i = 0; i < layers.size() - 1; ++i) {
		this->weights.push_back(
		    new Matrix(layers[i + 1], layers[i], 1));
		this->biases.push_back(new Matrix(layers[i + 1], 1, 1));
	}
}

std::vector<double> Network::feed_forward(std::vector<double> inputs) {
	if (inputs.size() != this->layers[0])
		throw std::invalid_argument("invalid inputs");

	Matrix *current = (new Matrix({inputs}))->transpose();
	this->data.clear();
	this->data.push_back(new Matrix(*current));

	for (int i = 0; i < this->layers.size() - 1; ++i) {
		current = this->weights[i]
			      ->multiply(current)
			      ->add(this->biases[i])
			      ->map(this->activation.function);
		this->data.push_back(new Matrix(*current));
	}

	return current->transpose()->outputs();
}

void Network::back_propogate(std::vector<double> outputs,
			     std::vector<double> targets) {
	if (targets.size() != this->layers[this->layers.size() - 1])
		throw std::invalid_argument("invalid targets");

	Matrix *parsed = (new Matrix({outputs}))->transpose();
	Matrix *errors =
	    (new Matrix({targets}))->transpose()->add(parsed->map([](double x) {
		    return -x;
	    }));
	Matrix *gradients = parsed->map(this->activation.derivative);

	for (int i = this->layers.size() - 2; i >= 0; --i) {
		gradients =
		    gradients->hadamard(errors)->multiply(this->learning_rate);

		this->weights[i] = this->weights[i]->add(
		    gradients->multiply(this->data[i]->transpose()));
		this->biases[i] = this->biases[i]->add(gradients);

		errors = this->weights[i]->transpose()->multiply(errors);
		gradients = this->data[i]->map(this->activation.derivative);
	}
}

void Network::train(std::vector<std::vector<double>> inputs,
		    std::vector<std::vector<double>> targets, int epochs) {
	for (int i = 0; i < epochs; ++i) {
		if (epochs < 100 || i % (epochs / 100) == 0)
			std::cout << "epoch " << i << " of " << epochs
				  << std::endl;

		for (int j = 0; j < inputs.size(); ++j) {
			auto outputs = this->feed_forward(inputs[j]);
			this->back_propogate(outputs, targets[j]);
		}
	}
}
