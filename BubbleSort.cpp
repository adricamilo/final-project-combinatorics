<<<<<<< HEAD
#include "sorting.hpp"

using namespace std;

void bubbleSort(vector<int>& lista) {
    bool needNextPass = true;

    for (int k = 1; needNextPass && k < lista.size(); k++) {
        // Array may be sorted and next pass not needed
        needNextPass = false;
        for (int i = 0; i < lista.size() - k; i++) {
            if (lista[i] > lista[i + 1]) {
                // Swap list[i] with list[i + 1]
                int temp = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = temp;

                needNextPass = true; // Next pass still needed
            }
        }
    }
}
=======
#include "sorting.hpp"

using namespace std;

void bubbleSort(vector<int>& lista) {
    bool needNextPass = true;

    for (int k = 1; needNextPass && k < lista.size(); k++) {
        // Array may be sorted and next pass not needed
        needNextPass = false;
        for (int i = 0; i < lista.size() - k; i++) {
            if (lista[i] > lista[i + 1]) {
                // Swap list[i] with list[i + 1]
                int temp = lista[i];
                lista[i] = lista[i + 1];
                lista[i + 1] = temp;

                needNextPass = true; // Next pass still needed
            }
        }
    }
}
>>>>>>> eef49553d6b671f3b190d729d8760eb438aba4c5
