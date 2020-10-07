#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class NSX
{
private:
	string maNsx;
	string tenNsx;
	string dcNsx;
public:
	void nhap() {
		cout << "Nhap vao Ma nha san xuat: ";
		getline(cin, maNsx);
		
		cout << "Nhap vao Ten nha san xuat: ";
		getline(cin, tenNsx);
		
		cout << "Nhap vao Dia Chi nha san xuat: ";
		getline(cin, dcNsx);
	}
	
	void xuat() {
		cout << setw(15) << maNsx
		<< setw(20) << tenNsx
		<< setw(20) << dcNsx;
	}
};

class Hang
{
private:
	string maHang;
	string tenHang;
	NSX nsx;
public:
	void nhap()	{
		cout << "Nhap vao ma hang: ";
		getline(cin, maHang);
		
		cout << "Nhap vao ten hang: ";
		getline(cin, tenHang);
		
		nsx.nhap();
	}
	
	void xuat() {
		cout << left;
		cout << setw(15) << maHang
		<< setw(20) << tenHang;
		nsx.xuat();
	}
};

int main()
{
	Hang nsx1;
	
	nsx1.nhap();
	
	cout << "=========================================================================================" << endl;
	cout << left;
	cout << setw(15) << "MA HANG"
	<< setw(20) << "TEN HANG"
	<< setw(15) << "MA NSX"
	<< setw(20) << "TEN NSX"
	<< setw(20) << "DIA CHI NSX" << endl;
	nsx1.xuat();
	return 0;
}

