#include <bits/stdc++.h>

using namespace std;

int main() {
  bool first = true;
  while (true) {
    int scanlines;
    cin >> scanlines;
    cin.ignore(100, '\n');
    if (scanlines == 0) break;
    if (!first) cout << endl;
    bool corrupt = false;
    int prevlength = -1;
    for (int i = 0; i < scanlines; i++) {
      string encoding;
      getline(cin, encoding);
      encoding = encoding + ' ';
      char print = encoding[0];
      int repeat = 0;
      int length = 0;
      for (int i = 2; i < encoding.length(); i++) {
        if (encoding[i] != ' ') repeat = repeat*10 + (encoding[i] - '0');
        else {
          for (int j = 0; j < repeat; j++) {
            cout << print;
          }
          if (print == '#') print = '.';
          else print = '#';
          length += repeat;
          repeat = 0;
        }
      }
      cout << endl;
      if (!corrupt && (prevlength == -1 || length == prevlength)) {
        prevlength = length;
        length = 0;
      } else corrupt = true;
    }
    if (corrupt) cout << "Error decoding image" << endl;
    first = false;
  }
  return 0;
}
