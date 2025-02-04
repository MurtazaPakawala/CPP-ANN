#include <Neuron.hpp>
#include <iostream>
#include <cmath>

Neuron::Neuron(unsigned numOutputs, int index_val) {
    for (unsigned c = 0; c < numOutputs; c++) {
        // Create a connection with a random weight
        neuron_connections.push_back(Connection());
        neuron_connections.back().weight = randomWeight();
    }
    std::cout << index_val << "< this is the index value of the neuron\n";
    my_index = index_val;
}

void Neuron::setOutputVal(double outputVal) {
    m_outputVal = outputVal;
}

double Neuron::getOutputVal() const {
    return m_outputVal;
}
std::ostream& operator<<(std::ostream& os, const Neuron& neuron) {
    os << "Neuron Output Value: " << neuron.m_outputVal << "\nConnections:\n";
    for (const auto& conn : neuron.neuron_connections) {
        os << "  Weight: " << conn.weight << ", Delta Weight: " << conn.deltaWeight << "\n";
    }
    return os;
}


// activation function 

double Neuron::activationFunction(double val) {
    return tanh(val);
}

double Neuron::activationFunctionDerivative(double tanh_val) {
    return 1 - tanh_val * tanh_val;
}


void Neuron::calcSum(const Layer& prevLayer) {
    std::cout << "came\n";
    double sum = 0;
    // we also include the bias neuron
    for (unsigned n = 0; n < prevLayer.size(); n++) {
        std::cout << n << " " << my_index<< "\n";
        sum+= prevLayer[n].getOutputVal() * prevLayer[n].neuron_connections[my_index].weight;
    }
    std::cout << "calculation done\n";
    // todo apply the activation and store the value 
}


