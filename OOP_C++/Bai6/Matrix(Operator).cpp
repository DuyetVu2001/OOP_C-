#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Matrix {
private:
	float **a;
	int n;
public:
	Matrix();
	int getN() {
		return this->n;
	}
	friend istream &operator>> (istream &is, Matrix &obj);
	friend ostream &operator<< (ostream &os, Matrix &obj);
	friend Matrix operator+ (Matrix &matrix1, Matrix &matrix2);
	Matrix operator* (Matrix &matrix2);
};

Matrix::Matrix() {
	
}

istream &operator>> (istream &is, Matrix &obj) {
	cout << "Ma tran vuong cap n. Nhap n: ";
	cin >> obj.n;
	//Cap phat dong
	obj.a = new float* [obj.n];
	for (int i = 0; i < obj.n; i++) {
		obj.a[i] = new float [obj.n];
	}
	//Nhap vao ma tran
	for (int i = 0; i < obj.n; i++) {
		for (int j = 0; j < obj.n; j++) {
			cout << "Nhap a[" << i << "][" << j << "]: ";
			cin >> obj.a[i][j];
		}
	}
	return is;
}

ostream &operator<< (ostream &os, Matrix &obj) {
	for (int i = 0; i < obj.n; i++) {
		for (int j = 0; j < obj.n; j++) {
			cout << left;
			cout << setw(5) << obj.a[i][j];
		}
		cout << endl << endl;
	}
	return os;
}

Matrix operator+ (Matrix &matrix1, Matrix &matrix2) {
	Matrix matrix3;
	//Gan dong, cot cua mt3 nhu mt1
	matrix3.n = matrix1.n;
	//Cap phat dong
	matrix3.a = new float* [matrix3.n];
	for (int i = 0; i < matrix3.n; i++) {
		matrix3.a[i] = new float [matrix3.n];
	}
	//Thuc hien phep cong
	for (int i = 0; i < matrix3.n; i++) {
		for (int j = 0; j < matrix3.n; j++) {
			matrix3.a[i][j] = matrix1.a[i][j] + matrix2.a[i][j];
		}
	}
	return matrix3;
}

Matrix Matrix::operator* (Matrix &matrix2) {
	Matrix matrix3;
	matrix3.n = n;
	//Cap phat dong
	matrix3.a = new float* [matrix3.n];
	for (int i = 0; i < matrix3.n; i++) {
		matrix3.a[i] = new float [matrix3.n];
	}
	//Thuc hien phep nhan
	for (int i = 0; i < matrix3.n; i++) {
		for (int k = 0; k < matrix3.n; k++) {
			for (int j = 0; j < matrix3.n; j++) {
				matrix3.a[i][k] += a[i][j] * matrix2.a[j][k];
			}
		}
	}
	return matrix3;
}

int main() {
	Matrix mt1, mt2, mt3;
	cin >> mt1;
	cin >> mt2;
	
	if (mt1.getN() == mt2.getN()) {
		cout << "Cong hai ma tran: \n";
		mt3 = mt1 + mt2;
		cout << mt3;
		
		cout << "Nhan hai ma tran: \n";
		mt3 = mt1 * mt2;
		cout << mt3;
	}
	else {
		cout << "Khong the thuc hien phep cong va phep nhan!!" << endl;
	}
	return 0;
}

