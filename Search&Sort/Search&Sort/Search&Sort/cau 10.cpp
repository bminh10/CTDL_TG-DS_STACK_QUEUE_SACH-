#include <iostream>
#define MAX 8
using namespace std;

void quickSortASC(int a[], int left, int right) {
	int l = left;
	int r = right;
	int pivot = a[(l + r) / 2];
	while (l <= r) {
		while (a[l] < pivot) {
			l++;
		}
		while (a[r] > pivot) {
			r--;
		}
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	if (l < right) {
		quickSortASC(a, l, right);
	}
	if (r > left) {
		quickSortASC(a, left, r);
	}


}

void quickSortDESC(int a[], int left, int right) {
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

	if (l < right) {
		quickSortDESC(a, l, right);
	}
	if (r > left) {
		quickSortDESC(a, left, r);
	}

}

bool MaxHeap(int a, int b) {
	return a > b;
}
bool MinHeap(int a, int b) {
	return a < b;
}

//tang dan
void heapify(int a[], int n, int i,bool func(int,int)) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int jmax = i;


	if (l<n && func(a[l],a[jmax])) {
		jmax = l;
	}
	if (r<n && func(a[r], a[jmax])) {
		jmax = r;
	}

	if (jmax != i) {
		swap(a[i], a[jmax]);
		heapify(a, n, jmax,func);
	}
}


void heapSortASC(int a[], int n,bool func(int, int)) {
	//tim max heap
	int i = (n / 2) - 1;
	while (i >= 0) {
		heapify(a, n, i,func);
		i--;
	}

	for (int right = n - 1; right > 0; right--) {
		swap(a[0], a[right]);
		heapify(a, right, 0,func);
	}

}






void printList(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int main() {
	int a[MAX] = { 5,6,2,-8,10,22,15,4 };
	heapSortASC(a, MAX,MinHeap);
	printList(a, MAX);

	return 0;
}