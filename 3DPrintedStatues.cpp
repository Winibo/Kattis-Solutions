#include <bits/stdc++.h>

using namespace std;

int main() {
  int statues;
  cin >> statues;
  int days = ceil(log(statues) / log(2)) + 1;
  cout << days;
  return 0;
}
