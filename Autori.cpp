#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() {
	string shortend, fullString;
	getline(cin, fullString);
	smatch matchs;
   while (std::regex_search (fullString,matchs,regex("[A-Z]"))) {
      for (auto x:matchs) cout << x;
      fullString = matchs.suffix().str();
   }
	return 0;
}
