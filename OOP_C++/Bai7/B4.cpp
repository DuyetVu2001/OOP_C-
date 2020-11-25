#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Date {
private:
	int d, m, y;
	
public:
	void nhap() {
		cout << "Nhap vao lan luot ngay thang nam: ";
		cin >> d >> m >> y;	
		cin.ignore();
	}
	void xuat()	{
		cout << d << "/" << m << "/" << y << endl;
	}
};

class ThongTin {
private:
	string tenHang;
	double donGia;
	int soLuong;
	
public:
	double thanhTien() {
		return donGia * soLuong;
	}
	void nhap() {
		cout << "+ Ten hang: ";
		getline(cin, tenHang);
		cout << "+ Don gia: ";
		cin >> donGia;
		cout << "+ So luong: ";
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
};

class Phieu{
private:
	Date date;
	string maPhieu;
	ThongTin tt[100];
	int n;
public:
	Date getDate() {
		return date;
	}
	void nhap() {
		date.nhap();
		cout << "+ Ma phieu: ";
		getline(cin, maPhieu);
		
		cout << "Nhap vao so mat hang: ";
		cin >> n;
		cin.ignore();
		for (int i = 0; i < n; i++) {
			cout << "- NHAP VAO THONG TIN MAT HANG " << i + 1 << ".\n";
			tt[i].nhap();
		}
	}
	double congThanhTien() {
		double sum = 0;
		for (int i = 0; i < n; i++) {
			sum += tt[i].thanhTien();
		}
		return sum;
	}
	string getMaPhieu() {
		return maPhieu;
	}
	void xuat() {
		for (int i = 0; i < n; i++) {
			tt[i].xuat();
		}
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
	Phieu p1;
	p1.nhap();
	
	cout << "\n\t\tPHIEU MUA HANG" << endl;
	
	cout << "Ma phieu: " << p1.getMaPhieu();
	cout << "\t\tNgay lap: ";
	p1.getDate().xuat();
	
	title();
	p1.xuat();
	
	cout << right << setw(42) << "Cong thanh tien " << setw(5) << p1.congThanhTien();
	
	return 0;
}
