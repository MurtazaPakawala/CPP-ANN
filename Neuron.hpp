#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>
#include <cstdlib>

struct Connection {
    double weight;
    double deltaWeight;

};
class Neuron {
public:
    Neuron(unsigned numOutputs);

private:
    static double randomWeight() {
        return rand() / double(RAND_MAX);
    }

    double m_outputVal;
    std::vector<Connection> neuron_connections;
};
#endif