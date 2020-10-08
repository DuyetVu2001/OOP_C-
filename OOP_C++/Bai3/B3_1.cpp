#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Date
{
private:
	int day;
	int month;
	int year;
public:
	void nhap() {
		cout << "Nhap vao ngay sinh: ";
		cin >> day;
		
		cout << "Nhap vao thang sinh: ";
		cin >> month;
		
		cout << "Nhap vao nam sinh: ";
		cin >> year;
	}
	
	void xuat() {
		cout << day << "/" << month << month << "/" << year;
	}
};

class NhanSu
{
private:
	string maNhanSu;
	string hoTen;
	Date namSinh;
public: 
	void nhap()	{
		cout << "Ma nhan su: ";
		getline(cin, maNhanSu);
		
		cout << "Ho va ten: ";
		getline(cin, hoTen);
		
		namSinh.nhap();
		cin.ignore();
	}
	
	void xuat() {
		cout << setw(15) << left << maNhanSu
		<< setw(25) << left << hoTen;
		namSinh.xuat();
		cout << endl;
	}
};

int main()
{
	NhanSu ns1[100];
	int n;
	
	cout << "Nhap vao so nhan su: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout << "==========================NHAN SU " << i + 1 << "===========================" << endl;
		ns1[i].nhap();
	}
	
	
	cout << "\n=======================THONG TIN NHAN SU==========================" << endl;
	cout << setw(15) << left << "ID"
		<< setw(25) << left << "HO VA TEN"
		<< "NAM SINH" << endl;
	for (int i = 0; i < n; i++) {
		ns1[i].xuat();
	}
	
}








