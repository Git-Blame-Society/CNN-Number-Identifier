#pragma once
#include <random>
#include "layer.hpp"

using namespace std;

class conv2d : public layer
{
    int in_channels;
    int out_channels;
    int kernel_size;
    vector<vector<vector<vector<float>>>> kernel;
    vector<float> biases;

public:
    conv2d(int in_channels, int out_channels, int kernel_size);
    vector<vector<vector<float>>> forward(const vector<vector<vector<float>>> &input) override;
};
