#include <iostream>
using namespace std;

class PS 
{
private:
	float tu, mau;
public:
	void nhap() {
		cout << "Nhap vao tu va mau: ";
		cin >> tu >> mau;
	}
	
	void xuat() {
		cout << tu << "/" << mau;
	}
	
	PS operator + (PS y) {
		PS z;
		z.tu = tu*y.mau + mau*y.tu;
		z.mau = mau * y.mau;
		return z;
	}
};

int main()
{
	PS a, b, z;
	a.nhap();
	b.nhap();
	
	z = a + b;
	z.xuat();
	return 0;
}

