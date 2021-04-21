#include <iostream>
using namespace std;

void selection_sort (int a[], int n) {
	int min_index;
	
	for (int i = 0; i < n - 1; i++) {
		min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (a[min_index] > a[j]) {
				min_index = j;
			}
		}
		swap(a[min_index], a[i]);
		
		
	}
}

int main() {
	int a[] = {4, 7, 10, 1, -10};
	int n = sizeof(a) / sizeof(int);
	
	selection_sort(a, n);
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	
	return 0;
}

