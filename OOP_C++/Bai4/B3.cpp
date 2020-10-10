#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Date
{
private:
	int day;
	int month;
	int year;	
friend class Hang;
friend int main();
};

class Hang
{
private:
	string maHang;
	string tenHang;
	Date ngaySx;
public:
	void nhap();
	void xuat();
friend int main();
};

void Hang::nhap()
{
	cout << "Nhap vao Ma Hang: ";
	getline(cin, maHang);
	
	cout << "Nhap vao Ten Hang: ";
	getline(cin, tenHang);
	
	cout << "Nhap lan luot Ngay Thang Nam San Xuat: ";
	cin >> ngaySx.day >> ngaySx.month >> ngaySx.year;
	cin.ignore();
}

void Hang::xuat()
{
	cout << left;
	cout << setw(15) << maHang
	<< setw(15) << tenHang
	<< ngaySx.day << "/" << ngaySx.month << "/" << ngaySx.year << endl;
}

int main()
{
	Hang h1[100];
	int n;
	cout << "Nhap vao so mat hang: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout << "\n==========================MAT HANG " << i + 1 << "==========================" << endl;
		h1[i].nhap();		
	}
	
	cout << "\n=========================MAT HANG SAN XUAT NAM 2017=============================" << endl;
	cout << left;
	cout << setw(15) << "MA HANG"
	<< setw(15) << "TEN HANG"
	<< "NGAY SAN XUAT" << endl;
	for (int i = 0; i < n; i++) {
		if (h1[i].ngaySx.year == 2017)
			h1[i].xuat();	
	}
	return 0;
}

