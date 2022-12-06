#include "sorting.hpp"

using namespace std;

void merge(vector<int>& list1, vector<int>& list2, vector<int>& temp) {
    int current1 = 0; // Current index in list1
    int current2 = 0; // Current index in list2
    int current3 = 0; // Current index in temp

    while (current1 < list1.size() && current2 < list2.size()) {
        if (list1[current1] < list2[current2])
            temp[current3++] = list1[current1++];
        else
            temp[current3++] = list2[current2++];
    }

    while (current1 < list1.size())
        temp[current3++] = list1[current1++];

    while (current2 < list2.size())
        temp[current3++] = list2[current2++];
}

void mergeSort(vector<int>& lista) {
    if (lista.size() <= 1)
        return;

    vector<int> firstHalf(lista.begin(), lista.begin() + lista.size() / 2);
    mergeSort(firstHalf);

    vector<int> secondHalf(lista.begin() + lista.size() / 2, lista.end());
    mergeSort(secondHalf);

    merge(firstHalf, secondHalf, lista);

}

