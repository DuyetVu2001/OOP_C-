#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class SinhVien
{
protected:
	string hoTen, soBD;
};

class DiemThi : public SinhVien
{
protected:
	double kq1, kq2;
};

class KetQua : public DiemThi
{
private:
	double tongDiem;
public:
	void nhap();
	void xuat();
};

void KetQua::nhap()
{
	cout << "Nhap vao ho ten: ";
	getline(cin, hoTen);
	
	cout << "Nhap vao so BD: ";
	getline(cin, soBD);
	
	cout << "Nhap vao lan luot ket qua mon thi 1, 2: ";
	cin >> kq1 >> kq2;
	cin.ignore();
};

void KetQua::xuat()
{
	cout << left;
	cout << setw(15) << hoTen
	<< setw(15) << soBD
	<< setw(10) << kq1
	<< setw(15) << kq2 
	<< kq1 + kq2 << endl;
}

void title() 
{
	cout << left;
	cout << setw(15) << "HO TEN"
	<< setw(15) << "SO BD"
	<< setw(10) << "KQ1"
	<< setw(15) << "KQ2" 
	<< "TONG" << endl;
}

int main()
{
	KetQua kq[100];
	int n;
	
	cout << "Nhap vao so sinh vien cua lop: ";
	cin >> n;
	cin.ignore();
	//Nhap thong tin
	for (int i = 0; i < n; i++) {
		cout << "\nNHAP THONG TIN SINH VIEN " << i + 1 << "." << endl;
		kq[i].nhap();
	}
	//Xuat thong tin
	cout << endl;
	title();
	for (int i = 0; i < n; i++) {
		kq[i].xuat();
	}
	return 0;
}
