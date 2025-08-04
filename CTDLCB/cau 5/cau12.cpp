#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int getPriority(char op) {
	if (op == '^') {
		return 3;
	}
	if (op == '/' || op == '*'){
		return 2;
	}
	if (op == '-' || op == '+') {
		return 1;
	}
	return 0;
}


string infixToPostfix(char* s) {
	stack<char>a;
	queue<char>b;

	int len = strlen(s);
	for (int i = 0; i < len; i++) {
		if (isdigit(s[i])) {
			b.push(s[i]);
		}
		else if (s[i] == '(') {
			a.push(s[i]);
		}
		else if (s[i] == ')') {
			char op = a.top();
			a.pop();
			while (op != '(') {
				b.push(op);
				op = a.top();
				a.pop();
			}
		}
		else {
			if (s[i] != ' ') {
				while (!empty(a) && getPriority(s[i]) <= getPriority(a.top())) {
					b.push(a.top());
					a.pop();
				}
				a.push(s[i]);
			}
			
		}
	}

	while (!empty(a)) {
		b.push(a.top());
		a.pop();
	}
	
	

	string res = "";
	while (!empty(b)) {
		res = res +  b.front();
		b.pop();
		if (!empty(b)) {
			res = res + " ";
		}
	}

	return res;

}

//"5 * (3^2 + 4)"
string infixToPrefix(char* s) {
	string prefix="";
	stack<char> a;
	int len = strlen(s);
	for (int i = len-1; i >= 0; i--) {
		if (isdigit(s[i])) {
			prefix += s[i];
		}
		else if (s[i] == ')') {
			a.push(s[i]);
		}
		else if (s[i] == '(') {
			char op = a.top();
			a.pop();
			while (op != ')') {
				prefix += op;
				op = a.top();
				a.pop();
			}
		}
		else {
			if (s[i] != ' ') {
				while (!empty(a) && getPriority(a.top()) > getPriority(s[i])) {
					prefix += a.top();
					a.pop();
				}
 				a.push(s[i]);
			}
			
		}

	}

	while (!empty(a)) {
		prefix += a.top();
		a.pop();
	}

	for (int i = 0; i < prefix.length()/2; i++) {
		swap(prefix[i], prefix[prefix.length() - 1 - i]);
	}


	return prefix;

}




int main() {
	
	char s[] = "5 * (3^2 + 4)"; //5 3 2 ^ 4 + * postfix
	//a+b+c -> + + abc			  //4 2 3 ^ + 5 * -> * 5 + ^ 3 2 4 

	string res = infixToPrefix(s);
	cout << res << endl;



	return 0;
}