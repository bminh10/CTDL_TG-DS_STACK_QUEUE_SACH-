#include <iostream>
#include <string>
using namespace std;

struct SinhVien {
	long long id;
	string hoten;
	string khoa;
	float dtb;
};

struct Node {
	SinhVien info;
	Node* next;

};

void init(Node*& head) {
	head = nullptr;
}
Node* createNode(SinhVien x) {
	Node* p = new Node();
	p->info = x;
	p->next = nullptr;
	return p;
}
void nhap1SV(SinhVien& sv) {
	cout << "==================\n";
	cout << "nhap ID: ";
	cin >> sv.id;
	cin.ignore();
	cout << "nhap Ho ten ";
	getline(cin, sv.hoten);
	cout << "nhap Khoa: ";
	getline(cin, sv.khoa);
	cout << "nhap DTB: ";
	cin >> sv.dtb;
	cout << "==================\n";
}

void xuat1SV(SinhVien sv) {
	cout << "==================\n";
	cout << "ID: " << sv.id << endl;
	cout << "Ho ten " << sv.hoten << endl;
	cout << "Khoa: " << sv.khoa << endl;
	cout << "DTB: " << sv.dtb << endl;
	cout << "==================\n";
}

void addLast(Node*&head,SinhVien x) {
	Node* p = createNode(x);
	if (head == nullptr) {
		head = p;
		return;
	}
	Node* tmp = head;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	tmp->next = p;
	return;

}

void delFirst(Node*& head) {
	if (head != nullptr) {
		Node* tmp = head;
		if (head->next == nullptr) {
			head = nullptr;
			delete tmp;
			return;
		}
		head = head->next;
		tmp->next = nullptr;
		delete tmp;
		return;

	}
}
void nhapDS(Node*& head, int n) {
	for (int i = 0; i < n; i++) {
		SinhVien sv;
		nhap1SV(sv);
		addLast(head, sv);
	}
}
SinhVien search(Node* head, float x) {
	Node* tmp = head;
	while (tmp != nullptr && tmp->info.dtb < x) {
		tmp = tmp->next;
	}
	if (tmp != nullptr) {
		return tmp->info;
	}
}

//B
int compareID(SinhVien a, SinhVien b) {
	return a.id - b.id;
}


void interchangeSort(Node*& head,int func(SinhVien,SinhVien)) {
	for (Node* i = head; i->next != nullptr; i = i->next) {
		for (Node* j = i->next; j != nullptr; j = j->next) {
			if (func(i->info, j->info) < 0 ) {
				swap(i->info, j->info);
			}
		}
	}
}


int compareKhoa(SinhVien a, SinhVien b) {
	return a.khoa.compare(b.khoa);
}
int compareHoTen(SinhVien a, SinhVien b) {
	return a.hoten.compare(b.hoten);
}

// sap xep danh sach sinh vien tang theo khoa, neu cungten khoa thi tang dan theo ten
void interchangeSort(Node*& head) {
	for (Node* i = head; i->next != nullptr; i = i->next) {
		for (Node* j = i->next; j != nullptr; j = j->next) {
			if (compareKhoa(i->info, j->info) > 0 || (compareKhoa(i->info, j->info) == 0 && compareHoTen(i->info, j->info) >0 )) {
				swap(i->info,j->info);
			}
		}
	}
}

void clearNode(Node*& head) {
	while (head != nullptr) {
		delFirst(head);
	}
}




void print(Node* head) {
	Node* tmp = head;
	while (tmp != nullptr) {
		xuat1SV(tmp->info);
		tmp = tmp->next;
	}
	cout << endl;
}

int main() {
	Node* head;
	init(head);
	int n;
	cout << "Nhap so luong sv: ";
	cin >> n;
	nhapDS(head, n);
	print(head);
	/*SinhVien res = search(head, 8);
	cout << "Sinh vien co dtb >= 8 la: ";
	xuat1SV(res);*/
	cout << "============= KQ SAP XEP THEO ID ============\n";
	interchangeSort(head,compareID);
	print(head);

	cout << "============= KQ SAP XEP 2 ============\n";
	interchangeSort(head);
	print(head);

	clearNode(head);
	if (head == nullptr) {
		cout << "Da giai phong \n";
	}

	return 0;
}