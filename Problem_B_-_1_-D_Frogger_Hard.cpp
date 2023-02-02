#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> b;
    vector<int> a;
    map<int, int> g;
    for (int i = 0; i < n; i++) {
        int temp = 0;
        cin >> temp;
        b.push_back(temp);
        a.push_back(0);
    }
    int score = 0;
    for (int i = 0; i < n; i++) {
        int pos = i;
        while (true) {
            if (pos < 0) {
                break;
            } else if (pos >= n) {
                break;
            } else if (a[pos]) {
                break;
            }
            score++;
            a[pos] = true;
            pos += b[pos];
        }
        for (int j = 0; j < n; j++) {
            a[j] = 0;
        }
    }
    cout << score << endl;
    return 0;
}
