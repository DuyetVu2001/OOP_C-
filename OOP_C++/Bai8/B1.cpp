#include <bits/stdc++.h>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
	
public:
	void nhap() {
		cout << "+ Nhap vao lan luot ngay, thang, nam thanh lap: ";
		cin >> day >> month >> year;
		cin.ignore();
	}
	void xuat() {
		cout << day << "/" << month << "/" << year << endl;
	}
};

class SanPham {
private:
	string tenHang;
	double donGia;
	int soLuong;

public:
	void nhap() {
		cout << "+ Nhap ten hang: ";
		getline(cin, tenHang);
		cout << "+ Nhap don gia: ";
		cin >> donGia;
		cout << "+ Nhap so luong: ";
		cin >> soLuong;
		cin.ignore();
	}
	void xuat() {
		cout << left;
		cout << setw(15) << tenHang
		<< setw(15) << donGia
		<< setw(15) << soLuong 
		<< thanhTien() << endl;
	}
	double thanhTien() {
		return donGia * soLuong;
	}
};

class Phieu {
private:
	string maPhieu;
	Date date;
	string maNCC;
	string tenNCC;
	string diaChi;
	SanPham sp[100];
	int n;
	
public:
	void nhap()	{
		cout << "+ Nhap ma phieu: ";
		getline(cin, maPhieu);
		date.nhap();
		cout << "+ Nhap ma NCC: ";
		getline(cin, maNCC);
		cout << "+ Nhap ten NCC: ";
		getline(cin, tenNCC);
		cout << "+ Nhap dia chi: ";
		getline(cin, diaChi);
		
		cout << "\n- Nhap vao so san pham: ";
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cout << "- NHAP SP " << i + 1 << ".\n";
			sp[i].nhap();
		}
	}
	void xuat() {
		for (int i = 0; i < n; i++) {
			sp[i].xuat();
		}
	}
	string getMaPhieu() {
		return maPhieu;
	}
	Date getDate()	{
		return date;
	}
	string getMaNCC() {
		return maNCC;
	}
	string getTenNCC() {
		return tenNCC;
	}
	string getDiaChi() {
		return diaChi;
	}
	double congThanhTien() {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum += sp[i].thanhTien();
		}
		return sum;
	}
};

void title() {
	cout << left;
	cout << setw(15) << "Ten hang"
	<< setw(15) << "Don gia"
	<< setw(12) << "So luong" 
	<< "Thanh tien" << endl;
}

int main() {
	Phieu p;
	p.nhap();
	
	cout << endl << "\t\tPHIEU NHAP HANG" << endl;
	//dong 1
	cout << "Ma phieu: " << p.getMaPhieu();
	cout << "\t\tNgay nhap: ";
	p.getDate().xuat();
	//dong 2
	cout << "Ma NCC: " << p.getMaNCC();
	cout << "\t\tTen NCC: " << p.getTenNCC() << endl;
	//dong 3 
	cout << "Dia chi: " << p.getDiaChi() << endl;
	//bang
	title();
	p.xuat();
	cout << right << setw(41) << "Cong thanh tien" << setw(5) << p.congThanhTien();
}
