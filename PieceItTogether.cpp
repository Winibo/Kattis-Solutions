#include <bits/stdc++.h>

using namespace std;

struct vertex {
  vector<bool> implications;
}


int main() {
  int height, width;
  cin >> height width;
  char board[500][500];

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      cin >> board[i][j];
    }
  }
  vector<vertex> variables; //Hold Variables
  vertex* links[500][500][8]; //Hold references to correct variables for later
  //Find all the variables in the graph
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      //Only Check Right and Down to avoid Duplicate Variables
      if (board[i][j] == 'B') {
        if (board[i][j+1] == 'W') { // Right
          vertex temp, temp2;
          variables.push_back(temp);
          variable.push_back(temp2);
          links[i][j][0] = &temp; //Right Pair
          links[i][j+1][1] = &temp; //Left Pair for next
          links[i][j][4] = &temp; //Right Pair
          links[i][j+1][5] = &temp; //Left Pair for next
        }
        if (board[i+1][j] == 'W') { // Down
          vertex temp;
          variables.push_back(temp);
          links[i][j][2] = &temp; // Down Pair
          links[i+1][j][3] = &temp; // Up Pair for next
          links[i][j][6] = &temp; // Down Pair
          links[i+1][j][7] = &temp; // Up Pair for next
        }
      } else if(board[i][j] == 'W') {
        if (board[i][j+1] == 'B') { // Right
          vertex temp;
          variables.push_back(temp);
          links[i][j][0] = &temp; // Right
          links[i][j+1][1] = &temp; // Up pair for next
          links[i][j][4] = &temp; //Right Pair
          links[i][j+1][5] = &temp; //Left Pair for next
        }
        if (board[i+1][j] == 'B') { // Down
          vertex temp;
          variables.push_back(temp);
          links[i][j][2] = &temp; // Down Pair
          links[i+1][j][3] = &temp; // Up Pair for next
          links[i][j][6] = &temp; // Down Pair
          links[i+1][j][7] = &temp; // Up Pair for next
        }
      }
    }
  }
  //Add implications
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      //Elements 0 = Right, 1 = Left, 2 = Down, 3 = Up, 4-7 inverse of 1-4
      
    }
  }
}
