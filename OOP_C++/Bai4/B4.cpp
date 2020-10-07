#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <math.h>

class PTB2
{
private:
	int a, b, c;
public:
	void nhap();
	void xuat();
	void giai();
	PTB2();
	PTB2(int a, int b, int c);
};

PTB2::PTB2() {
	this->a = 0;
	this->b = 0;
	this->c = 0;
}

PTB2::PTB2(int a, int b, int c) {
	this->a = a;
	this->b = b;
	this->c = c;
}

void PTB2::nhap() {
	cout << "\nNhap vao lan luot a, b, c: ";
	cin >> a >> b >> c;
}

void PTB2::xuat() {
	cout << "Phuong trinh vua nhap: " << a << "x^2+" << b << "x+" << c << "=0." << endl;
}

void PTB2::giai() {
	double delta = 0;
	double x1, x2;
	
	delta = b*b - 4*a*c;
	
	if (delta > 0) {
		x1 = (-b + sqrt(delta)) / 2*a;
		x2 = (-b - sqrt(delta)) / 2*a;
		
		cout << "Phuong trinh co hai nghiem phan biet: ";
		cout << "\nx1 = " << x1 << endl;
		cout << "x2 = " << x2 << endl;
	}
	else if (delta == 0) {
		x1 = x2 = -b / 2*a;
		
		cout << "Phuong trinh co nghiem kep: " << endl;
		cout << "x1 = x2 = " << x1;
	}
	else {
		cout << "Phuong trinh vo nghiem!" << endl;
	}
}

int main()
{
	PTB2 q, p(5, 3, -7);
	
	p.xuat();
	p.giai();
	
	q.nhap();
	q.xuat();
	q.giai();
}

