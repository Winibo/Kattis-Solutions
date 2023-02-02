#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
int main() {
  int n = 0;
  cin >> n;
  while (n--) {
    int m = 0;
    cin >> m;
    int sp = -1;
    priority_queue<pi> bp;
    priority_queue<pi, vector<pi>, greater<pi>> ap;
    string bs = "";
    while (m--) {
      cin >> bs;
      int a = 0;
      int p = 0;
      if (bs == "buy") {
        cin >> a >> bs >> bs >> p;
        bp.push(make_pair(p, a));
      } else if (bs == "sell") {
        cin >> a >> bs >> bs >> p;
        ap.push(make_pair(p, a));
      }
      while ((!bp.empty() && !ap.empty()) &&
      (bp.top().first >= ap.top().first)) {
        sp = ap.top().first;
        if (bp.top().second > ap.top().second) {
          a = bp.top().second - ap.top().second;
          p = bp.top().first;
          bp.pop();
          ap.pop();
          bp.push(make_pair(p, a));
        } else if (bp.top().second <
        ap.top().second) {
          a = ap.top().second - bp.top().second;
          p = ap.top().first;
          bp.pop();
          ap.pop();
          ap.push(make_pair(p, a));
        } else {
          bp.pop();
          ap.pop();
        }
      }
      if (ap.empty()) {
        cout << '-';
      } else {
        cout << ap.top().first;
      }
      cout << " ";
      if (bp.empty()) {
        cout << '-';
      } else {
        cout << bp.top().first;
      }
      cout << " ";
      if (sp == -1) {
        cout << '-';
      } else {
        cout << sp;
      }
      cout << endl;
    }
  }
  return 0;
}
