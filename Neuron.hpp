#ifndef NEURON_HPP
#define NEURON_HPP
#include <vector>
#include <cstdlib>
#include <iostream>
class Neuron;
typedef std::vector<Neuron> Layer;
struct Connection {
    double weight;
    double deltaWeight;

};
class Neuron {
public:
    Neuron(unsigned numOutputs, int my_index);

    // just for printing 
    void setOutputVal(double outputVal);
    double getOutputVal() const;
    void calcSum(const Layer &prevLayer);
    void calcOutputGrad(double target);
    void calcHiddenLayerGrad(const Layer& next_layer);
    void updateWeight(Layer& prev_layer);
    double sumDow(const Layer &next_layer) const;
    friend std::ostream& operator<<(std::ostream& os, const Neuron &neuron);

private:
    // making the activation function
    static double activationFunction(double x);
    static double activationFunctionDerivative(double x);
    static double randomWeight() {
        return rand() / double(RAND_MAX);
    }

    double m_outputVal;
    std::vector<Connection> neuron_connections;
    int my_index;
    double m_gradient;

    // learning params
    static double eta;
    static double alpha;

};


#endif