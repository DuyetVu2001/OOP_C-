#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

void merge(int a[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];
	
	for (i = 0; i < n1; i++) {
		L[i] = a[l+i];
	}
	
	for (j = 0; j < n2; j++) {
		R[j] = a[m+1+j];
	}
	
	i = 0;
	j = 0;
	k = l;
	
	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			a[k++] = L[i++];
		}
		else {
			a[k++] = R[j++];
		}
	}
	
	while (i < n1) {
		a[k++] = L[i++];
	}
	
	while (j < n2) {
		a[k++] = R[j++];
	}
}

void mergeSort(int a[], int l, int r) {
	int m = (l+r) / 2;
	
	if (l < r) {
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

int main() {
	int a[] = {3, 4, 1, 6, 2, -100};
	
	mergeSort(a, 0, 5);
	
	for (int i = 0; i < 6; i++) {
		cout << a[i] << " ";
	}
	return 0;
}

