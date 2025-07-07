#include<iostream>
#include<stack>
using namespace std;


struct DaThuc {
	float soMu;
	float heSo;
};


struct Node {
	DaThuc info;
	Node* next;
};

void init(Node*& head) {
	head = NULL;
}

Node* createNode(const DaThuc x) {
	Node* p = new Node();
	p->info = x;
	p->next = NULL;
	return p;

}

void insBac(Node*& head, const DaThuc x)
{
	Node* p = createNode(x);
	if (head == NULL) {
		
		head = p;
	}
	else {
		Node*tmp = head;
		Node* pre = NULL;
		while (tmp != NULL && tmp->info.soMu < x.soMu) {
			pre = tmp;
			tmp = tmp->next;
		}
		if (tmp != NULL) {
			if (pre == NULL) {
				if (x.soMu == tmp->info.soMu) {
					tmp->info.heSo = x.heSo;
					return;
				}
				p->next = head;
				head = p;
			}
			else {
				p->next = tmp;
				pre->next = p;
			}
		}

	}

}

void nhap1DaThuc(DaThuc& dt) {
	cout << "Nhap he so: ";
	cin >> dt.heSo;
	cout << "Nhap so mu: ";
	cin >> dt.soMu;
}

void xuat1DaThuc(const DaThuc dt) {
	if (dt.soMu == 0) {
		cout << dt.heSo;
		return;
	}
	if (dt.soMu == 1) {
		cout << dt.heSo << "x";
		return;
	}
	cout << dt.heSo << "x^" << dt.soMu;
}

//xoa bac chi dinh cua phan tu
int delBac(Node*& head, const int mu) {
	if (head != NULL) {
		Node* tmp = head;
		Node* pre = nullptr;
		while (tmp != NULL && tmp->info.soMu != mu) {
			pre = tmp;
			tmp = tmp->next;
		}
		//neu tim duoc
		if (tmp != NULL) {
			if (pre == NULL) {
				head = NULL;
			}
			else {
				pre->next = tmp->next;
				tmp->next = NULL;
			}
			delete tmp;
			return 1; //xoa thanh cong
		}
	}
		
	
	return -1; //xoa khong thanh cong
}


//1 + x + x^2 + x^3
int calDaThuc(Node* head, const int valueofX) {
	stack<int>a;
	stack<char>b;

}


void printList(Node* head) {
	Node* tmp = head;
	while (tmp != NULL) {
		xuat1DaThuc(tmp->info);
		if (tmp->next != NULL) {
			cout << " + ";
		}
		tmp = tmp->next;
	}
	cout << endl;
}

int delFirst(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		if (head->next == nullptr) {
			head = NULL;
		}
		else {
			head = tmp->next;
			tmp->next = NULL;
		}
		delete tmp;
		return 1;
	}
	return -1;
}

void clearNode(Node*& head) {
	while (head != NULL) {
		delFirst(head);
	}
}

int main() {
	DaThuc dt1,dt2,dt3;
	dt1.heSo = 2;
	dt1.soMu = 0;

	dt2.heSo = 2;
	dt2.soMu = 1;
	
	dt3.heSo = 3;
	dt3.soMu = 2;
	
	
	Node *head;
	init(head);
	insBac(head, dt3);
	insBac(head, dt2);
	insBac(head, dt1);
	
	
	printList(head);
	delBac(head, 2);
	cout << "================KQ SAU KHI XOA=================\n";
	printList(head);


	int valueofX;
	cout << "Nhap gia tri cho x: ";
	cin >> valueofX;
	





	clearNode(head);
	if (head == NULL) {
		cout << "Rong\n";
	}

	
	return 0;
}