#include<bits/stdc++.h>
using namespace std;
int main() {
    int n = 0, s = 0, m = 0;
    vector<int> board;
    vector<bool> visit;
    cin >> n >> s >> m;
    for (int i = 0; i < n; i++) {
      int count = 0;
      cin >> count;
        board.push_back(count);
        visit.push_back(false);
    }
    int pos = s - 1;
    int jumps = 0;
    while (true) {
        if (pos < 0) {
            cout << "left" << endl;
            cout << jumps << endl;
            break;
        } else if (pos >= n) {
            cout << "right" << endl;
            cout << jumps << endl;
            break;
        } else if (board[pos] == m) {
            cout << "magic" << endl;
            cout << jumps << endl;
            break;
        } else if (visit[pos]) {
            cout << "cycle" << endl;
            cout << jumps << endl;
            break;
        }
        visit[pos] = true;
        jumps++;
        pos += board[pos];
    }
    return 0;
}
