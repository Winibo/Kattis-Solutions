#include <iostream>

using namespace std;

const int MAX_VERTICES = 20;

int dfs(int stable[], int vertices[][20], int n, int goal, int vertex, int depth=0) {
  //cout << "Starting DFS with a depth of " << depth << endl;
  if (depth == 2 && vertices[vertex][goal] == 1) {
    stable[vertex] = 1;
    return 1;
  } else if (depth == 2) {
    return 0;
  }
  for (int i = 0; i < n; i++) {
    if (vertices[vertex][i] == 1 && i != vertex) {
      int t = dfs(stable,vertices,n,goal,i,depth+1);
      if (t == 1) {
        stable[vertex] = 1;
        return 1;
      }
    }
  }
  return 0;
}



int main() {
  int n = 0;
  cin >> n;
  while (n != -1) {
    int vertices[20][20];
    int stable[20] = {};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> vertices[i][j];
      }
    }
    //cout << "Finished reading Vertices" << endl;
    for (int i = 0; i < n; i++) {
      if (stable[i] != 1) {
        //cout << "Starting DFS for vertex " << i << endl;
        dfs(stable, vertices, n, i, i);
      }
    }
    int temp = 0;
    //cout << "Printing weak vertices" << endl;
    for (int i = 0; i < n; i++) {
      if (stable[i] != 1) {
        if (temp != 0) cout << ' ';
        cout << i;
        temp++;
      }
    }
    cout << endl;
    //cout << "Reading new input" << endl;
    cin >> n;
  }
  return 0;
}
