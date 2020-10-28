#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class SanPham
{
protected:
	string tenSP;
	int namSX;
	long giaThanh;
};

class HoaDon : public SanPham
{
private:
	long slBan, giaBan;
public:
	long tinhThanhTien() {
		return this->slBan * this->giaBan;
	} 
	long tienThue() {
		return tinhThanhTien() * 10 / 100;
	}
	long tinhLai() {
		return this->slBan * (this->giaThanh - this->giaBan);
	}
	void nhap() {
		cout << "Nhap vao ten sp: ";
		getline(cin, tenSP);
		
		cout << "Nhap vao nam sx: ";
		cin >> namSX;
		
		cout << "Nhap vao gia thanh: ";
		cin >> giaThanh;
		
		cout << "Nhap vao so luong ban: ";
		cin >> slBan;
		
		cout << "Nhap vao gia ban: ";
		cin >> giaBan;
		cin.ignore();
	}
	void xuat() {
		cout << left;
		cout << setw(15) << tenSP
		<< setw(15) << namSX
		<< setw(15) << giaThanh
		<< setw(15) << slBan
		<< setw(15) << giaBan
		<< setw(15) << tinhThanhTien() 
		<< setw(15) << tienThue()
		<< setw(15) << tinhLai() << endl;
	}
};

void title()
{
	cout << endl;
	cout << left;
	cout << setw(15) << "TEN SP"
	<< setw(15) << "NAM SX"
	<< setw(15) << "GIA THANH"
	<< setw(15) << "SL BAN"
	<< setw(15) << "GIA BAN"
	<< setw(15) << "THANH TIEN"
	<< setw(15) << "TIEN THUE"
	<< setw(15) << "TIEN LAI" << endl;
}

void sapXepTienLaiGiam(HoaDon *ba, int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ba[i].tinhLai() < ba[j].tinhLai()) {
				swap (ba[i], ba[j]);
			}
		}
	}
}

int main()
{
	HoaDon hd[100];
	int n;
	
	cout << "Nhap vao so luong hoa don: ";
	cin >> n;
	cin.ignore();
	//Nhap thong tin
	for (int i = 0; i < n; i++) {
		cout << "\nNHAP TT HOA DON " << i + 1 << ".\n";
		hd[i].nhap();
	}
	//Sap xep lai giam dan
	sapXepTienLaiGiam(hd, n);
	title();
	for (int i = 0; i < n; i++) {
		hd[i].xuat();
	}
	//
	return 0;
}

