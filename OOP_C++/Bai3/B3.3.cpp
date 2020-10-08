#include <iostream>
using namespace std;
#include <string>

class Hang 
{
private:
	string maNSx;
	string tenNSx;
	string dcNSx;
public: 
	void nhap();
	void xuat();
};

void Hang::nhap() {
	cout << "Nhap vao ma hang: ";
	getline(cin, maNSx);
	
	cout << "Nhap vao ten nha san xuat: ";
	getline(cin, tenNSx);
	
	cout << "Nhap vao dia chi nha san xuat: ";
	getline(cin, dcNSx); 
}

void Hang::xuat() {
	cout << "Ma nha san xuat: " << this->maNSx << endl;
	cout << "Ten nha san xuat: " << this->tenNSx << endl;
	cout << "Dia chi nha san xuat: " << this->dcNSx << endl;
	cout << "===============================" << endl;
}

class Phieu
{
private:
	string maPhieu;
	Hang x[100];
	int n;
public:
	void nhap();
	void xuat();
		
};

void Phieu::nhap() {
	cout << "Nhap vao ma phieu: ";
	getline(cin, maPhieu);
	
	cout << "Nhap n: ";
	cin >> n;
	cin.ignore();
	for(int i = 0; i < n; i++) {
		cout << "MAT HANG " << i + 1 << endl;
		x[i].nhap();
		cout << endl;
	}
}

void Phieu::xuat() {
	cout << "===============================" << endl;
	cout << "Ma phieu: " << maPhieu << endl;
	cout << "===============================" << endl;
	for(int i = 0; i < n; i++) {
		cout << "MAT HANG " << i + 1 << endl;
		x[i].xuat();	
	}	
}

int main() {
	Phieu phieu1;
	phieu1.nhap();
	
	phieu1.xuat();	
}
