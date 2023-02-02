#include <bits/stdc++.h>

using namespace std;

int main() {
  while (true) {
    int num, dem, whole;
    cin >> num >> dem;
    if (num == 0 && dem == 0) break;
    whole = num / dem;
    num = num % dem;
    cout << whole << ' ' << num << ' ' << '/' << ' ' << dem << endl;
  }
  return 0;
}
