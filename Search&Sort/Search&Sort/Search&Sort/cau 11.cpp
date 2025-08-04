#include <iostream>
#include <string>
#define MAX 100
using namespace std;


struct NhanVien {
	int id;
	string hoTen;
	int thang;
	int namsinh;
};



struct DS {
	NhanVien a[MAX];
	int n;
};

void init(DS& a) {
	a.n = -1;
}

void nhap1NV(NhanVien& nv) {
	cout << "Nhap id: ";
	cin >> nv.id;
	cin.ignore();
	cout << "Nhap ho ten: ";
	getline(cin, nv.hoTen);
	cout << "Nhap thang: ";
	cin >> nv.thang;
	cout << "Nhap nam sinh: ";
	cin >> nv.namsinh;
}
void xuat1NV(NhanVien nv) {
	cout << "==========================\n";
	cout << "id: " << nv.id << endl;
	
	cout << "ho ten: " << nv.hoTen << endl;
	
	cout << "thang: " << nv.thang << endl;
	
	cout << "nam sinh: "<< nv.namsinh << endl;
	cout << "==========================\n";
}

void nhapDS(DS& a) {
	do {
		cout << "Nhap so luong nhan vien: ";
		cin >> a.n;
		if (a.n > MAX || a.n < 0) {
			cout << "Pham vi khong hop le ! \n";
		}

	} while (a.n > MAX || a.n < 0);
	
	for (int i = 0; i < a.n; i++) {
		nhap1NV(a.a[i]);
	}

}
//a
void findQuy1(DS a) {
	for (int i = 0; i < a.n; i++) {
		if (a.a[i].thang >= 1 && a.a[i].thang<=3) {
			xuat1NV(a.a[i]);
		}
	}
}
//b

int compareID(NhanVien a, NhanVien b) {
	return a.id - b.id;
}


void selectionSort(DS& a, int func(NhanVien, NhanVien)) {
	int min;
	for (int i = 0; i < a.n-1; i++) {
		min = i;
		for (int j = i + 1; j < a.n; j++) {
			if (func(a.a[min], a.a[j])<0) {
				min = j;
			}
		}

		swap(a.a[i], a.a[min]);
	}

}
//c

NhanVien binarySearch(DS a, int id) {
	int l = 0;
	int r = a.n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a.a[mid].id == id) {
			return a.a[mid];
		}
		if (id < a.a[mid].id) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}


	}
	
}

//d

int compareHoTen(NhanVien a, NhanVien b) {
	return a.hoTen.compare(b.hoTen);
}
int compareThang(NhanVien a, NhanVien b) {
	return a.thang - b.thang;
}

//compare so sanh ki tu dau tien cua chuoi , neu bang nhau thi so sanh ki tu tiep theo
//so sanh qua ma ascii
void interchangeSort(DS& a) {
	for (int i = 0; i < a.n - 1; i++) {
		for (int j = i + 1; j < a.n; j++) {
			if (compareThang(a.a[i], a.a[j]) > 0 || (compareThang(a.a[i], a.a[j]) == 0 && compareHoTen(a.a[i], a.a[j]) > 0)) {
				swap(a.a[i], a.a[j]);
			}




		}
	}
}



/*if (compareThang(a.a[i], a.a[j])==0) {
	if (compareHoTen(a.a[i], a.a[j]) > 0) {
		swap(a.a[i], a.a[j]);
	}
}
else {
	if (compareThang(a.a[i], a.a[j]) > 0) {
		swap(a.a[i], a.a[j]);
	}
}*/
void printDS(DS a) {
	if (a.n < 0) {
		cout << "DS RONG\n";
		return;
	}
	for (int i = 0; i < a.n; i++) {
		xuat1NV(a.a[i]);
	}

}

int main() {
	DS a;
	init(a);

	nhapDS(a);

	printDS(a);

	
	cout << "Nhan vien co thang sinh la quy 1 : \n";
	findQuy1(a);
	 
	selectionSort(a,compareID);
	cout << "===================KQ SAP XEP==============\n";
	printDS(a);
	int id;
	cout << "Nhap id can tim: ";
	cin >> id;
	NhanVien res2 = binarySearch(a, id);
	cout << "Thong tin nhan vien co id = " << id << ": " << endl;
	xuat1NV(res2);


	interchangeSort(a);
	cout << "==============KQ SAP XEP 2=============\n";
	printDS(a);


	return 0;
}