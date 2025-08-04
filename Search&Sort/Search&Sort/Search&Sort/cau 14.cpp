#include <iostream>
using namespace std;

struct Node {
	int info;
	Node* next;
	Node* prev;
};

struct DoublyLinkedList {
	Node* head;
	Node* tail;
};

void init(DoublyLinkedList& l) {
	l.head = l.tail = nullptr;
}


Node* createNode(int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	p->prev = nullptr;
	return p;
}

void addLast(DoublyLinkedList& l, int x) {
	Node* p = createNode(x);
	if (l.head == nullptr) {
		l.head = l.tail = p;
		return;
	}
	l.tail->next = p;
	p->prev = l.tail;
	l.tail = p;
	return;

}

void delFirst(DoublyLinkedList& l) {
	if (l.head != nullptr) {
		Node* tmp = l.head;
		if (tmp->next == nullptr) {
			l.head = l.tail = nullptr;
			delete tmp;
			return;
		}
		l.head = l.head->next;
		l.head->prev = nullptr;
		tmp->next = nullptr;
		delete tmp;
		return;

	}

}



void insOrdered(DoublyLinkedList& l, int x) {
	Node* p = createNode(x);
	if (l.head == nullptr) {
		l.head =l.tail= p;
		return;
	}
	if (x < l.head->info) {
		p->next = l.head;
		l.head->prev = p;
		l.head = p;
		return;
	}
	if (x > l.tail->info) {
		l.tail->next = p;
		p->prev = l.tail;
		l.tail = p;
		return;
	}
	Node* tmp = l.head;
	while (tmp != l.tail) {
		if (tmp->info < x && tmp->next->info > x) {
			tmp->next->prev = p;
			p->next = tmp->next;

			tmp->next = p;
			p->prev = tmp;
			return;
		}
		tmp = tmp->next;
	}
}

void insertionSort(DoublyLinkedList& l) {
	DoublyLinkedList tmp;
	init(tmp);
	
	for (Node* i = l. head; i != nullptr; i = i->next) {
		insOrdered(tmp, i->info);
	}
	l = tmp;

}


void print(DoublyLinkedList l) {
	Node* tmp = l.head;
	while (tmp != nullptr) {
		cout << tmp->info << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
void clearNode(DoublyLinkedList& l) {
	while (l.head != nullptr) {
		delFirst(l);
	}
}

int main() {
	DoublyLinkedList l;
	init(l);
	addLast(l, 2);
	addLast(l, 1);
	addLast(l, 5);
	addLast(l, 3);
	

	print(l);
	insertionSort(l);
	print(l);


	clearNode(l);
	if (l.head == nullptr) {
		cout << "Giai phong \n";
	}
	
	return 0;
}