#include <iostream>
using namespace std;

int main() {
	int linelength;
	cin>>linelength;
	string line[linelength];

	for(int i=0;i<linelength;i++) {
		cin >> line[i];
	}
	if (line[0] > line[1]) {
		for (int i=1;i<linelength-1;i++) {
			if (line[i] < line[i+1]) {
				printf("%s\n","NEITHER" );
				return 0;
			}
		}
		printf("%s\n","DECREASING" );
	} else {
		for (int i=1;i<linelength-1;i++) {
			if (line[i] > line[i+1]) {
				printf("%s\n","NEITHER" );
				return 0;
			}
		}
		printf("%s\n","INCREASING");
	}
	return 0;
}
