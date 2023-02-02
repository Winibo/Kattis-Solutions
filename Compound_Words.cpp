#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;
int main() {
	string input;
	vector<string> inputlist;
	while (getline(cin, input)) {
		istringstream ss(input);
		do {
			string word;
			ss >> word;
			if (word != "") {
				inputlist.push_back(word);
			}
		} while (ss);
	}
	set<string> output;
	for (int i=0;i<inputlist.size(); ++i) {
		for (int j=0;j<inputlist.size(); ++j) {
			if (i != j) {
				output.insert(inputlist[i]+inputlist[j]);
			}
		}
	}
	for (set<string>::const_iterator i = output.begin();i != output.end(); ++i) {
		cout << *i << endl;
	}
	return 0;
}
