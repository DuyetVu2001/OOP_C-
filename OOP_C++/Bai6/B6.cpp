#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Array {
private:
	float *arr;
	int n;
	
public:
	friend istream &operator >> (istream &is, Array &obj);
	friend ostream &operator << (ostream &os, Array &obj);
	friend Array operator-- (Array &arr1);
	friend Array operator++ (Array &arr1); 
};

istream &operator >> (istream &is, Array &obj) {
	cout << "Nhap vao so phan tu n: ";
	cin >> obj.n;
	//Cap phat dong
	obj.arr = new float [obj.n];
	//Nhap mang 
	for (int i = 0; i < obj.n; i ++) {
		cout << "Nhap a[" << i << "]: ";
		cin >> obj.arr[i];
	}
	return is;
}

ostream &operator << (ostream &os, Array &obj) {
	for (int i = 0; i < obj.n; i++) {
		cout << obj.arr[i] << endl;
	}
	return os;
}

Array operator-- (Array &arr1) {
	for (int i = 0; i < arr1.n - 1; i++) {
		for (int j = i + 1; j < arr1.n; j++) {
			if (arr1.arr[i] < arr1.arr[j]) {
				swap(arr1.arr[i], arr1.arr[j]);
			}		
		}
	}
	return arr1;
}

Array operator++(Array &arr1) {
	for (int i = 0; i < arr1.n - 1; i++) {
		for (int j = i + 1; j < arr1.n; j++) {
			if (arr1.arr[i] > arr1.arr[j]) {
				swap(arr1.arr[i], arr1.arr[j]);
			}		
		}
	}
	return arr1;
}

int main() {
	Array a1;
	
	cin >> a1;
	
	++a1;	
	cout << "Sap xep tang: " << endl;
	cout << a1;
	--a1;
	cout << "Sap xep giam: " << endl;
	cout << a1;
	return 0;
}

