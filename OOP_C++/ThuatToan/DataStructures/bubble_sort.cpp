#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

void bubbleSort(int a[], int n){
	bool swapped = true;
	for (int i = n - 1; i >= 1; i--) {
		swapped = true;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[j+1]) {
                swap (a[j], a[j+1]);
				swapped = false;
            }
        }

		if (swapped) {
			cout << "Dung tai i = " << i << endl;
			break;
		}
    }
} 

void printArray(int a[], int n){
	for (int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
}

int main() {
	int a[] = {1, 2, 3, 9, 2};
	int n = sizeof(a) / sizeof(int);
	
	bubbleSort(a, n);
	printArray(a, n);
	
	return 0;
}

