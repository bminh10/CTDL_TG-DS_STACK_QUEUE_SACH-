#include <iostream>
using namespace std;



//tim x = 2, trong day tren thi tim kiem tuan tu hay tim kiem nhi phan hieu qua hon? giai thich?
int search(int a[], int n, int key) {
	for (int i = 0; i < n; i++) {
		if (a[i] == key) {
			return i;
		}
	}
	return -1;
}


int binarySearch(int a[], int n,int key) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (a[mid] == key) {
			return mid;
		}
		if (key > a[mid]) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	return -1;
}

//giai thich
//Tim kiem tuan tu
/*Lan lap thu 1 -> i = 0 -> a[0] == 2 -> tim thay x -> dung vong lap (Mat 1 phep so sanh)*/
//Tong : 1 lan so sanh

//tim kiem nhi phan
/*Lan lap thu 1 -> l = 0 , r = 8 -> mid = (l+r)/2 = 4 -> a[mid]=8 > key=2 -> r = mid - 1
  Lan lap thu 2 -> l = 0 , r = 3 -> mid = (l+r)/2 = 1 -> a[mid]=5 > key=2 -> r = mid - 1
  Lan lap thu 3 -> l = 0 , r = 0 -> mid = (l+r)/2 = 0 -> a[mid]=2 == key=2 -> tim thay x -> dung vong lap*/
//tong 3 lan so sanh

//=> Tim kiem tuan tu trong truong hop nay hieu qua hon



//b) xac dinh so phep so sanh de tim duoc x=6 trong day bangg tim kiem nhi phan
/*
Lan lap thu 1 -> l = 0 , r = 8 -> mid = (l+r)/2 = 4 -> a[mid]= 8 > x=6 -> r=mid-1
Lan lap thu 2 -> l=0 , r = 3 -> mid = (l+r)/2 = 1 -> a[mid] = 5 < x = 6 -> l = mid + 1
Lan lap thu 3 -> l = 2 , r = 3 -> mid = (l+r)/2 = 2 -> a[mid] = 6 == x = 6 -> tim thay x -> dung vong lap
*/

//=> Tong so phep so sanh la 3


int main() {
	int a[9] = {2,5,6,6,8,9,10,15,20};
}