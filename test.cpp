#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include "sorting.hpp"

using namespace std;

int main() {
    int number_of_tests = 100;
    int vector_size = 10000;

    // creating random number generator
    mt19937 mt;

    // vector for data
    vector<int> data;

    for (int i = 0; i < number_of_tests; i++) {
        // creating this test's data
        mt.seed(time(nullptr));
        data.clear();
        data.reserve(vector_size);
        for (int j = 0; j < vector_size; j++)
            data.push_back(mt());

        // Bubble sort test
        vector<int> v1(data);
        auto start1 = chrono::system_clock::now();
        bubbleSort(v1);
        auto end1 = chrono::system_clock::now();

        // Merge sort test
        vector<int> v2(data);
        auto start2 = chrono::system_clock::now();
        mergeSort(v2);
        auto end2 = chrono::system_clock::now();

        // Quicksort test
        vector<int> v3(data);
        auto start3 = chrono::system_clock::now();
        quickSort(v3);
        auto end3 = chrono::system_clock::now();

        vector<long long> times;

        times.push_back((long long)chrono::duration_cast<chrono::milliseconds>(end1 - start1).count());
        times.push_back((long long)chrono::duration_cast<chrono::milliseconds>(end2 - start2).count());
        times.push_back((long long)chrono::duration_cast<chrono::milliseconds>(end3 - start3).count());

        ofstream WriteResults;
        WriteResults.open("./results.txt", ios_base::app);
        for (int k = 0; k < 2; k++)
            WriteResults << to_string(times[k]) << ",";
        WriteResults << to_string(times[2]) << endl;
        WriteResults.close();

        cout << "Test " << i + 1 << "/" << number_of_tests << " done." << endl;
    }

    return 0;
}
