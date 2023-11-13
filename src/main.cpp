#include <iostream>
#include <vector>

#include "../include/activation.hpp"
#include "../include/network.hpp"

int main() {
	std::vector<std::vector<double>> inputs = {
	    {0, 0}, {0, 1}, {1, 0}, {1, 1}, {0.5, 0.5}};

	std::vector<std::vector<double>> targets = {{0}, {1}, {1}, {0}, {0.5}};

	Network *network = new Network({2, 3, 1}, sigmoid, 0.5);

	network->train(inputs, targets, 10000);

	for (double i = 0; i < 1; i += 0.1) {
		for (double j = 0; j < 1; j += 0.1) {
			std::cout << int(network->feed_forward({i, j})[0] * 10)
				  << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
