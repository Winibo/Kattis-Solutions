#include <iostream>

using namespace std;

int main() {
	int climb, fall, height, totalClimbs = 0, currentHeight = 0;
	cin >> climb >> fall >> height;
	while (true) {
		totalClimbs += 1;
		currentHeight += climb;
		if (currentHeight >= height) {
			break;
		}
		currentHeight -= fall;
	}
	cout << totalClimbs;
	return 0;
}
