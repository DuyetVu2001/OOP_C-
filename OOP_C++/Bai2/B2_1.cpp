#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <math.h>

class PTB2
{
private:
	float a, b, c, x1, x2;
public:
	void nhap() {
		cout << "Nhap vao lan luot a, b, c: ";
		cin >> a >> b >> c;
	}
	float getA() {
		return a;
	}
	float getB() {
		return b;
	}
	float getC() {
		return c;
	}
	void setX1(float x1) {
		this->x1 = x1;
	}
	void setX2(float x2) {
		this->x2 = x2;
	}
	void xuat() {
		cout << "X1 = " << x1 << endl;
		cout << "X2 = " << x2 << endl;
	}
};

int main()
{
	PTB2 pt1;
	pt1.nhap();
	float delta, x1, x2;
	delta = pt1.getB() * pt1.getB() - 4 * pt1.getA() * pt1.getC();
	
	cout << "delta = " << delta << endl;
	if (delta > 0) {
		x1 = (-pt1.getB() + sqrt(delta)) / (2 * pt1.getA());
		x2 = (-pt1.getB() - sqrt(delta)) / (2 * pt1.getA());
		cout << "X1 = " << fixed << x1 << endl;
		cout << "X2 = " << fixed << x2 << endl;
	}
	else if (delta == 0) {
		x1 = x2 = -pt1.getB() / 2 * pt1.getA();
		cout << "X1 = X2 = " << x1;
	}
	else {
		cout << "Phuong trinh vo nghiem!";
	}
}








