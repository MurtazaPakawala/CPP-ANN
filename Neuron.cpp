#include <Neuron.hpp>


Neuron::Neuron(unsigned numOutpus) {
    for (unsigned c = 0; c < numOutpus; c++) {
        // make a connection
        neuron_connections.push_back(Connection());
        // the connection needs to be a random value in start
        neuron_connections.back().weight = randomWeight();
    }
}