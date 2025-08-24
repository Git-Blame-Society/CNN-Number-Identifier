#include "../headers/dataset.hpp"
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;

vector<vector<float>> parse_image(ifstream &file)
{
    vector<vector<float>> img(10, vector<float>(10));
    string line;
    for (int i = 0; i < 10; i++)
    {
        if (!getline(file, line))
            throw runtime_error("Unexpected EOF in image");

        for (int j = 0; j < 10; j++)
        {
            char c = line[j];
            if (c == '.')
                img[i][j] = 0.0f;
            else if (c == '*')
                img[i][j] = 1.0f;
            else if (c == '#')
                img[i][j] = 2.0f;
            else
                img[i][j] = 0.0f;
        }
    }
    // skip empty line
    getline(file, line);
    return img;
}

vector<sample> load_file(const string &filename)
{
    ifstream file(filename);
    if (!file)
        throw runtime_error("Cannot open file: " + filename);

    vector<sample> data;
    string line;
    while (getline(file, line))
    {
        if (line.empty())
            continue;
        int label = stoi(line);
        sample s;
        s.label = label;
        s.image = parse_image(file);
        data.push_back(s);
    }
    return data;
}

dataset load_dataset(const string &train_file, const string &test_file)
{
    dataset d;
    d.train = load_file(train_file);
    d.test = load_file(test_file);
    return d;
}
