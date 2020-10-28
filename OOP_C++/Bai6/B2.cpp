#include <iostream>
using namespace std;

class PhanSo
{
private:
	float tu, mau;
public:
	PhanSo () {	
		tu = 0;
		mau = 1;
	};
	PhanSo (float a, float b) {
		this->tu = a;
		this->mau = (b == 0) ? 1 : b;
	}
	friend istream &operator>> (istream &is, PhanSo &obj) {
		cout << "Nhap tu: ";
		is >> obj.tu;
		cout << "Nhap mau: ";
		is >> obj.mau;
		return is;
	}
	friend ostream &operator<< (ostream &os, PhanSo &obj) {
		os << obj.tu << "/" << obj.mau << endl;
		return os;
	}
	PhanSo operator+ (PhanSo const& b) { //Chuyen vao tham chieu khong the thay doi gia tri
		PhanSo x;
		x.tu = tu*b.mau + b.tu*mau;
		x.mau = mau*b.mau;
		return x;
	}
	PhanSo operator- (PhanSo const& b) {
		PhanSo x;
		x.tu = tu*b.mau - b.tu*mau;
		x.mau = mau*b.mau;
		return x;
	}
	friend PhanSo operator* (PhanSo const& a, PhanSo const& b) {
		PhanSo x;
		x.tu = a.tu * b.tu;
		x.mau = a.mau * b.mau;
		return x;
	}
	friend PhanSo operator/ (PhanSo const& a, PhanSo const& b) {
		PhanSo x;
		x.tu = a.tu * b.mau;
		x.mau = a.mau * b.tu;
		return x;
	}
};

int main()
{
	PhanSo a(1, 2), b(2, 3);
	
	PhanSo c = a + b;
	cout << c;
	
	c = a - b;
	cout << c;
	
	c = a * b;
	cout << c;
	
	c = a / b;
	cout << c;
	return 0;
}

