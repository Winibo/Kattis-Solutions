#include <iostream>
#include <stack>

using namespace std;

int main() {
	int inputs, currentInt;
	bool operand1, operand2;
	//Gets the starting T/F inputs:
	cin >> inputs;
	char startinput[inputs], currentInput;
	stack <bool> currentvalues;
	for (int i=0; i < inputs; i++) {
		cin >> currentInput;
		if (currentInput == 'T') startinput[i] = true;
		else startinput[i] = false;
	}
	//While there is still more to calculate, continue to read values;
	//Always a default of at least 1 value.
	cin >> currentInput;
	while (cin) {
		//If the current value is an input (not a logic gate).
		if (currentInput != '*' && currentInput != '+' && currentInput != '-') {
			//All inputs are capital letters, ASCII A is a 65(thus A-65 = 0)
			currentInt = static_cast<int>(currentInput) - 65;
			currentvalues.push(startinput[currentInt]);
		} else if (currentInput == '*') {
			//Logical AND gate
			operand1 = currentvalues.top();
			currentvalues.pop();
			operand2 = currentvalues.top();
			currentvalues.pop();
			currentvalues.push(operand1 && operand2);
		} else if (currentInput == '+') {
			//Logical OR gate
			operand1 = currentvalues.top();
			currentvalues.pop();
			operand2 = currentvalues.top();
			currentvalues.pop();
			currentvalues.push(operand1 || operand2);
		} else if (currentInput == '-') {
			//Logical NOT gate
			operand1 = currentvalues.top();
			currentvalues.pop();
			operand1 = !operand1;
			currentvalues.push(operand1);
		}
		//get next input
		cin >> currentInput;
	}

	//Take final value from stack (if true output T else F)
	operand1 = currentvalues.top();
	if (operand1) cout << 'T' << endl;
	else cout << 'F' << endl;
	return 0;
}
