#include <iostream>
#include "../headers/dataset.hpp"

using namespace std;

int main() {
    try {
        auto data = load_dataset("dataset/train_ascii.txt",
                                 "dataset/test_ascii.txt");

        cout << "Train samples: " << data.train.size() << "\n";
        cout << "Test samples: " << data.test.size() << "\n";

        // Peek at first sample
        auto &img = data.train[0].image;
        cout << "Label: " << data.train[0].label << "\n";
        for (auto &row : img) {
            for (auto &pix : row)
                cout << (pix > 0 ? "*" : ".");
            cout << "\n";
        }
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << "\n";
    }
}
