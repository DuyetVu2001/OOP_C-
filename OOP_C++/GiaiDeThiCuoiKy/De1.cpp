#include <bits/stdc++.h>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;

public:
	void nhap() {
		cout << "+ Nhap vao lan luot ngay, thang, nam sinh: ";
		cin >> day >> month >> year;;
		cin.ignore();
	} 
	void xuat() {
		cout << day << "/" << month << "/" << setw(12) << year;
	}
	int getYear() {
		return year;
	}
};

class CongDan {
private:
	string cmnd;
	string hoTen;
	Date ngSinh;
	string hoKhau;
	
public:
	void nhap() {
		cout << "+ Nhap CMND: ";
		getline(cin, cmnd);
		cout << "+ Nhap ho ten: ";
		getline(cin, hoTen);
		ngSinh.nhap();
		cout << "+ Nhap ho khau: ";
		getline(cin, hoKhau);
	}
	void xuat() {
		cout << left;
		cout << setw(15) << cmnd
		<< setw(25) << hoTen;
		ngSinh.xuat();
		cout << setw(15) << hoKhau;
	}
	Date getNgSinh() {
		return ngSinh;
	}
};

class XeHoi {
private:
	CongDan chuSoHuu;
	string bienSo;
	string tenHang;
	
public:
	void nhap() {
		chuSoHuu.nhap();
		cout << "+ Nhap bien so: ";
		getline(cin, bienSo);
		cout << "+ Nhap ten hang: ";
		getline(cin, tenHang);
	}
	void xuat() {
		chuSoHuu.xuat();
		cout << setw(15) << bienSo
		<< setw(15) << tenHang << endl;
	}
	CongDan getChuSoHuu() {
		return chuSoHuu;
	}
	string getTenHang() {
		return tenHang;
	}
};

void title() {
	cout << left;
	cout << setw(15) << "CMND"
	<< setw(25) << "Ho ten"
	<< setw(15) << "Sinh nhat"
	<< setw(15) << "Ho khau"
	<< setw(15) << "Bien so"
	<< setw(15) << "Ten hang" << endl;
}

int main() {
	XeHoi xh[100];
	int n;
	cout << "- Nhap vao so xe hoi: ";
	cin >> n;
	cin.ignore();
	//Nhap
	for (int i = 0; i < n; i++) {
		cout << "\n- NHAP TT XE HOI " << i + 1 << ". " << endl;
		xh[i].nhap();
	}
	//Xuat
	cout << endl;
	title();
	for (int i = 0; i < n; i++) {
		xh[i].xuat();
	}
	//Honda && 1985
	cout << endl;
	title();
	for (int i = 0; i < n; i++) {
		if (xh[i].getChuSoHuu().getNgSinh().getYear() == 1985 && xh[i].getTenHang() == "Honda") {
			xh[i].xuat();
		}
	}
}
