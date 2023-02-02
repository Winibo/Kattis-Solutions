#include <iostream>
#include <numeric>

using namespace std;


int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int main() {
	for (int test=0; test < 5; test++) {
		int heads = 0, knights = 0;
		cin >> heads >> knights;
		if (heads == 0 && knights == 0) {
			break;
		}
		int headCircumferences[heads], knightHeights[knights];
		for (int i=0; i < heads; i++) {
			cin >> headCircumferences[i];
		}
		for (int i=0; i < knights; i++) {
			cin >> knightHeights[i];
		}
		if (knights < heads) {
			cout << "Loowater is doomed!" << endl;
			continue;
		}
		qsort(knightHeights, knights, sizeof(int), compare);
		qsort(headCircumferences, heads, sizeof(int), compare);
		if (knightHeights[knights-1] < headCircumferences[heads-1]) {
			cout << "Loowater is doomed!" << endl;
			continue;
		}
		int knightcosts[heads], currenthead = 0, cost = 0;
		for (int i=0; i<knights;i++) {
			if (knightHeights[i] >= headCircumferences[currenthead]) {
				knightcosts[currenthead] = knightHeights[i];
				currenthead += 1;
			}
			if (currenthead == heads) {
				break;
			}
		}
		if (currenthead < heads) {
			cout << "Loowater is doomed!" << endl;
			continue;
		}
		cost = accumulate(knightcosts, knightcosts+heads, cost);
		cout << cost << endl;
	}
	return 0;
}
