#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Date {
private: 
	int d, m, y;
	
public: 
	int getY() {
		return this->y;
	}
	void nhap () {
		cout << "+ Nhap vao lan luot ngay thang, nam, sinh: ";
		cin >> d >> m >> y;
		cin.ignore();
	}
	void xuat () {
		cout << d << "-" << m << "-" << y;
	}
};

class CongDan {
private:
	string cmnd, hoTen, hoKhau;
	Date date;
		
public: 
	Date getDate () {
		return this->date;
	}
	void nhap() {
		cout << "+ Nhap vao cmnd: ";
		getline(cin, cmnd);
		
		cout << "+ Nhap vao ho ten: ";
		getline(cin, hoTen);
		
		cout << "+ Nhap vao ho khau thuong tru: ";
		getline(cin, hoKhau);
		
		date.nhap();
	}
	void xuat() {
		cout << left;
		cout << setw(15) << cmnd
		<< setw(25) << hoTen
		<< setw(15) << hoKhau;
		date.xuat();
		cout << endl;
	}
};

class XeHoi {
private:
	string bienSo, tenHang;
	CongDan chuSoHuu;
		
public: 
	string getTenHang () {
		return this->tenHang;
	}
	CongDan getChuSoHuu () {
		return this->chuSoHuu;
	}
	void nhap() {
		cout << "+ Nhap vao bien so: ";
		getline(cin, bienSo);
		
		cout << "+ Nhap vao ten hang: ";
		getline(cin, tenHang);
		
		chuSoHuu.nhap();
	}
	void xuat() {
		cout << left;
		cout << setw(15) << bienSo
		<< setw(15) << tenHang;
		chuSoHuu.xuat();
	}
};

void title() {
	cout << left;
	cout << setw(15) << "Bien So"
	<< setw(15) << "Ten Hang"
	<< setw(15) << "CMND"
	<< setw(25) << "Ho Ten"
	<< setw(15) << "Ho Khau"
	<< "Ngay sinh" << endl;
}

void nhapXe(XeHoi xh[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n- NHAP VAO XE HOI THU " << i + 1 << " .\n";
		xh[i].nhap();
	}
}

void xuatXe(XeHoi xh[], int n) {
	cout << endl;
	title();
	for (int i = 0; i < n; i++) {
		xh[i].xuat();
	}
}

void honDa1985(XeHoi xh[], int n) {
	cout << endl;
	cout << "--------HONDA 1985" << endl;
	title();
	for (int i = 0; i < n; i++) {
		if (xh[i].getTenHang() == "Honda" && xh[i].getChuSoHuu().getDate().getY() == 1985) {
			xh[i].xuat();
		}
	}
}

int main() {
	int n = 0;
	XeHoi xh[100];
	
	cout << "Nhap vao so xe hoi: ";
	cin >> n;
	cin.ignore();
	
	nhapXe(xh, n);
	xuatXe(xh, n);

	honDa1985(xh, n);
	return 0;
}

