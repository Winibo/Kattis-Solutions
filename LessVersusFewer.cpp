#include <bits/stdc++.h>

using namespace std;


string c[5] = {"number", "fewest", "fewer", "many", "few"};
string m[5] = {"amount", "least", "less", "much", "little"};

int main() {
  int nouns, phrases;
  cin >> nouns >> phrases;
  //Get all nouns
  int cnouns = 0, mnouns = 0;
  string count[1000];
  string mass[1000];
  for (int i = 0; i < nouns; i++) {
    string temp;
    char temp2;
    cin >> temp >> temp2;
    if (temp2 == 'c') {
      count[cnouns] = temp;
      cnouns++;
    } else {
      mass[mnouns] = temp;
      mnouns++;
    }
  }
  //Check all phrases
  for (int i = 0; i < phrases; i++) {
    string lvf;
    bool found = false;
    bool countnoun = false;
    string word;
    cin >> lvf >> word;
    if (word == "of") {
      cin >> word;
    }
    if (lvf == "most" || lvf == "more") {
      cout << "Correct!" << endl;
      continue;
    }
    for (int j = 0; j < 5; j++) {
      if (lvf == c[j]) {
        countnoun = true;
        //cerr << lvf << " = " << c[j] << endl;
        //Check for the word
        for (int k = 0; k < cnouns; k++) {
          if (word == count[k]) {
            //cerr << word << " = " << count[k] << endl;
            cout << "Correct!" << endl;
            found = true;
            break;
          }
        }
      }
      if (found) break;
    }
    if (found) continue;
    for (int j = 0; j < mnouns; j++) {
      if (countnoun) break;
      if (word == mass[j]) {
        cout << "Correct!" << endl;
        found = true;
        break;
      }
    }
    if (found) continue;
    cout << "Not on my watch!" << endl;
  }
  return 0;
}
