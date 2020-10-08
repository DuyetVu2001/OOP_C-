#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class QuanLy
{
private:
	string maQl;
	string hoTen;
public:
	void nhap() {
		cout << "Nhap vao Ma Quan Ly: ";
		getline(cin, maQl);
		
		cout << "Nhao vao Ho Ten: ";
		getline(cin, hoTen);
	}
	
	void xuat() {
		cout << setw(15) << maQl
		<< setw(25) << hoTen;
	}
};

class May
{
private:
	string maMay;
	string kieuMay;
	string tinhTrang;
public:
	void nhap() {
		cout << "Nhap vao Ma May: ";
		getline(cin, maMay);
		
		cout << "Nhap vao Kieu May: ";
		getline(cin, kieuMay);
		
		cout << "Nhap vao Tinh Trang: ";
		getline(cin, tinhTrang);
	}
	
	void xuat() {
		cout << setw(15) << maMay
		<< setw(15) << kieuMay
		<< setw(15) << tinhTrang;
	}
};

class PhongMay
{
private:
	string maPhong;
	int tenPhong;
	double dienTich;
	QuanLy x;
	May y[100];
	int n;
public:
	void nhap() {
		cout << "Nhao vao Ma Phong: ";
		getline(cin, maPhong);
		
		cout << "Nhap vao Ten Phong: ";
		cin >> tenPhong;
		
		cout << "Nhap vao Dien Tich: ";
		cin >> dienTich;
		cin.ignore();
		
		x.nhap();
		
		cout << "Nhap vao so may n: ";
		cin >> n;
		cin.ignore();
		
		for (int i = 0; i < n; i++) {
			cout << "===============================MAY " << i + 1 << "===============================" << endl;
			y[i].nhap();
		}
	}
	
	void xuat() {
		cout << left;
		cout << setw(15) << maPhong
		<< setw(20) << tenPhong
		<< setw(15) << dienTich;
		x.xuat();	
	}
	
	void xuatThongTinMay() {
		for (int i = 0; i < n; i++) {
			cout << endl;
			cout << left;
			cout << setw(10) << i + 1;
			y[i].xuat();
		}
	}
};

int main()
{
	PhongMay pm1;
	pm1.nhap();
	
	cout << "\n\n==========================THONG TIN PHONG================================" << endl;
	cout << left;
	cout << setw(15) << "MA PHONG"
	<< setw(20) << "TEN PHONG"
	<< setw(15) << "DIEN TICH"
	<< setw(15) << "MA QL"
	<< setw(25) << "HO TEN" << endl;
	pm1.xuat();
	
	cout << "\n\n==========================THONG TIN MAY TRONG PHONG=======================" << endl;
	cout << left;
	cout << setw(10) << "MAY SO"
	<< setw(15) << "MA MAY"
	<< setw(15) << "KIEU MAY"
	<< setw(15) << "TINH TRANG";
	pm1.xuatThongTinMay();
	
	return 0;
}
