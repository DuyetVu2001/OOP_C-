#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

class XeHoi
{
private:
	string nhanHieu;
	string hangSanXuat;
	string kieuDang;
	string mauSon;
	string namSanXuat;
	string xuatXu;
	long long giaBan;
public:
	void nhap();
	void xuat();
	long long getGiaBan();
	string getHangSanXuat();
};

void XeHoi::nhap()
{
	cout << "NHAN HIEU: ";
	getline(cin, nhanHieu);
	
	cout << "HANG SX: ";
	getline(cin, hangSanXuat);
	
	cout << "KIEU DANG: ";
	getline(cin, kieuDang);
	
	cout << "MAU SON: ";
	getline(cin, mauSon);
	
	cout << "NAM SAN XUAT (vd: 01/03/2001): ";
	getline(cin, namSanXuat);
	
	cout << "XUAT XU: ";
	getline(cin, xuatXu);
	
	cout << "GIA BAN: ";
	cin >> giaBan;
	cin.ignore();
}
	
void XeHoi::xuat()
{
	cout << left;
	cout << setw(15) << nhanHieu
	<< setw(15) << hangSanXuat
	<< setw(15) << kieuDang
	<< setw(15) << mauSon
	<< setw(15) << namSanXuat
	<< setw(15) << xuatXu 
	<< setw(15) << giaBan << endl;
}

long long XeHoi::getGiaBan()
{
	return this->giaBan;
}

string XeHoi::getHangSanXuat() 
{
	return this->hangSanXuat;
}

void sapXepGiaXeTangDan(XeHoi a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].getGiaBan() > a[j].getGiaBan()) {
				swap(a[i], a[j]);
			}
		}
	}
}

int main()
{
	XeHoi xeHoi[100];
	int n = 0;
	
	cout << "Nhap vao so luong xe hoi: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout << "\n============================XE SO " << i + 1 << "==============================" << endl;
		xeHoi[i].nhap();
	}
	
	cout << "\n================================THONG TIN XE=======================================" << endl;
	cout << left;
	cout << setw(15) << "NHAN HIEU"
	<< setw(15) << "HANG SX"
	<< setw(15) << "KIEU DANG"
	<< setw(15) << "MAU SON"
	<< setw(15) << "NAM SX"
	<< setw(15) << "XUAT XU" 
	<< setw(15) << "GIA BAN" << endl;
	sapXepGiaXeTangDan(xeHoi, n);
	for (int i = 0; i < n; i++) {
		xeHoi[i].xuat();
	}
	
	cout << "\n================================THONG TIN XE CUA HANG Toyota=======================================" << endl;
	cout << left;
	cout << setw(15) << "NHAN HIEU"
	<< setw(15) << "HANG SX"
	<< setw(15) << "KIEU DANG"
	<< setw(15) << "MAU SON"
	<< setw(15) << "NAM SX"
	<< setw(15) << "XUAT XU" 
	<< setw(15) << "GIA BAN" << endl;
	sapXepGiaXeTangDan(xeHoi, n);
	for (int i = 0; i < n; i++) {
		if (xeHoi[i].getHangSanXuat() == "Toyota") {
			xeHoi[i].xuat();
		}
	}
	return 0;
}
