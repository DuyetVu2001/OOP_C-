#include <iostream>
using namespace std;

void sort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
}

void count(int a[], int n) {
	int dem = 1;
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1] && i != n - 1) {
			dem++;
		}
		else {
			cout <<  a[i] << " - " << dem << "; ";
			dem = 1;
		}
	}
}

int main() {
    int a[7] = {1, 2, 3, 4, 5, -2, 0};
    int n = 7;

	sort(a, n);
	count(a, n);
    return 0;
}
