#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pi;
int main() {
  int tests;
  cin >> tests;
  for (int i = 0; i < tests; i++) {
    int orders = 0;
    cin >> orders;
    priority_queue<pair<int, int>> bid;
    priority_queue<pi, vector<pi>, greater<pi>> ask;
    int lastStock = -1;
    for (int i = 0; i < orders; i++) {
      //Read in next line
      string bs, skip;
      int amount, price;
      cin >> bs >> amount >> skip >> skip >> price;
      if (bs == "buy") {
        bid.push(make_pair(price, amount));
      } else ask.push(make_pair(price, amount));
      //Make any necessary sales
      if (!bid.empty() && !ask.empty()) {
        //If we're willing to buy, do so
        int sum = 0;
        while (!bid.empty() && !ask.empty() && bid.top().first >= ask.top().first) {
          lastStock = ask.top().first;
          if (bid.top().second > (ask.top().second + sum)) {
            sum += ask.top().second;
            ask.pop();
          } else {
            pair<int, int> a;
            a = ask.top();
            ask.pop();
            a.second -= (bid.top().second - sum);
            if (a.second > 0) ask.push(a);
            bid.pop();
            sum = 0;
          }
        }
        pair<int, int> b;
        if (!bid.empty()) {
          b = bid.top();
          b.second -= sum;
          bid.pop();
          if (b.second > 0) bid.push(b);
        }
      }
      //Output
      string out = "";
      if (!ask.empty()) out += to_string(ask.top().first);
      else out = out + '-';
      out += ' ';
      if (!bid.empty()) out += to_string(bid.top().first);
      else out = out + '-';
      out += ' ';
      if (lastStock != -1) out += to_string(lastStock);
      else out += '-';
      cout << out << endl;
    }
    cerr << "Exiting";
  }
  cerr << endl << "Exit 2";
  return 0;
}
