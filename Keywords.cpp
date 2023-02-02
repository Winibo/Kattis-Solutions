#include <iostream>
#include <regex>
#include <set>
#include <string>

using namespace std;

int main() {
	int keywords, uniquekeywords = 0;
	cin >> keywords;
	cin.ignore();
	string unfiltered[keywords];
	set <string> filtered;
	for (int i=0; i < keywords; i++) getline(cin, unfiltered[i]);
	for (int i=0; i < keywords; i++) {
		transform(unfiltered[i].begin(), unfiltered[i].end(), unfiltered[i].begin(), ::toupper);
		filtered.insert(regex_replace(unfiltered[i], regex("-"), " "));
	}
	for (auto itr=filtered.begin(); itr != filtered.end(); ++itr) {
		uniquekeywords += 1;
	}
	cout << uniquekeywords << endl;
	return 0;
}
