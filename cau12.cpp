#include <iostream>
#define MAX 20
using namespace std;

struct Stack {
	int a[MAX];
	int top;
};

struct StackChar {
	char b[MAX];
	int top;
};

void init(Stack& s) {
	s.top = -1; // cho bang -1 thay vi 0 de dung lam chi so truy cap dinh cua stack
}
//push so nguyen
void push(Stack &s,int x){
	s.a[++s.top] = x;
}
//push ky tu
void push(StackChar& s, char x) {
	s.b[++s.top] = x;
}

//lay so nguyen xong xoa
int pop(Stack& s) {
	return s.a[s.top--];
}
//lay ky tu xong xoa
int pop(StackChar& s) {
	return s.b[s.top--];
}

int peek(Stack s) {
	return s.a[s.top];
}
//kiem tra stack so nguyen rong hay khong
bool isEmpty(Stack s) {
	return s.top == -1;
}
//kiem tra stack ky tu rong hay khong
bool isEmpty(StackChar s) {
	return s.top == -1;
}

void HauTotoTrungTo(char *a) {
	Stack s;
	StackChar b;
	for (int i = 0; i < strlen(a); i++) {
		if (isdigit(a[i])) {
			push(s, a[i] - '0'); //push so nguyen
			cout << pop(s) << " ";
		}
		else if (a[i] == '(') {
			i++;
			while (a[i] != ')') {
				if (isdigit(a[i])) {
					push(s, a[i] - '0');
					cout << pop(s) << " ";
				}
				else {
					if (a[i] != ' ') {
						push(b, a[i]);
					}
				}
				i++;
			}
		}
		else {
			if (a[i] != ' ') {
				push(b, a[i]); //push phep toan
			}
		}
	}
	while (isEmpty(s) && !isEmpty(b)) {
		cout << pop(b) << " ";
	}
	
}


int main() {
	
	char a[] = "5 * (3 + 4)";


	return 0;
}