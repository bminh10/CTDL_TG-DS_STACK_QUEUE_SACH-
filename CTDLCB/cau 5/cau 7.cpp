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
	return p;
}

void addFirst(Node*& head, Node*& tail,const int x) {
	Node* p = createNode(x);
	p->next = head;
	if (head == nullptr) { // neu head va tail null
		
		tail = p;
	}
	
	head = p;

}

//them phan tu tai vi tri index
int addX(Node*& head, Node*& tail, const int x,const int index) {
	
	int i = 1;
	Node* tmp = head;
	Node* prev = nullptr;
	while (tmp != NULL && i < index) {
		prev = tmp;
		tmp = tmp->next;
		i++;
	}
	//neu tim thay
	if (tmp != NULL) {
		
		if (i==1) {
			addFirst(head, tail, x);
		}
		else {
			Node* p = createNode(x);
			p->next = tmp;
			prev->next = p;

		}
		return 1;// da them vao vi tri chi dinh
	}
	return -1; // vi tri chi dinh khong ton tai trong danh sach
	

}

//them truoc gia tri chi dinh
int addBefore(Node*&head, const int x,const int value) {
	if (head != NULL) {
		Node* tmp = head;
		Node* prev = NULL;
		while (tmp != NULL && tmp->info != value) {
			prev = tmp;
			tmp = tmp->next;
		}
		//neu tim thay
		if (tmp != NULL) {
			Node* p = createNode(x);
			if (prev != NULL) { //them truoc o giua 2 phan tu
				p->next = tmp;
				prev->next = p;
			}
			else { //them truoc phan tu dau tien
				p->next = head;
				head = p;
			}

		}
		return 1;//them thanh cong
	}
	return -1;//khong ton tai gia tri chi dinh

}

//them sau chi dinh
int addAfter(Node*head,Node*&tail, const int x, const int value) {
	if (tail != NULL) {
		Node* tmp = head;
		while (tmp != NULL && tmp->info != value) {
			tmp = tmp->next;
		}
		//neu tim thay
		if (tmp != NULL) {
			Node* p = createNode(x);
			//neu tmp khong phai phan tu cuoi
			if (tmp->next != nullptr) {
				p->next = tmp->next;
			}
			else {
				tail = p;
			}
			tmp->next = p;
		}
		return 1;//them thanh cong
	}
	return -1;//khong ton tai gia tri chi dinh 
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
		return 1;//xoa thanh cong
	}
	return -1;//xoa khongg thanh cong
}

int delLast(LinkedList& a) {
	if (a.head != NULL) {
		Node* tmp = a.head;
		Node* prev = nullptr;
		while (tmp->next != nullptr) {
			prev = tmp;
			tmp = tmp->next;
		}
		if (prev != nullptr) {
			a.tail = prev;
			a.tail->next = nullptr;
		}
		else {
			a.head = nullptr;
			a.tail = nullptr;
		}
		delete tmp;
		return 1;//xoa thanh cong
	}
	return -1;//xoa khong thanh cong

}
//xoa phan tu x
int delX(LinkedList& a, const int value) {
	if (a.head != nullptr) {
		Node* tmp = a.head;
		Node* prev = nullptr;
		while (tmp != nullptr && tmp->info != value) {
			prev = tmp;
			tmp = tmp->next;
		}
		//neu tim thay
		if (tmp != NULL) {
			if (prev == NULL) { // phan tu can xoa o vi tri dau tien
				a.head = nullptr;
				a.tail = nullptr;
			}
			else if (tmp->next == nullptr) {
				a.tail = prev;
				a.tail->next = nullptr;
			}
			else { //phan tu can xoa o vi tri giua
				prev->next = tmp->next;
				tmp->next = nullptr;

			}
			delete tmp;
			return 1; // xoa thanh cong
		}

	}
	return -1; // xoa khong thanh cong
}
// kiem tra danh sach tang dan
int isAsc(LinkedList& a) {
	if (a.head != NULL) {
		Node* j = nullptr;
		for (Node* i = a.head; i->next != nullptr; i = i->next) {
			j = i->next;
			if (i->info > j->info) {
				return -1;//khong tang dan
			}
		}
	}
	return 1;

	
}

//them nhung phai dam bao danh sach tang dan
int addIf(LinkedList& a, const int x) {
	if (a.head != NULL && isAsc(a)==1) {
		Node* tmp = a.head;
		if (x < tmp->info) {
			addFirst(a.head, a.tail, x);
			return 1;
		}
		//tim vi tri chen
		
		while (tmp->next != NULL) {
			
			if (x > tmp->info && x < tmp->next->info) {
				Node* p = createNode(x);
				p->next = tmp->next;
				tmp->next = p;
				return 1;//them thanh cong
			}
			tmp = tmp->next;
		}
		//neu tim thay vi tri them van dam bao tang dan va khong phai phan tu cuoi cung
		if (x > tmp->info) {
			Node* p = createNode(x);
			tmp->next = p;
			a.tail = p;
			return 1;//them thanh cong
		}
	}
	return -1; //them that bai do khong dam bao tang dan
}




void clearNode(Node*& head,Node*&tail) {
	while (head != nullptr) {
		delFirst(head,tail);
	}
}


void output(Node* head) {
	if (head == NULL) {
		cout << "Rong \n";
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

	addFirst(a.head, a.tail, 8);
	addFirst(a.head, a.tail, 4);
	addFirst(a.head, a.tail, 3);
	if (addIf(a,2) != -1) {
		cout << "Them thanh cong\n";
	}
	else {
		cout << "Khong dam bao tang dan \n";
	}
	/*int res1 = addAfter(a.head,a.tail, 3, 6);
	if (res1 != -1) {
		cout << "Them thanh cong !\n";
	}
	else {
		cout << "Them khong thanh cong \n";
	}*/
	cout << "Danh sach hien tai: ";
	output(a.head);

	/*int kq = delX(a, 3);
	if (kq != -1) {
		cout << "Xoa thanh cong! \n";
		cout << "Danh sach hien tai: ";
		output(a.head);

	}
	else {
		cout << "Xoa khong thanh cong \n";
	}*/



	

	/*int res2 = delLast(a);
	int res3 = delLast(a);
	int res4 = delLast(a);
	int res5 = delLast(a);
	if (res2 != -1) {
		cout << "Xoa thanh cong \n";
	}
	else {
		cout << "Xoa that bai \n";
	}
	cout << "Danh sach hien tai: ";
	output(a.head);*/

	/*int res = addX(a.head, a.tail, 4, 3);
	if (res != -1) {
		cout << "Them phan tu vao chi dinh thanh cong! \n";
		output(a.head);
	}
	else {
		cout << "Vi tri chi dinh khong ton tai\n";
	}*/

	

	

	//giai phong
	clearNode(a.head,a.tail);
	if (a.head == nullptr && a.tail==nullptr) {
		cout << "Da giai phong xong\n";
	}

	return 0;
}