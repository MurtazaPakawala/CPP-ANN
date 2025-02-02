#include <Net.hpp>
#include <vector>



Net::Net(const std::vector<unsigned> &topology) {
    unsigned num_layers = topology.size();

    for (unsigned curr_layer = 0; curr_layer < num_layers; curr_layer++) {
        nn_graph.push_back(Layers());

        // total neurons 
        // adding one for the bias 
        unsigned total_neurons = topology[curr_layer] + 1;

        for (unsigned neuron = 0; neuron < total_neurons; neuron++) {
            nn_graph.back().push_back(Neuron());
        }
    }
}