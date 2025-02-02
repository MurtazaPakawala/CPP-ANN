#ifndef NET_HPP
#define NET_HPP

#include <Neuron.hpp>
#include <vector>


typedef std::vector<Neuron> Layers;
class Net {
    public:
    Net(const std::vector<unsigned>& topology);
    void feedForward(const std::vector<double> & inputVal);
    void backProp(const std::vector<double>& outputVal);
    void getResult(std::vector<double>& resVal) const;


    private:
    std::vector<Layers> nn_graph;

};
#endif 