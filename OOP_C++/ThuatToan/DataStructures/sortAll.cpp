#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <math.h>

void bubbleSort(int a[], int n) {
	bool check;
	
	for (int i = n - 1; i > 0; i--) {
		check = true;
		
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j+1]) {
				swap(a[j], a[j+1]);
				check = false;
			}
		}
		
		if (check)
			break;
	}
}

void insertSort(int a[], int n) {
	int key, j;
	
	for (int i = 1; i < n; i++) {
		key = a[i];
		j = i;
		
		while (j > 0 && key < a[j - 1]) {
			a[j] = a[j - 1];
			j--;
		}
		
		a[j] = key;
	}
}

void selectionSort(int a[], int n) {
	int minIndex;
	
	for (int i = 0; i < n - 1; i++) {
		minIndex = i;
		
		for (int j = i + 1; j < n; j++) {
			if (a[minIndex ] > a[j]) {
				minIndex = j;
			}
		}
		
		swap(a[i], a[minIndex]);
	}
}

//merge sort
void merge (int a[], int l, int mid, int r) {
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int L[n1], R[n2];
	
	for (int i = 0; i < n1; i++) {
		L[i] = a[l + i];
	}
	
	for (int j =0; j < n2; j++) {
		R[j] = a[mid + j + 1];
	}
	
	i = 0;
	j = 0;
	k = l;
	
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	
	while (j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}	

void mergeSort (int a[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergeSort(a, l, mid);
		mergeSort(a, mid+1, r);
		merge(a, l, mid, r);
	}
}

void display(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << "   ";
	}
	
	cout << endl;
}

//heap sort


//quick sort

int deQuy (int n) {
	if (n == 1|| n == 2) 
		return 1;
	return 2*deQuy(n-1)	+ pow(-1, (n-1));
}

int binarySearch (int a[], l, r, target) {
	
	return ;
}

int main() {
	int a[] = {1, 0, 3, 3, 5, -10};
	int n = sizeof(a)/sizeof(int);
	
//	cout << "+ SX tang: \n";
//	selectionSort(a, n);
//	display(a, n);
	
//	cout << "+ SX tang: \n";
//	mergeSort(a, 0, n - 1);
//	display(a, n);
	cout << deQuy(7);
	return 0;
}
