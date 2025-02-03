#include <Net.hpp>
#include <vector>
#include <cassert>
#include <iostream>


Net::Net(const std::vector<unsigned> &topology) {
    unsigned num_layers = topology.size();

    for (unsigned curr_layer = 0; curr_layer < num_layers; curr_layer++) {
        nn_graph.push_back(Layers());

        // total neurons 
        // adding one for the bias 
        unsigned total_neurons = topology[curr_layer] + 1;
        unsigned numOutpus = curr_layer == num_layers - 1 ? 0 : topology[curr_layer + 1];
        for (unsigned neuron = 0; neuron < total_neurons; neuron++) {
            nn_graph.back().push_back(Neuron(numOutpus));
            std::cout << "hey! created a neuron\n";
        }
    }
}
void Net::feedForward(const std::vector<double>& input) {
    // todo
    // making sure that the input size matches to the network input layer size 
    assert(input.size() == nn_graph[0].size() - 1);

    // going through all the neurons and setting the input values 
    for (unsigned i = 0; i < input.size(); i++) {
        nn_graph[0][i] = input[i];
        std::cout << nn_graph[0][i] << "\n";
        // just checking this is correct or not 
    }
}

void Net::backProp(const std::vector<double>& target) {
    // todo
}

void Net::getResult(std::vector<double>& result) const {
    // todo
}