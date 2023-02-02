#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
	string inputWord;
	vector <string> inputString;
	set <string> noDuplicates;
	cin >> inputWord;
	while (cin) {
		inputString.push_back(inputWord);
		noDuplicates.insert(inputWord);
		cin >> inputWord;
	}
	if (inputString.size() == noDuplicates.size()) {
		cout << "yes" << endl;
	} else {
		cout << "no" << endl;
	}
}
