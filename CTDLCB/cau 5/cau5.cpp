#include <iostream>
#include <climits>
using namespace std;

//danh sach lien ket don

struct Node {
	int info;
	Node* next;
	
};

struct LinkedList {
	Node* head;
	Node* tail;
};


//khoi dong danh sach
void init(Node*& head,Node*&tail) {
	head = nullptr;
	tail = nullptr;
}

//tao node moi
Node* createNode(const int x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}

//them dau danh sach
void addFirst(Node*& head,Node*&tail, const int x) {
	Node* p = createNode(x);
	p->next = head;
	if (head == nullptr) {
		tail = p;
	}
	head = p;
}

//them cuoi danh sach
void addLast(Node*&head,Node*& tail, const int x) {
	Node* p = createNode(x);
	Node* tmp = tail;
	if(head==NULL){
		head = p;
	}
	else {
		tmp->next = p;
	}
	tail = p;
}

//xoa dau
void delFirst(Node*& head,Node*&tail) {
	Node* tmp = head;
	if (tmp->next != NULL) { // neu danh sach >1 phan tu
		head = tmp->next;
		
	}
	else { // danh sach chi co 1 phan tu
		head = tail = NULL;
	}
	tmp->next = nullptr;
	delete tmp;

}

//clear Node
void clearNode(Node*& head,Node*&tail) {
	while (head != NULL) {
		delFirst(head, tail);
		
	}
}



//ham tim key
Node* findKey(Node* head, const int x) {
	Node* tmp = head;
	while (tmp != NULL && tmp->info!=x) {
		tmp = tmp->next;
	}
	return tmp;
}

//tim Max
int findMax(Node* head) {
	Node* i = head;
	int max = INT_MIN;
	while (i != NULL) {
		
		if (i->info > max) {
			max = i->info;
		}

		i = i->next;
	}
	return max;
}
//kiem tra danh sach co tang dan hay khong //ASC: TĂNG DẦN | DESC : GIẢM DẦN


//Thuat toan nay toi uu hon trong sach????
int isAsc(Node* head) {
	if (head != nullptr) {
		Node* j = nullptr;
		for (Node* i = head; i->next != NULL; i = i->next) {
			j = i->next;
			if (i->info > j->info) {
				return -1; //khong ASC
			}
		}
		return 1; // dang ASC
	}
	return -2; //khong sap xep duoc vi ds rong
}



//duyet danh sach
void print(Node* head) {
	if (head == NULL) {
		cout << "Danh sach rong !\n";
		return;
	}
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

	//cac thao tac them/xoa
	addLast(a.head, a.tail, 1);
	addLast(a.head, a.tail, 2);
	addLast(a.head, a.tail, 3);
	
	print(a.head);
	delFirst(a.head, a.tail);
	cout << "================KQ XOA=================\n";
	print(a.head);

	//tim kiem
	Node* res = findKey(a.head, 4);
	if (res != NULL) { 
		cout << "Tim thanh cong !\n";
		cout << res->info << endl;
	}
	else {
		cout << "khong co\n";
	}

	cout << "================FIND MAX=================\n";
	cout << findMax(a.head) << endl;

	cout << "===================KIEM TRA DANH SACH===================\n";
	if (isAsc(a.head) != -1) {
		cout << "Danh sach dang sap xep tang dan !\n";
	}
	else if (isAsc(a.head) == -2) {
		cout << "DS rong nen khong kiem tra \n";
	}
	else {
		cout << "Danh sach khong sap xep tang dan \n";
	}

	//cuoi bai phai clear het Node de tranh bi memory leak
	//...
	clearNode(a.head, a.tail);
	print(a.head);
	return 1;
}