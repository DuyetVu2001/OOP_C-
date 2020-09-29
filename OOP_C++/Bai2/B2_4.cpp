#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class DoanhNghiep
{
private:
	string ten;
	string diaChi;
	long soNhanVien;
	double doanhThu;
public:
	void nhap() {
		cout << "Ten doanh nghiep: ";
		getline(cin, ten);
		
		cout << "Dia chi doanh nghiep: ";
		getline(cin, diaChi);
		
		cout << "So luong nhan vien: ";
		cin >> soNhanVien;
		
		cout << "Doanh thu: ";
		cin >> doanhThu;
		cin.ignore();
	}
	
	void xuat() {
		cout << setw(20) << left << ten
		<< setw(20) << left << diaChi
		<< setw(20) << left << soNhanVien
		<< fixed << setprecision(3) << doanhThu << endl;
	}
};

int main()
{
	DoanhNghiep dn[100];
	
	int n;
	cout << "Nhap vao n doanh nghiep: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout << "=============================" << endl;
		cout << "DOANH NGHIEP " << i + 1 << endl;
		cout << "=============================" << endl;
		dn[i].nhap();
		cout << endl;
	}
	
	cout << "=======================================================================" << endl;	
	cout << setw(20) << left << "Ten DN"
		<< setw(20) << left << "DIA CHI"
		<< setw(20) << left << "SO LUONG NV"
		<< "DOANH THU" << endl;
	for (int i = 0; i < n; i++)	{
		dn[i].xuat();
	}	
}
