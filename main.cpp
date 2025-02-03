#include <iostream>
#include <vector>
#include <Neuron.hpp>
#include <Net.hpp>

int main() {
    // there has to be neural network (providing some sort of structure)
    // which has layers
    // layers have neuron


    // Net we just have to mention the layers number of the neural net 
    std::vector<unsigned> topology = {2, 3, 2};
    Net myNet = Net(topology);

    // input values is just a array [double]
    std::vector<double> inputVal = {1, 0};
    // std::vector<double> outputVal;
    // std::vector<double> resultVal;


    myNet.feedForward(inputVal);
    // myNet.backProp(outputVal);
    // myNet.getResult(resultVal);
    return 0;
}