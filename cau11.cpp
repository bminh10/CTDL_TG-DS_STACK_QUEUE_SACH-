#include <iostream>
#include <stack>
using namespace std;



int main() {
	stack<int> a;
	stack<char>b;

	string s = "10 5 + 2 * 3 /";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			int num = 0;
			while (isdigit(s[i])) {
				num = num*10+(s[i]-'0');
				i++;
			}
			i--;
			a.push(num);
		}
		else {
			if (s[i] != ' ') {
				b.push(s[i]);
				char op = b.top();

				int y = a.top();
				a.pop();
				int x = a.top();
				a.pop();
				switch (op)
				{
				case '+': {
					a.push(x + y);
					break;
				}
				case '-': {
					a.push(x - y);
					break;
				}
				case '*': {
					a.push(x * y);
					break;
				}
				case '/': {
					a.push(x / y);
					break;
				}
				default:
					break;
				}
				b.pop();
			}
		}
	}
	
	cout << a.top() << endl;

	return 0;
}