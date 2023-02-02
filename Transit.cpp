#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int start, goal, stops;
  cin >> start >> goal >> stops;
  int walks[21];
  int rides[20];
  int arrivals[20];
  int time = start;
  for (int i = 0; i < stops+1; i++) {
    cin >> walks[i];
  }

  for (int i = 0; i < stops; i++) {
    cin >> rides[i];
  }

  for (int i = 0; i < stops; i++) {
    cin >> arrivals[i];
  }

  for (int i = 0; i < stops; i++) {
    //Add walk distance
    time += walks[i];
    //Calculate and add when next bus leaves
    float multi = ceil(static_cast<float>(time) / static_cast<float>(arrivals[i]));
    time += (arrivals[i] * multi) - time;
    //Add ride time
    time += rides[i];
  }
  //Add final walking time
  time += walks[stops];
  if (time < goal) cout << "yes"; else cout << "no";
  return 0;
}
