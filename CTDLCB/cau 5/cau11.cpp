#include <iostream>
#include <string>
#define MAX 20
using namespace std;

//khai bao cau truc
struct Stack {
	int a[MAX];
	int top; //phan tu tren dinh stack hay con la so luong
};

//khoi tao rong
void init(Stack& s) {
	s.top = -1; // cap nhat bang -1 thay vi 0 de su dung lam chi so
}

//day vao
void push(Stack& s, int x) {
	if (s.top < MAX) {
		s.a[++s.top] = x;
	}
}

//lay ra roi xoa
int pop(Stack& s) {
	return s.a[s.top--];
}

//lay ra nhung khong xoa
int peek(Stack s) {
	return s.a[s.top];
}

int tinhHauTo(char*s){ // con tro s tro den ky tu dau tien cua chuoi
	Stack a;
	init(a);
	for (int i = 0; i < strlen(s); i++) {
		if (isdigit(s[i])) {
			int num = 0;
			while (isdigit(s[i])) {
				num = num * 10 + (s[i] - '0');
				i++;
			}
			push(a, num);
		}
		else {
			if (s[i] != ' ') {
				char op = s[i];
				int y = pop(a);
				int x = pop(a);
				switch (op)
				{
				case '+': {
					push(a, x + y);
					break;
				}
				case'-': {
					push(a, x - y);
					break;
				}
				case '*': {
					push(a, x * y);
					break;
				}
				case '/': {
					if (y != 0) {
						push(a, x / y);
					}
					break;

				}
				}
				
			}
		}
	}
	return pop(a);
}





int main() {
	Stack s;
	init(s);
	
	char a [] = "10 5 + 2 * 3 /";
	
	
	cout << tinhHauTo(a) << endl;

	return 0;
}