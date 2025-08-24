// creating a base layer so that all layers have the same structure

#pragma once
#include <vector>

using namespace std;

class layer
{
public:
    virtual vector<vector<vector<float>>> forward(const vector<vector<vector<float>>> &input) = 0;

    virtual ~layer() = default;
};
