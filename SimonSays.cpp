#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  cin.ignore(256, '\n');
  while (tests--) {
    string command;
    getline(cin, command);
    if (command.substr(0,10) == "Simon says") {
      cout << command.substr(11) << endl;
    }
  }
  return 0;
}
