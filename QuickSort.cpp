#include "sorting.hpp"

using namespace std;

int partition(vector<int>& lista, int first, int last) {
    int pivot = lista[first]; // Choose the new first element as the pivot
    int low = first + 1; // Index for forward search
    int high = last; // Index for backward search

    while (high > low) {
        // Search forward from left
        while (low <= high && lista[low] <= pivot)
            low++;

        // Search backward from right
        while (low <= high && lista[high] > pivot)
            high--;

        // Swap two elements in the list
        if (high > low) {
            int temp = lista[high];
            lista[high] = lista[low];
            lista[low] = temp;
        }
    }

    while (high > first && lista[high] >= pivot)
        high--;

    // Swap pivot with list[high]
    if (pivot > lista[high]) {
        lista[first] = lista[high];
        lista[high] = pivot;
        return high;
    }
    else {
        return first;
    }
}

void quickSorting(vector<int>& lista, int first, int last) {
    if (last <= first)
        return;
    int pivotIndex = partition(lista, first, last);
    quickSorting(lista, first, pivotIndex - 1);
    quickSorting(lista, pivotIndex + 1, last);
}

void quickSort(vector<int>& lista) {
    quickSorting(lista, 0, lista.size() - 1);
}

