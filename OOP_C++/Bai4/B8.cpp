#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class PhongBan
{
private:
	int maPb;
	string tenPb;
	string truongPhong;
	int soNv;
friend class NhanVien;	
};

class Date 
{
private:
	int day;
	int month;
	int year;
friend class NhanVien;
};

class NhanVien
{
private:
	int maNv;
	string hoDem;
	string ten;
	Date ngaySinh;
	PhongBan phong;
public:
	void nhap() {
		cout << "MA NHAN VIEN: ";
		cin >> maNv;
		cin.ignore();
		
		cout << "HO DEM: ";
		getline(cin, hoDem);
		
		cout << "TEN: ";
		getline(cin, ten);
		
		cout << "NHAP VAO LAN LUOT NGAY THANG NAM SINH: ";
		cin >> ngaySinh.day >> ngaySinh.month >> ngaySinh.year;
		
		cout << "MA PHONG BAN: ";
		cin >> phong.maPb;
		cin.ignore();
		
		cout << "TEN PHONG BAN: ";
		getline(cin, phong.tenPb);
		
		cout << "TEN TRUONG PHONG: ";
		getline(cin, phong.truongPhong);
		
		cout << "SO NHAN VIEN: ";
		cin >> phong.soNv;
		cin.ignore();
	}
	
	void xuat() {
		cout << left;
		cout << setw(10) << maNv
		<< setw(20) << hoDem
		<< setw(10) << ten		 
		<< setw(15) << phong.maPb
		<< setw(15) << phong.tenPb		
		<< setw(20) << phong.truongPhong
		<< setw(10) << phong.soNv
		<< ngaySinh.day << "/" << ngaySinh.month << "/" << ngaySinh.year << endl;
	}
	
	string getTenPb() {
		return this->phong.tenPb;
	}
	
	string getTen() {
		return this->ten;
	}
	
	int getMaNv() {
		return this->maNv;
	}
};

void sapXepTenNhanVien(NhanVien a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].getTen() > a[j].getTen()) {
				swap(a[i], a[j]);
			}
		}
	}
}

void chenNhanVien(NhanVien *a, int n, int k) {
	for (int i = n; i > k; i--) {
		a[i] = a[i - 1];
	}
	
	a[k].nhap();
}

void xoaNhanVien(NhanVien *a, int n, int k) {
	for (int i = k; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
}

int main()
{
	NhanVien *nv;
	nv = new NhanVien[50];
	int n;
	
	cout << "Nhap vao so nhan vien: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "\n==============================NV " << i + 1 << "=================================" << endl;
		nv[i].nhap();
	}
	
	//HIEN THI NHAN VIEN PHONG TAI CHINH
	cout << "\n==========================THONG TIN NHAN VIEN PHONG TAI CHINH========================" << endl;
	cout << left;
	cout << setw(10) << "MA NV"
	<< setw(20) << "HO DEM"
	<< setw(10) << "TEN"		
	<< setw(15) << "MA PB"
	<< setw(15) << "TEN PB"		
	<< setw(20) << "TRUONG PHONG"
	<< setw(10) << "SO NV"
	<< "NGAY SINH" << endl;
	for (int i = 0; i < n; i++) {
		if (nv[i].getTenPb() == "Tai chinh") {
			nv[i].xuat();
		}
	}
	
	//SAP XEP TEN NHAN VIEN
	sapXepTenNhanVien(nv, n); 
	cout << "\n==========================THONG TIN NHAN VIEN THEO THU TU ABC========================" << endl;
	cout << left;
	cout << setw(10) << "MA NV"
	<< setw(20) << "HO DEM"
	<< setw(10) << "TEN"		
	<< setw(15) << "MA PB"
	<< setw(15) << "TEN PB"		
	<< setw(20) << "TRUONG PHONG"
	<< setw(10) << "SO NV"
	<< "NGAY SINH" << endl;	
	for (int i = 0; i < n; i++) {
		nv[i].xuat();
	}
	
	//CHEN THONG TIN NHAN VIEN
	int k;
	cout << "\nNhap vao vi tri can chen: ";
	cin >> k;

	chenNhanVien(nv, n, k);
	n++;
	sapXepTenNhanVien(nv, n);
	cout << "\n==========================THONG TIN NHAN VIEN THEO THU TU ABC SAU KHI CHEN THEM========================" << endl;
	cout << left;
	cout << setw(10) << "MA NV"
	<< setw(20) << "HO DEM"
	<< setw(10) << "TEN"		
	<< setw(15) << "MA PB"
	<< setw(15) << "TEN PB"		
	<< setw(20) << "TRUONG PHONG"
	<< setw(10) << "SO NV"
	<< "NGAY SINH" << endl;	
	for (int i = 0; i < n; i++) {
		nv[i].xuat();
	}
	
	//XOA NHAN VIEN CO MA 123
	for (int i = 0; i < n; i++) {
		if (nv[i].getMaNv() == 123) {
			k = i;
			xoaNhanVien(nv, n, k);
			n--;
			i--;
		}
	}
	cout << "\n==========================THONG TIN NHAN VIEN THEO THU TU ABC SAU KHI XOA MA 123========================" << endl;
	cout << left;
	cout << setw(10) << "MA NV"
	<< setw(20) << "HO DEM"
	<< setw(10) << "TEN"		
	<< setw(15) << "MA PB"
	<< setw(15) << "TEN PB"		
	<< setw(20) << "TRUONG PHONG"
	<< setw(10) << "SO NV"
	<< "NGAY SINH" << endl;	
	for (int i = 0; i < n; i++) {
		nv[i].xuat();
	}	
	return 0;
}

