#include <iostream>

using namespace std;

const int needed[6] = {1, 1, 2, 2, 2, 8};
int main() {
	int contains;
	for (int i=0; i < 6;i++) {
		cin >> contains;
		cout << needed[i] - contains << ' ';
	}
	return 0;
}
