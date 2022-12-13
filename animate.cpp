#include <iostream>
#include <random>
#include <cstdlib>
#include <string>
#include "animation_sorting.hpp"

using namespace std;

int main() {
    int vector_size = 100;

    // creating random number generator
    mt19937 mt;

    // vector for data
    vector<int> data;

    mt.seed(202210);

    data.reserve(vector_size);

    for (int j = 0; j < vector_size; j++)
        data.push_back(abs((int)mt()));

    // Bubble sort animation
    vector<int> v1(data);
    bubbleSortAnimate(v1, "bubbleSortData.csv");
    cout << "Bubble sort done." << endl;

    // Quicksort animation
    vector<int> v3(data);
    quickSortAnimate(v3, "quickSortData.csv");
    cout << "Quicksort done." << endl;

    return 0;
}
