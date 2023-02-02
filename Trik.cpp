#include <iostream>
#include <string>

using namespace std;

int main() {
	int eof;
	bool cupA = true, cupB = false, cupC = false, storage;
	string swaps;
	char currentSwap;
	getline(cin, swaps);
	for (int i=0; i < swaps.length(); i++) {
		currentSwap = swaps[i];
		if (currentSwap == 'A') {
			storage = cupA;
			cupA = cupB;
			cupB = storage;
		} else if (currentSwap == 'B') {
			storage = cupB;
			cupB = cupC;
			cupC = storage;
		} else {
			storage = cupA;
			cupA = cupC;
			cupC = storage;
		}
	}
	if (cupA) {
		cout << 1 << endl;
	} else if (cupB) {
		cout << 2 << endl;
	} else {
		cout << 3 << endl;
	}
	return 0;
}
