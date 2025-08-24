#include "../headers/conv2d.hpp"
#include <cstdlib>

conv2d::conv2d(int in_ch, int out_ch, int k) : in_channels(in_ch), out_channels(out_ch), kernel_size(k)
{
    default_random_engine eng(rand());
    uniform_real_distribution<float> dist(-0.1f, 0.1f);

    kernels.resize(out_channels, vector<vector<vector<float>>>(in_channels, vector<vector<float>>(kernel_size, vector<float>(kernel_size))));

    for (int o = 0; o < out_channels; o++)
    {
        for (int i = 0; i < in_channels; i++)
        {
            for (int x = 0; x < kernel_size; x++)
            {
                for (int y = 0; y < kernel_size; y++)
                {
                    kernels[0][i][x][y] = dist(eng);
                }
            }
        }
    }
    biases.resize(out_channels, 0.0f);
}

vector<vector<vector<float>>> conv2d::forward(const vector<vector<vector<float>>> &input)
{
    int H = input[0].size();
    int W = input[0][0].size();
    int outH = H - kernel_size + 1;
    int outW = W - kernel_size + 1;

    vector<vector<vector<float>>> output(out_channels, vector<vector<float>>(outH, vector<float>(outW, 0.0f)));

    for (int o = 0; o < out_channels; o++)
    {
        for (int i = 0; i < in_channels; i++)
        {
            for (int x = 0; x < outH; x++)
            {
                for (int y = 0; y < outW; y++)
                {
                    float sum = 0.0f;
                    for (int kx = 0; kx < kernel_size; kx++)
                    {
                        for (int ky = 0; ky < kernel_size; ky++)
                        {
                            sum += input[i][x + kx][y + ky] * kernels[o][i][kx][ky];
                        }
                    }
                    output[o][x][y] += sum;
                }
            }
        }
        for (int x = 0; x < outH; x++)
        {
            for (int y = 0; y < outW; y++)
            {
                output[o][x][y] += biases[o];
            }
        }
    }
    return output;
}
