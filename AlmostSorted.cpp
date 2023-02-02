#include <bits/stdc++.h>

using namespace std;

int main() {
  int length;
  cin >> length;
  int array[200000];
  for (int i = 0; i < length; i++) {
    int temp;
    cin >> temp;
    array[i] = temp;
  }
  int query;
  cin >> query;
  //Check not already sorted
  int temp = 0;
  for (int i = 0; i < length; i++) {
    if (array[i] < query) {
      temp++;
    }
  }
  if (array[temp] == query) {
    for (int j = 0; j < length; j++) {
      cout << array[j] << ' ';
    }
    return 0;
  }
  //Implement cycle sort
  for (int i = 0; i < length; i++) {
    int lesser = -1;
    while (lesser != i) {
      lesser = 0;
      for (int j = 0; j < length; j++) {
        if (array[j] < array[i]) lesser++;
      }
      //Stop when we find the right element
      if (array[temp] == query) {
        for (int j = 0; j < length; j++) {
          cout << array[j] << ' ';
        }
        return 0;
      }
      if (lesser == i) break;
      int temp = array[lesser];
      array[lesser] = array[i];
      array[i] = temp;
    }
  }
  return 0;
}
