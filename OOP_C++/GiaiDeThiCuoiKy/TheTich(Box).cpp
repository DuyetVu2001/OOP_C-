#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

// + -- * 

class HCN {
private:
	int a, b, c, theTich;
	
public:
	int getTheTich();
	friend ostream &operator << (ostream &os, HCN &obj);
	friend istream &operator >> (istream &is, HCN &obj);
	HCN operator+ (HCN &hcn2);
	friend HCN operator* (HCN &hcn1, HCN &hcn2);
	HCN operator-- ();
	friend HCN operator++ (HCN &hcn1);
};

int HCN::getTheTich() {
	this->theTich = a * b * c;
	return this->theTich;
}

ostream &operator << (ostream &os, HCN &obj) {
	os << "The tich HCN: " << obj.theTich;
	return os;
}

istream &operator >> (istream &is, HCN &obj) {
	cout << "Nhap vao lan luot chieu dai, rong, cao cua HCN: ";
	is >> obj.a >> obj.b >> obj.c;
	obj.getTheTich();
	return is;
}

HCN HCN::operator+ (HCN &hcn2) {
	HCN hcn3;
	hcn3.theTich = getTheTich() + hcn2.getTheTich();
	return hcn3;
}

HCN operator* (HCN &hcn1, HCN &hcn2) {
	HCN hcn3;
	hcn3.theTich = hcn1.getTheTich() * hcn2.getTheTich();
	return hcn3;
}

HCN HCN::operator-- () {
	theTich = getTheTich() - 1;
}

HCN operator++ (HCN &hcn1) {
	hcn1.theTich = hcn1.getTheTich() + 1;
	return hcn1;
}

int main() {
	HCN hcn, hcn1, hcn2;
	cin >> hcn1;
	cout << hcn1;
	return 0;
}
