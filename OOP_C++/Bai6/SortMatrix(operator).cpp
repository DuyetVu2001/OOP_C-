#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Matrix {
private:
	int **arr;
	int dong;
	int cot;
	
public:
	friend istream &operator >> (istream &is, Matrix &obj);
	friend ostream &operator << (ostream &os, Matrix &obj);
	friend Matrix operator-- (Matrix &arr1);
	Matrix operator++ ();
};

istream &operator >> (istream &is, Matrix &obj) {
	cout << "Nhap vao so dong, so cot cua ma tran: ";
	cin >> obj.dong >> obj.cot;
	//Cap phat dong
	obj.arr = new int* [obj.dong];
	for (int i = 0; i < obj.dong; i++) {
		obj.arr[i] = new int [obj.cot];
	}
	//Nhap ma tran
	for (int i = 0; i < obj.dong; i++) {
		for (int j = 0; j < obj.cot; j++) {
			cout << "Nhap a[" << i << "][" << j << "]: ";
			cin >> obj.arr[i][j];
		}
	}
	return is;
}

ostream &operator << (ostream &os, Matrix &obj) {
	//Xuat ma tran
	cout << "\nMA TRAN VUA NHAP: " << endl;
	for (int i = 0; i < obj.dong; i++) {
		for (int j = 0; j < obj.cot; j++) {
			cout << left;
			cout << setw(5) << obj.arr[i][j];
		}
		cout << endl << endl;
	}
	return os;
}

Matrix operator-- (Matrix &arr1) {
	int j = 0;
	for (int k = 0; k < arr1.dong; k++) {
		for (int h = 0; h < arr1.cot; h++) {
			for (int i = k; i < arr1.dong; i++) {
				if (i == k) {
					j = h + 1;
				}
				else {
					j = 0;
				}
				for (; j < arr1.cot; j++) {
					if (arr1.arr[k][h] < arr1.arr[i][j]) {
						swap(arr1.arr[k][h], arr1.arr[i][j]);
					}
				}
			}
		}
	}
	return arr1;
}


int main() {
	Matrix mt1;
	
	cin >> mt1;
	--mt1;
	
	cout << mt1;
	return 0;
}

