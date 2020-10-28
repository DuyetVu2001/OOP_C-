#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Printer
{
protected:
	double trongLuong;
	string hangSx;
	int namSx;
	int tocDo;		
};

class DotPrinter : public Printer
{
private:
	int matDoKim;
public:
	void nhap();
	void xuat();
};

void DotPrinter::nhap()
{
	cout << "Trong luong: ";
	cin >> trongLuong;
	cin.ignore();
	
	cout << "Hang Sx: ";
	getline(cin, hangSx);
	
	cout << "Nam Sx: ";
	cin >> namSx;
	
	cout << "Toc do (so trang/ phut): ";
	cin >> tocDo;
	
	cout << "Mat do kim: ";
	cin >> matDoKim;
}

void DotPrinter::xuat()
{
	cout << left;
	cout << setw(20) << trongLuong
	<< setw(15) << hangSx
	<< setw(15) << namSx
	<< setw(15) << tocDo
	<< setw(20) << matDoKim;
}

class LaserPrinter : public Printer
{
private:
	int doPhanGiai;
public:
	void nhap();
	void xuat();
};

void LaserPrinter::nhap()
{
	cout << "Trong luong: ";
	cin >> trongLuong;
	cin.ignore();
	
	cout << "Hang Sx: ";
	getline(cin, hangSx);
	
	cout << "Nam Sx: ";
	cin >> namSx;	
	cout << "Toc do (so trang/ phut): ";
	cin >> tocDo;
	
	cout << "Do phan giai: ";
	cin >> doPhanGiai;	
}

void LaserPrinter::xuat()
{
	cout << left;
	cout << setw(20) << trongLuong
	<< setw(15) << hangSx
	<< setw(15) << namSx
	<< setw(15) << tocDo
	<< setw(20) << doPhanGiai;
}

int main()
{
	LaserPrinter ls;
	DotPrinter dot;
	
	cout << "================NHAP THONG TIN MAY IN LASER==================" << endl;
	ls.nhap();
	cout << "\n================NHAP THONG TIN MAY IN LASER==================" << endl;
	dot.nhap();
	
	cout << "\n\n=================================THONG TIN MAY IN LASER=================================" << endl;
	cout << left;
	cout << setw(20) << "TRONG LUONG"
	<< setw(15) << "HANG SX"
	<< setw(15) << "NAM SX"
	<< setw(15) << "TOC DO"
	<< setw(20) << "DO PHAN GIAI" << endl;
	ls.xuat();
	
	cout << "\n\n=================================THONG TIN MAY IN DOT=================================" << endl;
	cout << left;
	cout << setw(20) << "TRONG LUONG"
	<< setw(15) << "HANG SX"
	<< setw(15) << "NAM SX"
	<< setw(15) << "TOC DO"
	<< setw(20) << "MAT DO KIM" << endl;
	dot.xuat();
	return 0;
}

