#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class PhanSo {
private: 
	int tu, mau;
	
public:
	PhanSo () {
		tu = 0;
		mau = 1;
	}
	PhanSo (int tu, int mau) {
		this->tu = tu;
		this->mau = (mau > 0) ? mau : 1;	
	}	
	int ucln () {
		int a = this->tu, b = this->mau;
		
		while (a != b) {
			if (a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		
		return a;
	}
	friend istream &operator >> (istream &is, PhanSo &obj) {
		cout << "Nhap vao lan luot tu so, mau so: ";
		is >> obj.tu >> obj.mau;
	}
	friend ostream &operator << (ostream &os, PhanSo &obj) {
		os << obj.tu / obj.ucln() << "/" << obj.mau / obj.ucln();
	}
	PhanSo operator+ (PhanSo &ps2) {
		PhanSo ps3;
		ps3.tu = tu*ps2.mau + mau*ps2.tu;
		ps3.mau = mau*ps2.mau;		
		return ps3;
	}
};

int main() {
	PhanSo ps(2, 6), ps1, ps2;
	cin >> ps1;
	ps2 = ps + ps1;
	cout << ps2;
	return 0;
}

