#include <iostream>
#include <chrono>
#define MAX 100000
using namespace std;

void quickSort(int a[],int left, int right) {
	int l = left;
	int r = right;
	int pivot = a[(l + r) / 2];
	while (l <= r) {
		while (a[l] > pivot) {
			l++;
		}
		while (a[r] < pivot) {
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}

	if (l > right) {
		quickSort(a, l, right);
	}
	if (r < left) {
		quickSort(a, left, r);
	}
}


void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


void heapify(int a[], int n, int i) {
	int l = 2*i+1;
	int r = 2*i+2;
	int jmax = i;
	if (l < n && a[l] < a[jmax]) {
		jmax = l;
	}
	if (r < n && a[r] < a[jmax]) {
		jmax = r;
	}

	if (jmax != i) {
		swap(a[i], a[jmax]);
		heapify(a, n, jmax);
	}
}

void heapSort(int a[], int n) {
	//find min heap
	int i = (n / 2) - 1;
	while (i >= 0) {
		heapify(a, n, i);
		i--;
	}

	for (int right = n - 1; right > 0; right--) {
		swap(a[0], a[right]);
		heapify(a, right, 0);
	}

}



int main() {
	int a[MAX];
	for (int i = 0; i < MAX; i++) {
		a[i] = i;
	}


	auto start = chrono::high_resolution_clock::now();
	quickSort(a, 0, MAX - 1);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "Thoi gian: " << elapsed.count() << " giay.\n";
	print(a, 10);
	




	/*auto start = chrono::high_resolution_clock::now();
	heapSort(a, MAX);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = end - start;
	cout << "Thoi gian: " << elapsed.count() << " giay.\n";
	print(a, 10);
	*/

	//quick sort nhanh hon 
	
	



	return 0;
}