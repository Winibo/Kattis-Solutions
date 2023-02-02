#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int atBats, basesMade = 0, validAtBats = 0, currentAtBat;
	cin >> atBats;
	for (int i=0; i < atBats; i++) {
		cin >> currentAtBat;
		if (currentAtBat != -1) {
			basesMade += currentAtBat;
			validAtBats += 1;
		}
	}
	cout << fixed << setprecision(10);
	cout << static_cast<float>(basesMade)
			/static_cast<float>(validAtBats) << endl;
	return 0;
}
