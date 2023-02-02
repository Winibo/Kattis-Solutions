#include <bits/stdc++.h>

using namespace std;

char amap[100][100];
bool visited[100][100];

void fill(int x, int y, int height, int length) {
  if (x < 0 || y < 0 || x == length || y == height) return;
  if (amap[y][x] != '#' || visited[y][x] == true) return;
  visited[y][x] = true;
  fill(x-1,y, height, length);
  fill(x+1,y, height, length);
  fill(x-1,y-1, height, length);
  fill(x-1,y+1, height, length);
  fill(x+1,y-1, height, length);
  fill(x+1,y+1, height, length);
  fill(x,y-1, height, length);
  fill(x,y+1, height, length);
}

int calculate(int height, int length) {
  int regions = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < length; x++) {
      if (amap[y][x] == '#' && visited[y][x] == false) {
        fill(x,y, height, length);
        regions++;
      }
    }
  }
  return regions;
}

int main() {
  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      visited[i][j] = false;
    }
  }
  int height, length;
  cin >> height >> length;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < length; j++) {
      char current;
      cin >> current;
      amap[i][j] = current;
    }
  }
  //Colour map
  cout << calculate(height, length) << endl;
  return 0;
}
