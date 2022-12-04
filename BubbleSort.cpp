#include <iostream>
#include <vector>
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

int main(){
    vector<int> helo = {1, 3, 2, 4, 5};

    bubbleSort(helo);
    for (int i = 0; i < helo.size(); i ++){
    cout << helo[i] << endl; 
    }
}