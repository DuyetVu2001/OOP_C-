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
friend class Hang;
};

class Hang
{
private:
	string maHang;
	string tenHang;
	string donGia;
	double trongLuong;
	NSX nsx;
public:
	void nhap() {
		cout << "Nhap vao Ma Hang: ";
		getline(cin, maHang);
		
		cout << "Nhap vao Ten Hang: ";
		getline(cin, tenHang);
		
		cout << "Nhap vao Don Gia: ";
		getline(cin, donGia);
		
		cout << "Nhap vao Trong Luong: ";
		cin >> trongLuong;
		cin.ignore();
		
		cout << "Nhap vao Ma Nha San Xuat: ";
		getline(cin, nsx.maNsx);
		
		cout << "Nhap vao Ten Nha San Xuat: ";
		getline(cin, nsx.tenNsx);
		
		cout << "Nhap vao Dia Chi Nha San Xuat: ";
		getline(cin, nsx.dcNsx);
	}
	
	void xuat() {
		cout << left;
		cout << setw(15) << maHang
		<< setw(20) << tenHang
		<< setw(15) << donGia
		<< setw(15) << trongLuong
		<< setw(15) << nsx.maNsx
		<< setw(20) << nsx.tenNsx
		<< setw(15) << nsx.dcNsx << endl;
	}
};

int main()
{
	Hang h1;
	
	h1.nhap();
	
	cout << "\n\n============================================================" << endl;
	cout << left;
	cout << setw(15) << "Ma Hang"
	<< setw(20) << "Ten Hang"
	<< setw(15) << "Don Gia"
	<< setw(15) << "Trong Luong"
	<< setw(15) << "Ma NSX"
	<< setw(20) << "Ten NSX"
	<< setw(15) << "Dia Chi NSX" << endl;
	h1.xuat();
	return 0;
}

