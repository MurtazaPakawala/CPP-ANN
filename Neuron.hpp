#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>
#include <cstdlib>
#include <iostream>

struct Connection {
    double weight;
    double deltaWeight;

};
class Neuron {
public:
    Neuron(unsigned numOutputs);

    // just for printing 
    void setOutputVal(double outputVal);
    double getOutputVal() const;
    friend std::ostream& operator<<(std::ostream& os, const Neuron &neuron);

private:
    static double randomWeight() {
        return rand() / double(RAND_MAX);
    }

    double m_outputVal;
    std::vector<Connection> neuron_connections;
};
#endif