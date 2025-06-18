#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* next;
};

struct LinkedList {
	Node* head;
	Node* tail;
};
//khoi dong danh sach lien ket
void init(Node*& head, Node*& tail) {
	head = nullptr;
	tail = nullptr;
}

Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
}

void addX(Node*& head, Node*& tail, const int x,const int index) {
	
	int i = 1;
	Node* tmp = head;
	while (tmp != NULL && i != index) {
		tmp = tmp->next;
		i++;
	}
	//neu tim thay
	if (tmp != NULL) {

	}
	

}


int delFirst(Node*& head,Node*&tail) {
	if (head != NULL) {
		Node* tmp = head;
		if (tmp->next != nullptr) {
			head = tmp->next;
			tmp->next = nullptr;
		}
		else {
			head = nullptr;
			tail = nullptr;
		}
		delete tmp;

	}
	return -1;//xoa khongg thanh cong
}

void clearNode(Node*& head,Node*&tail) {
	while (head != nullptr) {
		delFirst(head,tail);
	}
}


void output(Node* head) {
	Node* tmp = head;
	while (tmp != NULL) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << endl;
}



int main() {
	LinkedList a;

	init(a.head, a.tail);


	return 0;
}