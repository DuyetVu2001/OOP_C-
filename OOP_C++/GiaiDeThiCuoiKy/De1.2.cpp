#include <bits/stdc++.h>
using namespace std;

class PhanSo {
private:
	int tu;
	int mau;
	
public:
	PhanSo() {
		tu = 0;
		mau = 1;
	}
	PhanSo(int tu, int mau) {
		this->tu = tu;
		this->mau = mau;
	}
	void nhap() {
		cout << "+ Nhap vao tu so: ";
		cin >> tu;
		cout << "+ Nhap vao mau so: ";
		cin >> mau;
	}
	PhanSo operator+ (PhanSo &ps2) {
		PhanSo ps3;
		ps3.tu = tu * ps2.mau + ps2.tu * mau;
		ps3.mau = mau * ps2.mau;
		return ps3;
	}
	int ucln(int a, int b) {
		if (a == 0 || b == 0) {
			return a + b;
		}
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
	void operator-- () {		
		int temp = ucln(tu, mau); // Tim uoc chung lon nhat
		tu /= temp;
		mau /= temp;		
	}
	friend ostream &operator << (ostream &os, PhanSo &obj) {
		os << obj.tu << "/" << obj.mau << endl;
		return os;
	}
};

int main() {
	PhanSo ps1, ps2(2, 3), ps3(6, 3);
	ps1.nhap();
	
	--ps3;	
	cout << ps3 << endl;
	ps3 = ps1 + ps2;
	cout << ps3;
	return 0;
}

