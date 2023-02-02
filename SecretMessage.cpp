#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  while (tests-- > 0) {
    string plaintext = "";
    string ciphertext = "";
    cin >> plaintext;
    int square = ceil(sqrt(plaintext.length()))*ceil(sqrt(plaintext.length()));
    if (square != plaintext.length()) 
      plaintext.append(square - plaintext.length(), '*');
    int root = sqrt(plaintext.length());
    // cerr << plaintext << endl;
    for (int i = 0; i < root; i++) {
      for (int j = root-1; j >= 0; j--) {
        // cerr << "Element " << j*root + i << endl;
        if (plaintext[j*root + i] == '*')
          continue;
        ciphertext += plaintext[j*root + i];
      }
    }
    cout << ciphertext << endl;
  }
  return 0;
}
