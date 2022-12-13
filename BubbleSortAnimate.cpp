#include "animation_sorting.hpp"
#include "writer.hpp"

using namespace std;

void bubbleSortAnimate(vector<int>& lista, string archivo) {
	ofstream writer;
	writer.open("./" + archivo, ios_base::app);
	
	writeStatus(lista, writer);
	
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
				
				writeStatus(lista, writer);
				
                needNextPass = true; // Next pass still needed
            }
        }
    }
	writer.close();
}
