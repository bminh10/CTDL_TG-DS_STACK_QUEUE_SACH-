#include<iostream>
using namespace std;

void quickSort(int a[], int left, int right) {
	int pivot = (left + right) / 2;
	int i = left, j = right;
	while (i <= j) {
		while (a[pivot] > a[i]) {
			i++;
		}
		while (a[pivot] < a[j]) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < j) {
		quickSort(a, left, j);

	}
	if (i < right) {
		quickSort(a, i, right);
	}

}



int main() {
	int a[6] = {30, 40, 35, 45, 20, 36 };
	quickSort(a, 0, 5);

	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}


	return 0;
}