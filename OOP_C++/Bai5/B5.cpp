#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class SanPham
{
protected:
	string maSP, tenSP, ngaySX, mau;
	double trongLuong;
public:
	double getTrongLuong() {
		return this->trongLuong;
	}
	SanPham(){
		
	}
	SanPham(string maSp, string tenSP, string ngaySX, 
			string mau, double trongLuong);
};

SanPham::SanPham(string maSP, string tenSP, string ngaySX, 
				string mau, double trongLuong)
{
	this->maSP = maSP;
	this->tenSP = tenSP;
	this->ngaySX = ngaySX;
	this->mau = mau;
	this->trongLuong = trongLuong;
}

class HangDienTu : public SanPham
{
private:
	long congSuat, dongDien;
public:
	void nhap();
	void xuat();
	HangDienTu() {
		
	}
	HangDienTu(string maSP, string tenSP, string ngaySX, 
			string mau, double trongLuong, long congSuat,
			long dongDien);
	HangDienTu(long congSuat, long dongDien);
};

HangDienTu::HangDienTu(string maSP, string tenSP, string ngaySX, 
			string mau, double trongLuong, long congSuat,
			long dongDien) : SanPham(maSP, tenSP, ngaySX, mau, trongLuong)
{
	this->congSuat = congSuat;
	this->dongDien = dongDien;
}
void HangDienTu::nhap()
{
	cout << "Nhap ma SP: ";
	getline(cin, maSP);
	
	cout << "Nhap ten SP: ";
	getline(cin, tenSP);
	
	cout << "Nhap ngay SX (theo dinh dang: _/_/_. VD: 01/03/2001): ";
	getline(cin, ngaySX);
	
	cout << "Nhap mau SP: ";
	getline(cin, mau);
	
	cout << "Nhap trong luong: ";
	cin >> trongLuong;
	cin.ignore();
}

void HangDienTu::xuat()
{
	cout << left;
	cout << setw(15) << maSP
	<< setw(15) << tenSP
	<< setw(15) << ngaySX
	<< setw(15) << mau
	<< setw(15) << trongLuong << endl;
}

void title()
{
	cout << left;
	cout << setw(15) << "Ma SP"
	<< setw(15) << "Ten SP"
	<< setw(15) << "Ngay SX"
	<< setw(15) << "Mau"
	<< setw(15) << "Trong Luong" << endl;
}

double timTrongLuongThapNhat(HangDienTu *hdt, int n)
{
	double min = 10000000;
	for (int i = 0; i < n; i++) {
		if (hdt[i].getTrongLuong() < min) {
			min = hdt[i].getTrongLuong();
		}
	}
	return min;
}

int main()
{
	HangDienTu *hdt = new HangDienTu[10];
	int n;
	
	cout << "Nhap vao so luong san pham: ";
	cin >> n;
	cin.ignore();
	//Nhap thong tin 
	for (int i = 0; i < n; i++) {
		cout << "\nNHAP VAO THONG TIN MAT HANG DIEN TU THU " << i + 1 << "." << endl;
		hdt[i].nhap();
	}
	//Xuat thong tin
	cout << "\nTHONG TIN CAC SAN PHAM" << endl;
	title();
	for (int i = 0; i < n; i++) {
		hdt[i].xuat();
	}
	//Cac mat hang co trong luong thap nhat
	cout << "\nTHONG TIN CAC SAN PHAM CO TRONG LUONG THAP NHAT" << endl;
	title();
	for (int i = 0; i < n; i++) {
		if (hdt[i].getTrongLuong() == timTrongLuongThapNhat(hdt, n))
			hdt[i].xuat();
	}
	
	return 0;
}

