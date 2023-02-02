#include <bits/stdc++.h>

using namespace std;

char maps[1001][1001];
int groups[1001][1001];

void flood_fill(int x, int y, int rows, int columns, int colour) {
  groups[x][y] = colour;
  //Up
  if (x > 0 && maps[x-1][y] == maps[x][y] && groups[x-1][y] == -1) {
    flood_fill(x-1,y, rows, columns, colour);
  }
  //Down
  if (x < rows && maps[x+1][y] == maps[x][y] && groups[x+1][y] == -1) {
    flood_fill(x+1,y, rows, columns, colour);
  }
  //Left
  if (y > 0 && maps[x][y-1] == maps[x][y] && groups[x][y-1] == -1) {
    flood_fill(x,y-1, rows, columns, colour);
  }
    //Right
  if (y < columns && maps[x][y+1] == maps[x][y] && groups[x][y+1] == -1) {
    flood_fill(x,y+1, rows, columns, colour);
  }
}


int main() {
  int r, c;
  cin >> r >> c;
  int group = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> maps[i][j];
      groups[i][j] = -1;
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (groups[i][j] == -1) {
        flood_fill(i, j, r, c, group);
        group++;
      }
    }
  }
  //Return answers to queries
  int queries;
  cin >> queries;
  for (int i = 0; i < queries; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (groups[r1-1][c1-1] == groups[r2-1][c2-1]) {
      if (maps[r1-1][c1-1] == '1') cout << "decimal" << endl;
      else cout << "binary" << endl;
    } else cout << "neither" << endl;
  }
  return 0;
}
