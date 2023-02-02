#include <iostream>
#include <utility>
#include <vector>

using namespace std;

enum mark {Unvisited, Search, Visited, End, EndSearch};

struct node {
  vector<pair<int,bool>> edges;
  mark m = Unvisited;
};

void dfs(node v[], mark m, mark end, int start = 0, int depth = 0) {
  //cout << "Depth: " << depth << endl;
  if (v[start].m == m || v[start].m == Search) return; // Exit if looping
  if (v[start].m != Search && v[start].m != EndSearch) v[start].m = m;
  for (pair<int,bool> i : v[start].edges) {
    if (i.second) {
      dfs(v,m,end,i.first,depth+1);
      return;
    }
  }
  if (v[start].m != EndSearch) v[start].m = end;
}


int main() {
  node vertices[1000];
  int nodes, edges;
  cin >> nodes >> edges;
  for (int i = 0; i < edges; i++) {
    int a,b;
    bool forced = false;
    cin >> a >> b;
    if (a < 0) {
      forced = true;
      a = a*-1;
    }
    vertices[a-1].edges.push_back(make_pair(b-1,forced));
  }
  //Mark all locations we can reach with legal moves
  //cout << "Calling First DFS" << endl;
  dfs(vertices, Search, EndSearch);

  //Mark all locations we reach from illegal moves
  //cout << "Starting Illegal Moves" << endl;
  for (int i = 0; i < nodes; i++) {
    if (vertices[i].m == Search || vertices[i].m == EndSearch) {
      for (pair<int, bool> i : vertices[i].edges) {
        dfs(vertices, Visited, End, i.first);
      }
    }
  }
  //Calculate answer
  int answer = 0;
  for (int i = 0; i < nodes; i++) {
    if (vertices[i].m == End || vertices[i].m == EndSearch) answer++;
  }
  // for (int i = 0; i < nodes; i++) {
  //   cout << "Node " << i << " is marked: ";
  //   if (vertices[i].m == Unvisited) cout << "Unvisited" << endl;
  //   if (vertices[i].m == Search) cout << "Search" << endl;
  //   if (vertices[i].m == Visited) cout << "Visited" << endl;
  //   if (vertices[i].m == End) cout << "End" << endl;
  //   if (vertices[i].m == EndSearch) cout << "EndSearch" << endl;
  // }
  cout << answer;
  return 0;
}
