#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

bool calc(const string op, stack <int>& dS){
	// left, right, total
	int l, r, t;

	r = dS.top();
	dS.pop();

	l = dS.top();
	dS.pop();

	char in = op[0];

	switch(in){
		case '+':
			t = l+r;
			break;
		case '-':
			t = l-r;
			break;
		case '*':
			t = l*r;
			break;
		case '/':
			t = l/r;
			break;
		case '%':
			t = l&r;
			break;
		case '~':
			t *= -1;
			break;
		default:
			return false;
	}

	dS.push(t);
	cout << "\t" << t << endl;

	return true;
}

int main(){
    cout << "Please enter your Reverse Polish Notation:" << endl;

    stack < int > d;
    string in;

    while(true){
		// Get user input
		cout << "> ";
		cin >> in;

		// Check is input a number
		float v;
		if(istringstream(in) >> v){
			d.push(v);

		// Quit the program if 'quit' or 'exit'
	} else if(in == "quit" || in == "exit" || in == "end"){
			break;

		// Perform the action. If something went wrong, display error message
		} else {
			if(!calc(in, d)){
				cout << endl << "Invalid input" << endl;
			}
		}
    }

    return 0;
}
