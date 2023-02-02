#include <iostream>

using namespace std;

int main() {
	int left = 1, right = 1000, guess;
	string response;
	for (int i = 0; i < 10; i++) {
		guess = (left+right)/2;
		cout << guess << endl << flush;
		if (i < 9) {
			cin >> response;
			if (response == "lower") {
				right = guess;
			} else if (response == "higher") {
				left = guess+1;
			} else if (response == "correct") {
				break;
			}
		}
	}
	return 0;
}
