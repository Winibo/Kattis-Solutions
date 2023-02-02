#include <iostream>

using namespace std;

int main() {
	int sequencelength, currentvalue = 1;
	cin >> sequencelength;
	if (sequencelength == 1) {
		cout << 1 << endl << 1 << endl;
		return 0;
	}
	int sequence[sequencelength],
	 greedysequence[sequencelength];
	for (int i=0; i < sequencelength; i++) {
		cin >> sequence[i];
	}
	greedysequence[0] = sequence[0];
	for (int i=1; i < sequencelength; i++) {
		if (greedysequence[currentvalue-1] < sequence[i]) {
			greedysequence[currentvalue] = sequence[i];
			currentvalue += 1;
		}
	}
	cout << currentvalue << endl;
	for (int i=0; i < currentvalue; i++) {
		if (greedysequence[i] != 0 ) {
			cout << greedysequence[i] << " ";
		}
	}
	return 0;
}
