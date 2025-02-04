#include <Neuron.hpp>
#include <iostream>
#include <cmath>

Neuron::Neuron(unsigned numOutputs, int index_val) {
    for (unsigned c = 0; c < numOutputs; c++) {
        // Create a connection with a random weight
        neuron_connections.push_back(Connection());
        neuron_connections.back().weight = randomWeight();
    }
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
    double sum = 0;
    // we also include the bias neuron
    for (unsigned n = 0; n < prevLayer.size(); n++) {
        sum+= prevLayer[n].getOutputVal() * prevLayer[n].neuron_connections[my_index].weight;
    }
    // todo apply the activation and store the value 
}


void Neuron::calcOutputGrad(double target) {
    double delta = m_outputVal - target;
    m_gradient = delta * (activationFunctionDerivative(m_outputVal));
}
double Neuron::sumDow(const Layer& next_layer) const {
    double sum = 0;
    for (unsigned n = 0; n < next_layer.size() - 1; n++) {
        sum += neuron_connections[n].weight * next_layer[n].m_gradient;
    }
    return sum;
}

void Neuron::calcHiddenLayerGrad(const Layer& next_layer) {
    double dow = sumDow(next_layer);
    m_gradient = dow * activationFunctionDerivative(m_outputVal);
}



