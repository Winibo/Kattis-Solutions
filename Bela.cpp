#include <iostream>
#include <algorithm>

using namespace std;

const char NONDOM[8] = {11, 4, 3, 2, 10, 0, 0, 0};
const char DOM[8] = {11, 4, 3, 20, 10, 14, 0, 0};

int main() {
	int hands, totalPoints = 0;
	char dominantSuit, currentValue, suit, *location;
	char ARRAYPOS[8] = {'A', 'K', 'Q', 'J', 'T', '9', '8', '7'};
	cin >> hands >> dominantSuit;
	for (int i=0; i < hands*4;i++) {
		cin >> currentValue >> suit;

		location = find(ARRAYPOS, ARRAYPOS+8, currentValue);

		if (suit == dominantSuit) {
			totalPoints += DOM[distance(ARRAYPOS, location)];
		} else {
			totalPoints += NONDOM[distance(ARRAYPOS, location)];
		}
	}
	cout << totalPoints;

	return 0;
}
