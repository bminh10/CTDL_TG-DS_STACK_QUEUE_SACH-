#include<iostream>
#include <cmath>
#include<iomanip>
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

//void insBac(Node*& head, DaThuc x)
//{
//	Node* p = createNode(x);
//	if (head == NULL) {
//		
//		head = p;
//	}
//	else {
//		Node*tmp = head;
//		Node* pre = NULL;
//		while (tmp != NULL && tmp->info.soMu < x.soMu) {
//			pre = tmp;
//			tmp = tmp->next;
//		}
//		//bac = hoac hon 
//		if (tmp != NULL) {
//			if (pre == NULL) {
//				if (x.soMu == tmp->info.soMu) {
//					tmp->info.heSo = x.heSo;
//					return;
//				}
//				p->next = head;
//				head = p;
//				
//				
//			}
//			else {
//				if (x.soMu == tmp->info.soMu) {
//					tmp->info.heSo = x.heSo;
//					return;
//				}
//				p->next = tmp;
//				pre->next = p;
//			}
//		}
//
//	}
//
//}


//chen bac nho nhat dau tien va co thu tu ( bac cuoi cung la bac cua da thuc)
void insBac(Node*& head, DaThuc x) {
	Node* p = createNode(x);
	if (head == NULL) {
		head = p;
	}
	else {
		//danh sach chi co 1 phan tu
		if (head->next == NULL) {
			if(p->info.soMu == head->info.soMu){
				head->info.heSo = p->info.heSo;
				return;
			}
			if (p->info.soMu < head->info.soMu) {
				p->next = head;
				head = p;
				return;
			}
			if(p->info.soMu > head->info.soMu)  {
				head->next = p;
				return;
			}
		}
		//danh sach co nhieu hon 1 phan tu
		else {
			Node* tmp = head;
			if (p->info.soMu < tmp->info.soMu) {
				p->next = head;
				head = p;
				return;
			}
			if(p->info.soMu> tmp->info.soMu){
				while (tmp->next != NULL) {
					if (p->info.soMu > tmp->info.soMu && p->info.soMu < tmp->next->info.soMu) {
						p->next = tmp->next;
						tmp->next = p;
						return;
					}
					tmp = tmp->next;
				}
				if (tmp->info.soMu == p->info.soMu) {
					tmp->info.heSo = p->info.heSo;
					return;
				}
				tmp->next = p;
				return;
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
float calDaThuc(Node* head, float valueofX) {
	Node* tmp = head;
	float res = 0;
	while (tmp != NULL) {
		if (tmp->info.soMu == 0) {
			res = res + tmp->info.heSo;
			
			
		}
		else if (tmp->info.soMu == 1) {
			res = res + tmp->info.heSo * valueofX;
			
			
		}
		else {
			res = res + tmp->info.heSo * pow(valueofX,tmp->info.soMu);
			
			
			
		}
		tmp = tmp->next;
		
	}

	return res;


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
	DaThuc dt1,dt2,dt3,dt4;
	dt1.heSo = 2;
	dt1.soMu = 0;

	dt2.heSo = 2;
	dt2.soMu = 1;
	
	dt3.heSo = 6;
	dt3.soMu = 3;
	
	dt4.heSo = 5;
	dt4.soMu = 2;
	
	Node *head;
	init(head);
	
	insBac(head, dt1);
	insBac(head, dt2);
	insBac(head, dt3);
	
	insBac(head, dt4);
	
	printList(head);
	/*delBac(head, 2);
	cout << "================KQ SAU KHI XOA=================\n";
	printList(head);


	int valueofX;
	cout << "Nhap gia tri cho x: ";
	cin >> valueofX;*/
	
	cout << calDaThuc(head, 2)<< endl;




	clearNode(head);
	if (head == NULL) {
		cout << "Rong\n";
	}

	
	return 0;
}