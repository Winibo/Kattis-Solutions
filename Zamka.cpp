#include <iostream>
using namespace std;

int main() {
	int lowerBound, upperBound, target, digitsum = 0;
	int currentDivisor = 10, currentSlope, currentValue;
	cin >> lowerBound >> upperBound >> target;
	currentSlope = lowerBound / 9;
	//Calculate lowest value that meets conditions
	//Only need to check possible answers that we get from the formula
	//target + 9n for all n, as only numbers found in this formula
	//are ones that could sum to the answer
	while(true) {
		currentValue = target + (currentSlope*9);
		digitsum = 0;
		while (currentValue > 0) {
			digitsum += currentValue % currentDivisor;
			currentValue -= currentValue % currentDivisor;
			currentValue = currentValue / currentDivisor;
		}
		if (digitsum == target && (target + currentSlope*9 >= lowerBound)) {
			break;
		}
		currentSlope += 1;
	}
	cout << target + (currentSlope*9) << endl;
	currentSlope = upperBound / 9;
	while(true) {
		currentValue = target + (currentSlope*9);
		digitsum = 0;
		while (currentValue > 0) {
			digitsum += currentValue % currentDivisor;
			currentValue -= currentValue % currentDivisor;
			currentValue = currentValue / currentDivisor;
		}
		if (digitsum == target && (target + currentSlope*9 <= upperBound)) {
			break;
		}
		currentSlope -= 1;
	}
	cout << target + (currentSlope*9) << endl;
	return 0;
}
