#include <iostream>

using namespace std;

int main() {
  char board[5][5];
  int knights[25][2] = {};
  int knightlen = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> board[i][j];
      if (board[i][j] == 'k')  {
        knights[knightlen][0] = i;
        knights[knightlen][1] = j;
        knightlen++;
      }
    }
  }
  //cout << "Number of knights:" << knightlen << endl;
  if (knightlen != 9) {
    cout << "invalid";
    return 0;
  }
  for (int i = 0; i < knightlen; i++) {
    int a = knights[i][0],b = knights[i][1];
    //2 up 1 left
    if (a >= 2 && b >= 1) {
      if (board[a-2][b-1] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
    //2 up 1 right
    if (a >= 2 && b <= 3) {
      if (board[a-2][b+1] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
    //2 right 1 up
    if (a >= 1 && b <= 2) {
      if (board[a-1][b+2] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
    //2 right 1 down
    if (a <= 3 && b <= 2) {
      if (board[a+1][b+2] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
    //2 down 1 left
    if (a <= 2 && b >= 1) {
      if (board[a+2][b-1] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
    //2 down 1 right
    if (a <= 2 && b <= 3) {
      if (board[a+2][b+1] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
    //2 left 1 up
    if (a >= 1 && b >= 2) {
      if (board[a-1][b-2] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
    //2 left 1 down
    if (a <= 3 && b >= 2) {
      if (board[a+1][b-2] == 'k') {
        cout << "invalid";
        return 0;
      }
    }
  }
  cout << "valid";
  return 0;
}
