#include <bits/stdc++.h>

using namespace std;

int main() {
  int size = 0;
  cin >> size;
  long long answer = 0;
  while (size--) {
    char input;
    cin >> input;
    if (input == 'O')
      answer |= 1L << size;
  }
  cout << answer << endl;
  return 0;
}
