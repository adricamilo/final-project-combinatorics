#include "writer.hpp"

using namespace std;

void writeStatus(vector<int>& lista, ofstream& writer) {
	for (int i = 0; i < lista.size(); i++) {
		writer << lista[i];
		if (i != lista.size() - 1)
			writer << ", ";
		else
			writer << endl;
	}
}