#include <iostream>
using namespace std;

class PhanSo
{
private:
	float tu;
	float mau;
public:
	PhanSo() {
		tu = 0;
		mau = 1;
	}
	
	PhanSo(float a, float b) {
		this->tu = a;
		this->mau = (b == 0) ? 1 : b;
	}
	
	void showInfo() {
		cout << tu << "/" << mau << endl;
	}
	
	PhanSo operator+ (PhanSo const&); // Chuyen tham chi co dinh
	friend PhanSo operator- (PhanSo const&, PhanSo const&);
};

PhanSo PhanSo::operator+ (PhanSo const& b)
{
	PhanSo x;
	x.tu = tu*b.mau + b.tu*mau;
	x.mau = mau * b.mau;
	return x;	
}

PhanSo operator- (PhanSo const& a, PhanSo const& b)
{
	PhanSo x;
	x.tu = a.tu*b.mau - b.tu*a.mau;
	x.mau = a.mau * b.mau;
	return x;
}

int main()
{
	PhanSo a(1, 2);
	PhanSo b(2, 3);
	PhanSo tong = a + b;
	PhanSo hieu = a - b;
	
	tong.showInfo();
	hieu.showInfo();
	return 0;
}

