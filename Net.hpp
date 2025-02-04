#ifndef NET_HPP
#define NET_HPP

#include <Neuron.hpp>
#include <vector>


class Net {
    public:
    Net(const std::vector<unsigned>& topology);
    void feedForward(const std::vector<double> & inputVal);
    void backProp(const std::vector<double>& outputVal);
    void getResult(std::vector<double>& resVal) const;

    private:
    std::vector<Layer> nn_graph;
    // error rmse 
    double m_error;

};
#endif 