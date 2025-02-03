#include <Neuron.hpp>


Neuron::Neuron(unsigned numOutputs) {
    for (unsigned c = 0; c < numOutputs; c++) {
        // Create a connection with a random weight
        neuron_connections.push_back(Connection());
        neuron_connections.back().weight = randomWeight();
    }
}