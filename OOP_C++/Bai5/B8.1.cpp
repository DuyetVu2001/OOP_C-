#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class SanPham
{
protected:
	string tenSP;
	int namSX;
	double giaThanh;
	
public:
	void nhap() {
		cout << "+ Ten SP: ";
		getline(cin, tenSP);
		
		cout << "+ Nam SX: ";
		cin >> namSX;
		
		cout << "+ Gia thanh: ";
		cin >> giaThanh;
	}
	
	void xuat() {
		cout << left;
		cout << setw(15) << tenSP
		<< setw(15) << namSX
		<< setw(15) << giaThanh;
	}
};

class HoaDon : public SanPham
{
private:
	long slBan;
	double giaBan;
	
public:
	double thanhTien() {
		return slBan * giaBan;
	}
	
	double tinhThue() {
		return thanhTien() * 10 / 100;
	}
	
	double tinhLai() {
		return slBan * (giaBan - giaThanh);
	}
	
	void nhap() {
		SanPham::nhap();
		cout << "+ So luong ban: ";
		cin >> slBan;
		
		cout << "+ Gia ban: ";
		cin >> giaBan;
		cin.ignore();
	}
	
	void xuat() {
		SanPham::xuat();
		cout << left;
		cout << setw(15) << slBan
		<< setw(15) << giaBan 
		<< setw(15) << tinhLai() << endl;
	}
};

void title()
{
	cout << left;
	cout << setw(10) << "ID"
	<< setw(15) << "TEN SP"
	<< setw(15) << "NAM SX"
	<< setw(15) << "GIA THANH"
	<< setw(15) << "SL BAN"
	<< setw(15) << "GIA BAN" 
	<< setw(15) << "TIEN LAI" << endl;
}

void sapXepLaiGiam(HoaDon *hd, int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (hd[i].tinhLai() > hd[j].tinhLai()) {
				HoaDon tmp = hd[i];
				hd[i] = hd[j];
				hd[j] = tmp;
			}
		}
	}
}

void tinhTongCacHoaDon(HoaDon *hd, int n)
{
	double tong = 0;
	for (int i = 0; i < n; i++) {
		tong += hd[i].thanhTien();
	}
	
	cout << "\nTONG TIEN CUA CAC HOA DON BAN SP LA: " << tong << endl;
}

double tienThueCaoNhat(HoaDon *hd, int n)
{
	double max = hd[0].tinhThue();
	for (int i = 1; i < n; i++) {
		if (hd[i].tinhThue() > max) {
			max = hd[i].tinhThue();
		}
	}
	
	return max;
}

int main()
{
	HoaDon hd[100];
	int n;
	cout << "Nhap vao so hoa don: ";
	cin >> n;
	cin.ignore();
	
	//Nhap vao thong tin n san pham
	for (int i = 0; i < n; i++) {
		cout << "\n- NHAP VAO THONG TIN SAN PHAM THU " << i + 1 << "." << endl;
		hd[i].nhap();
	}
	
	//Hien thi ra man hinh danh sach
	cout << "\nTHONG TIN SAN PHAM\n" << endl;
	title();
	for (int i = 0; i < n; i++) {
		cout << left << setw(10) << i + 1;
		hd[i].xuat();
	}
	
	//Sap xep theo tien lai giam dan
	sapXepLaiGiam(hd, n);
	cout << "\nTHONG TIN SAN PHAM SAP XEP GIAM DAN THEO TIEN LAI\n" << endl;
	title();
	for (int i = 0; i < n; i++) {
		cout << left << setw(10) << i + 1;
		hd[i].xuat();
	}
	
	//Thong tin san pham co tien thue cao nhat
	tienThueCaoNhat(hd, n);
	cout << "\nTHONG TIN SAN PHAM\n" << endl;
	title();
	for (int i = 0; i < n; i++) {
		if (hd[i].tinhThue() == tienThueCaoNhat(hd, n)) {
			cout << left << setw(10) << i + 1;
			hd[i].xuat();
		}	
	}
	
	tinhTongCacHoaDon(hd, n);
	return 0;
}

