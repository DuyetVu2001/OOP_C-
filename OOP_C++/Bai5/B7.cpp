#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class BenhNhan
{
protected:
	string hoTen, queQuan;
	int namSinh;
public:
	void nhap();
	void xuat();
};

void BenhNhan::nhap()
{
	cout << "Nhap vao ho ten: ";
	getline(cin, hoTen);
	
	cout << "Nhap vao que quan: ";
	getline(cin, queQuan);
	
	cout << "Nhap vao nam sinh (kieu chuoi ky tu. VD: 01/03/2001): ";
	cin >> namSinh;
	cin.ignore();
}

void BenhNhan::xuat()
{
	cout << left;
	cout << setw(25) << hoTen
	<< setw(20) << queQuan
	<< setw(15) << namSinh << endl;
}

class BenhAn : public BenhNhan
{
private:
	string tenBenhAn;
	long soTien;
public:
	long getSoTien() {
		return this->soTien;
	}
	
	int tinhTuoiHienTai() {
		return 2020 - namSinh;
	}
	
	void nhap() {
		cout << "Nhap vao ho ten: ";
		getline(cin, hoTen);
		
		cout << "Nhap vao que quan: ";
		getline(cin, queQuan);
		
		cout << "Nhap vao nam sinh: ";
		cin >> namSinh;
		cin.ignore();
		
		cout << "Nhap vao ten benh an: ";
		getline(cin, tenBenhAn);
		
		cout << "Nhap vao so tien vien phi: ";
		cin >> soTien;
		cin.ignore();
	}
	
	void xuat() {
		cout << left;
		cout << setw(25) << hoTen
		<< setw(20) << queQuan
		<< setw(15) << namSinh 
		<< setw(20) << tenBenhAn
		<< setw(25) << soTien 
		<< tinhTuoiHienTai() << endl;
	}
};

void title()
{
	cout << left;
	cout << setw(25) << "HO TEN"
	<< setw(20) << "QUE QUAN"
	<< setw(15) << "NAM SINH"
	<< setw(20) << "TEN B.A"
	<< setw(25) << "TIEN VIEN PHI" 
	<< "TUOI" << endl;
}

void sapXepTheoTuoiGiam(BenhAn *ba, int n)
{
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ba[i].tinhTuoiHienTai() < ba[j].tinhTuoiHienTai()) {
				swap (ba[i], ba[j]);
			}
		}
	}
}

long tienVienPhiCaoNhat(BenhAn *ba, int n)
{
	long max = 0;
	for (int i = 0; i < n; i++) {
		if (ba[i].getSoTien() > max) {
			max = ba[i].getSoTien();
		}
	}
	return max;
}

int main()
{
	int n;
	BenhAn ba[100];
	
	cout << "So benh an la: ";
	cin >> n;
	cin.ignore();
	//Nhap thong tin
	for (int i = 0; i < n; i++) {
		cout << "\nNHAP THONG TIN BENH AN " << i + 1 << ".\n";
		ba[i].nhap();
	}
	//Sap xep tuoi giam dan
	cout << endl;
	title();
	sapXepTheoTuoiGiam(ba, n);
	for (int i = 0; i < n; i++) {
		ba[i].xuat();
	}
	//Danh sach benh nhan <= 10 tuoi
	cout << endl;
	title();
	for (int i = 0; i < n; i++) {
		if (ba[i].tinhTuoiHienTai() <= 10)
			ba[i].xuat();
	}
	//Benh nhan co tien vien phi cao nhat
	cout << endl;
	title();
	for (int i = 0; i < n; i++) {
		if (ba[i].getSoTien() == tienVienPhiCaoNhat(ba, n))
			ba[i].xuat();
	}
	return 0;
}

