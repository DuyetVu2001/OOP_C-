#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class MaTran {
private: 
	double **a;
	int m, n;
	
public: 
	friend istream &operator >> (istream &is, MaTran &obj) {
		cout << "+ Nhap vao lan luot so dong va so cot cua ma tran: ";
		is >> obj.m >> obj.n;
		//Cap phat dong cho dong (m)
		obj.a = new double* [obj.m];
		for (int i = 0; i < obj.m; i++) {
			obj.a[i] = new double[obj.n];
		}
		//Nhap ma tran
		for (int i = 0; i < obj.m; i++) {
			for (int j = 0; j < obj.n; j++) {
				cout << "+ Nhap a[" << i << "][" << j << "]: ";
				is >> obj.a[i][j];
			}
		}
		return is;
	}
	friend ostream &operator << (ostream &os, MaTran &obj) {
		//Xuat ma tran
		for (int i = 0; i < obj.m; i++) {
			for (int j = 0; j < obj.n; j++) {
				os << obj.a[i][j] << "   ";
			}
			cout << endl << endl;
		}
		return os;
	}
	MaTran operator* (MaTran &mt2) {
		MaTran mt3;
		mt3.m = m;
		mt3.n = mt2.n;
		mt3.a = new double* [mt3.m];
		for (int i = 0; i < mt3.m; i++) {
			mt3.a[i] = new double[mt3.n];
		}
		//nhan
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < mt2.n; j++) {
				for (int l = 0; l < n; l++) {
					mt3.a[i][j] += a[i][l] * mt2.a[l][j];
				}
			}
		}
		return mt3;
	}
};

int main() {
	MaTran mt1, mt2, mt3;
	cin >> mt1 >> mt2;
	mt3 = mt1 * mt2;
	cout << mt3;
	return 0;
}

