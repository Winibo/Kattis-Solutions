#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int choice;
  cin>>choice;
  cout << fixed << setprecision(14);
  double answer = 0;
  double factorial = 1;
  for (int i = 0; i < choice+1; i++) {
    factorial = factorial * i;
    if (factorial == 0)
      factorial = 1;
    answer += (1.0/factorial);
  }
  cout << answer << endl;
  return 0;
}
