#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& lista) {
    quickSort(lista, 0, lista.size() - 1)
}

void quickSort(vector<int>& lista, int first, int last) {
    if (last >= first)
        return;
    int pivotIndex = partition(list, first, last);
    quickSort(list, first, pivotIndex - 1);
    quickSort(list, pivotIndex + 1, last);
}

int partition(vector<int>& lista, int first, int last) {
    int pivot = list[first]; // Choose the new first element as the pivot
    int low = first + 1; // Index for forward search
    int high = last; // Index for backward search

    while (high > low) {
        // Search forward from left
        while (low <= high && list[low] <= pivot)
            low++;

        // Search backward from right
        while (low <= high && list[high] > pivot)
            high--;

        // Swap two elements in the list
        if (high > low) {
            int temp = list[high];
            list[high] = list[low];
            list[low] = temp;
        }
    }

    while (high > first && list[high] >= pivot)
        high--;

    // Swap pivot with list[high]
    if (pivot > list[high]) {
        list[first] = list[high];
        list[high] = pivot;
        return high;
    }
    else {
        return first;
    }
}

int main(){
    vector<int> helo = {1, 3, 2, 4, 5, 5, 8,9,10,522,45}

    quickSort(helo);
    for (int i = 0; i < helo.size(); i ++){
        cout << helo[i] << endl; 
    }
}
