#include <iostream>
#include "../headers/conv2d.hpp"

using namespace std;

int main() {
    // Input: single-channel 10x10
    std::vector<std::vector<std::vector<float>>> img(1,
        std::vector<std::vector<float>>(10, std::vector<float>(10, 1.0f)));

    conv2d conv(1, 2, 3); // 1 input channel, 2 output channels, 3x3 kernel

    auto out = conv.forward(img);

    std::cout << "Conv output shape: "
              << out.size() << "x"
              << out[0].size() << "x"
              << out[0][0].size() << "\n";
}
