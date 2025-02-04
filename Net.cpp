#include <Net.hpp>
#include <vector>
#include <cassert>
#include <iostream>


Net::Net(const std::vector<unsigned> &topology) {
    unsigned num_layers = topology.size();

    for (unsigned curr_layer = 0; curr_layer < num_layers; curr_layer++) {
        nn_graph.push_back(Layer());

        // total neurons 
        // adding one for the bias 
        unsigned total_neurons = topology[curr_layer] + 1;
        unsigned numOutpus = curr_layer == num_layers - 1 ? 0 : topology[curr_layer + 1];
        for (unsigned neuron = 0; neuron < total_neurons; neuron++) {
            nn_graph.back().push_back(Neuron(numOutpus, neuron));
        }
    }
}
void Net::feedForward(const std::vector<double>& input) {
    // todo
    // making sure that the input size matches to the network input layer size 
    assert(input.size() == nn_graph[0].size() - 1);

    // going through all the neurons and setting the input values 
    for (unsigned i = 0; i < input.size(); i++) {
        nn_graph[0][i].setOutputVal(input[i]);
    }

    // okay so we have put the input inside the neural net
    // let move forward
    for (unsigned layer_num = 1; layer_num < nn_graph.size(); layer_num++) {
        Layer &prevLayer = nn_graph[layer_num-1];
        for (unsigned n = 0; n < nn_graph[layer_num].size() - 1; n++) {
            nn_graph[layer_num][n].calcSum(prevLayer);
        }
    }
}

void Net::backProp(const std::vector<double>& target) {
        // makign the assert stament about the last layer 
        // still we kepts the bias in the last layer for now
        assert(target.size() == nn_graph.back().size() - 1);
        // step 1 calculate the error
        auto outputLayer = nn_graph.back();
        m_error = 0;
        for (unsigned n = 0; n < outputLayer.size() - 1; n++) {
            double delta = target[n] - outputLayer[n].getOutputVal();
            m_error += delta * delta;
        }
        // taking the mean of the error and sqrt
        m_error /= (outputLayer.size() - 1);
        m_error = sqrt(m_error);

        // step 2 calculate gradient for the output layer
        for (unsigned n = 0; n < outputLayer.size() - 1; n++) {
            outputLayer[n].calculateGradient(target[n]);
        }

        // step 3 calculate gradient for all hidden layer
        for (unsigned layer_num = outputLayer.size() - 2; layer_num > 0; layer_num--) {
            auto &hidden_layer = nn_graph[layer_num];
            auto &next_layer = nn_graph[layer_num + 1];

            for (unsigned n = 0; n < hidden_layer.size(); n++) {
                hidden_layer[n].calcHiddenLayerGrad(next_layer);
            }

        }

        // step 4 updating all weights 
        for (unsigned layer_num = outputLayer.size() - 1; layer_num > 0; layer_num--) {
            auto &curr_layer = nn_graph[layer_num];
            auto &prev_layer = nn_graph[layer_num-1];
            for (unsigned n = 0; n < curr_layer.size() - 1; n++) {
                curr_layer[n].updateWeight(prev_layer);
            }
        }
}

void Net::getResult(std::vector<double>& result) const {
    // todo
}