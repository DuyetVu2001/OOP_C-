#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

void bubbleSort(int a[], int n) {
	for (int i = n-1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[j+1]) {
				swap(a[j], a[j+1]);
			}
		}
	}
}

void insertSort(int a[], int n)  {
	int index, value;
	
	for (int i = 1; i < n; i++) {
		value = a[i];
		index = i;
	
		while(a[index-1] < value && index > 0) { 
			a[index] = a[index-1];
			index--;
		}
		
		a[index] = value;
	}
}

void selectSort (int a[], int n) {
	int maxIndex;
	
	for (int i = 0; i < n - 1; i++) {
		maxIndex = i;
		
		for (int j = i + 1; j < n; j++) {
			if (a[maxIndex] < a[j]) {
				maxIndex = j;
			}
		}
		
		if (i != maxIndex) {
			swap(a[i], a[maxIndex]);
		}
	}
}

//merge sort
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
		if (L[i] >= R[j]) {
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
	if (l < r) {
        int m = (l+r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m+1, r);
		merge(a, l, m, r);
	}
}

//quick sort
int partition(int a[], int l, int r) {
	int p = a[r];
	int i = l - 1;
	
	for (int j = l; j < r; j++) {
		if (a[j] < p) {
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	
	return i + 1;
}

void quickSort(int a[], int l, int r) {
	if (l >= r)
		return;
	int p = partition(a, l, r);
	quickSort(a, l, p - 1);
	quickSort(a, p + 1, r);
}

void display(int a[], int n)  {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
}

//heap sort
void heapify(int a[], int n, int i) {
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	
	if (l < n && a[l] > a[largest])
		largest = l;
	if (r < n && a[r] > a[largest])
		largest = r;
	if (largest != i) {
		swap(a[largest], a[i]);
		heapify(a, n, largest);
	}
}

void heapSort(int a[], int n) {
	for (int i = n/2-1; i >= 0; i--)
		heapify(a, n, i); // create a Max heap
	
	for (int i = n-1; i >= 0; i--) {
		swap(a[0], a[i]); // swap first and last node
		heapify(a, i, 0); // creates max heap on reduced array
	}
}

int main() {
	int a[] = {4, 1, 6, 8, 10, -10, 0};
	int n = sizeof(a) / sizeof(int);
	
//	cout << "+ Bubble sort: \n"; 
//	bubbleSort(a, n);
//	display(a, n);
//	
//	cout << "\n+ Insertion sort: \n";
//	insertSort(a, n);
//	display(a, n);
//	
//	cout << "\n+ Selection sort: \n";
//	selectSort(a, n);
//	display(a, n);
	
//	cout << "\n+ Merge sort: \n";
//	mergeSort(a, 0, n-1);
//	display(a, n);

//	cout << "\n+ Quick sort: \n";
//	quickSort(a, 0, n-1);
//	display(a, n);

	cout << "\n+ Heap sort: \n";
	quickSort(a, 0, n-1);
	display(a, n);
	return 0;
}



