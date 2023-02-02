#include <bits/stdc++.h>

using namespace std;

const double UNIT_DISTANCE = (M_PI * 60) / 28;
const int RUN_SPEED = 15;
const int PICKUP_SPEED = 1;

int calculateDistance(char current, char next) {
  int curr = 0;
  if (current != '\'' && current != ' ') {
    curr = current - 'A';
  } else if (current == '\'') {
    curr = 27;
  } else curr = 26;
  int nxt = 0;
  if (next != '\'' && next != ' ') {
    nxt = next - 'A';
  } else if (next == '\'') {
    nxt = 27;
  } else nxt = 26;
  //Get distance
  return min(max(nxt,curr) - min(nxt,curr), abs(max(nxt,curr) - min(nxt,curr) - 28));
}
int main() {
  int tests = 0;
  cin >> tests;
  cin.ignore(1, '\n');
  for (int i = 0; i < tests; i++) {
    string aphorism;
    getline(cin, aphorism);
    char currentLetter = aphorism[0];
    double time = 1;
    for (int i = 1; i < aphorism.length(); i++) {
      char nextLetter = aphorism[i];
      time += (UNIT_DISTANCE * calculateDistance(currentLetter, nextLetter)) / RUN_SPEED;
      time += PICKUP_SPEED;
      currentLetter = nextLetter;
    }
    cout << fixed << setprecision(10) << time << endl;
  }
  return 0;
}
