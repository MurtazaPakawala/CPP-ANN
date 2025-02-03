#include <Neuron.hpp>
#include <iostream>

Neuron::Neuron(unsigned numOutputs, int my_index) {
    for (unsigned c = 0; c < numOutputs; c++) {
        // Create a connection with a random weight
        neuron_connections.push_back(Connection());
        neuron_connections.back().weight = randomWeight();
    }
    my_index = my_index;
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

void Neuron::calcSum(const Layer& prevLayer) {
    double sum = 0;
    // we also include the bias neuron
    for (unsigned n = 0; n < prevLayer.size(); n++) {
        sum+= prevLayer[n].getOutputVal() * prevLayer[n].neuron_connections[my_index].weight;
    }
}