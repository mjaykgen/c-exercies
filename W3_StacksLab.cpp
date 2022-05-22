#include<iostream>
#include<stack>
using namespace std;
int intFromEven(int);
bool isValid(string);
int formEven(int);
bool check(string, int, stack<char>&);
int main() {
	int choice;
	do {
		cout << "Enter your choice: \n1- Form an integer from even digits:\n2-Validate an expression:\n";
		cin >> choice;
		if (choice == 1) {
			int n;
			cout << "Enter an integer:";
			cin >> n;
			cout << " Integer from even digits only is:" << intFromEven(n) << endl;
			cout << " Integer from even digits only is:" << formEven(n) << endl;			
		}
		else if (choice == 2) {
			string expr;
			cout << "Enter an expression to validate:";
			cin >> expr;
			if (isValid(expr))
				cout << "Expression is valid\n" ;
			else cout << "Expression is invalid\n";
			stack<char> s;
			/*if (check(expr,0,s))
				cout << "Expression is valid\n";
			else cout << "Expression is invalid\n";*/
		}
		else cout << "Invalid choice";
	} while (choice != 1 && choice != 2);
	return 0;
}
//iterative solution
int intFromEven(int n) { //form an integer from the even digits in n
	int newN=0, d;
	stack<int> s;
	while (n > 0) {
		d = n % 10;
		if( d % 2 ==0)
			s.push(d);
		n /= 10;
	}
	while (!s.empty()) {
		newN *= 10;
		newN +=  s.top();
		s.pop();
	}
	return newN;
}
///////////////////////////recursive/////////////////////////
void fillStack(stack<int>& s, int n) {
	//base case
	if (n == 0)
		return;
	int d = n % 10;
	if (d % 2 == 0)
		s.push(d);
	//recursive call
	fillStack(s, n / 10);
}
void evaluate(stack<int>& s, int& val) {
	if (s.empty())
		return;
	val *= 10;
	val += s.top();
	s.pop();
	evaluate(s, val);
}
//initial function
int formEven(int n) {
	//recursive func to fill stack
	stack<int> s;
	fillStack(s, n);
	//recursive func to evaluate
	int val = 0;
	evaluate(s, val);
	return val;
}
//////////////////////////////////////////////////////////////////////

//validate expression - iterative
bool isValid(string expr) {
	stack<char> s;
	for (int i = 0; i < expr.length(); i++) {
		if (expr[i] == '(')
			s.push(expr[i]);
		else if (expr[i] == ')') {
			if (s.empty())
				return false;
			s.pop();
		}
	}
	return s.empty();
}
////////////////////recursive validate /////////////////////////////////////////
bool check(string expr, int i, stack<char>& s) {
	if (i == expr.length() )
		return s.empty();
	if (expr[i] == '(')
		s.push(expr[i]);
	else if (expr[i] == ')') {
		if (s.empty())
			return false;
		s.pop();
	}
	return check(expr, i + 1, s);
}