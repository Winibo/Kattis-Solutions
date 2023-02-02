#include <iostream>
#include <limits>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;
// TODO: A little more cleverness might make it cheaty enough to pass
// Works to solve the problem, but is too slow to pass test cases given.
int add_next(int *weightList, int weights, int currentTotal = 0, int loop=0) {
	int recursivebest = 0;
	currentTotal += weightList[loop];
	int best = currentTotal;
	for (int j=loop+1;j < weights;j++) {
		recursivebest = add_next(weightList, weights, currentTotal, j);
		loop += 1;
		if ((abs(1000 - recursivebest) < abs(1000 - best)) ||
			(abs(1000 - recursivebest) == abs(1000 - best) &&
			 recursivebest > best)) {
			best = recursivebest;
		}
		if (recursivebest > 1000) {
			break;
		}
		if (best == 1000) {
			break;
		}
	}
	return best;
}


int main() {
	int weights, result, answer, max;
	cin >> weights;
	int weightList[weights];
	for (int i=0; i < weights; i++) {
		cin >> weightList[i];
		if (weightList[i] == 1000) {
			cout << 1000 << endl;
			return 0;
		}
	}
	max = accumulate(weightList, weightList+weights, 0);
	if (max < 1000) {
		cout << max;
		return 0;
	} else if (all_of(weightList, weightList+weights, [max](int i) {return i > (max-1000)*2;})) {
		cout << max;
		return 0;
	}
	for (int i=0;i < weights; i++) {
		result = add_next(weightList, weights, 0, i);
		if ((abs(1000 - result) < abs(1000 - answer)) ||
			(abs(1000 - result) == abs(1000 - answer) &&
			result > answer)) {
			answer = result;
		}
	}
	cout << answer << endl;
	return 0;
}
