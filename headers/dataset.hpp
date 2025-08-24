#pragma once
#include <vector>
#include <string>

using namespace std;

struct sample
{
    int label;
    vector<vector<float>> image;
};

struct dataset
{
    vector<sample> train;
    vector<sample> test;
};

dataset load_dataset(const string &train_file, const string &test_file);
