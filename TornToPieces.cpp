#include <bits/stdc++.h>

using namespace std;

struct Node {
  vector<string> neighbors;
};

map<string, Node> stationsm;

string findRoute(string start, string end, string route, vector<string> prev) {
  // cerr << "Starting from " << start << ", finding, " << end << endl;
  if (route != "")
    route = route + " " + start;
  else
    route = start;
  if (start == end) return route; //Base case
  Node current = stationsm[start];
  prev.push_back(start);
  // cerr << "Current route: " << route << endl;
  for (string c : current.neighbors) {
    string temp = "-1";
    if (find(prev.begin(), prev.end(), c) == prev.end())
      temp = findRoute(c, end, route, prev);
    if (temp != "-1") return temp;
  }
  return "-1";
}

int main() {
  int stations;
  cin >> stations;
  cin.ignore(256, '\n');
  while (stations--) {
    string connections;
    getline(cin, connections);
    istringstream in(connections);
    string first, connected;
    in >> first;
    Node temp;
    stationsm.emplace(first, temp);
    // cerr << "Connecting station " << first << endl;
    while (in >> connected) {
      stationsm.emplace(connected, temp);
      stationsm[first].neighbors.push_back(connected);
      stationsm[connected].neighbors.push_back(first);
      // cerr << "Added station " << connected << endl;
    }
  }
  //Solve
  string start, end;
  cin >> start >> end;
  // cerr << "Finding route from " << start << " to " << end << endl;
  vector<string> temp;
  string answer = findRoute(start, end, "", temp);
  if (answer != "-1")
    cout << answer << endl;
  else
    cout << "no route found" << endl;
  return 0;
}
