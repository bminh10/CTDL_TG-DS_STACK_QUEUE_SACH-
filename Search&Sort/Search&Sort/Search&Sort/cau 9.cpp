#include <iostream>
using namespace std;

//sap xep tang
void selectionSortASC(int a[], int n) {
	int min;
	for (int i = 0; i < n-1; i++) {
		min = i;
		for (int j = i+1; j < n; j++) {
			if (a[min] > a[j]) {
				min = j;
			}
		}
		swap(a[i], a[min]);
	}
}

void insertionSortASC(int a[], int n) {
	int x, pos;
	for (int i = 1; i < n; i++) {
		x = a[i];
		pos = i - 1;

		while(pos>=0 && a[pos]>x){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = x;
	}
}

//Cho biet trong truong hop sap xep tang thi selectionSort va insertionSort thuat toan nao toi uu hon
/*
Day la truong hop tot nhat 

Selection Sort:
Phep so sanh: n*(n-1)/2 -> 15 lan so sanh
Phep gan: 0

Insertion Sort
Phep so sanh: n-1 -> 5 lan so sanh
Phep doi cho: 0

*/

//=> insertion sort toi uu hon 


//cho biet neu dung thuat toan selection sort va insertion sort sap xep gian dan day tren thi thuat toan nao tot hon ?
/*
Day la truong hop xau nhat 

Selection Sort:
Phep so sanh: n(n-1)/2 -> 15 lan so sanh


Insertion Sort:
Phep so sanh: (n+2)(n-1)/2 = 20 lan so sanh

*/

//=> selection sort toi uu hon



void printList(int a[], int  n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int main() {
	int a[6] = { 1,2,3,4,5,6 };
	insertionSortASC(a, 6);
	printList(a, 6);


	return 0;
}