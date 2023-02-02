#include <iostream>
#include <regex>

using namespace std;

int main() {
	string phrase;
	cin >> phrase;
	if (regex_search(phrase, regex("ss"))) {
		cout << "hiss" << endl;
	} else {
		cout << "no hiss" << endl;
	}
	return 0;
}
