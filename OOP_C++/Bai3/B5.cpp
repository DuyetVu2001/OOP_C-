#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Date
{
private:
	string sinhNhat;
public:
	void nhap() {
		cout << "Sinh nhat cua ban: ";
		getline(cin, sinhNhat);
	}
	
	void xuat() {
		cout << setw(20) << sinhNhat;
	}
};

class NhanSu
{
private:
	string ho;
	string dem;
	string ten;
	Date sinhNhat;
	string soCMT;
public:
	void nhap() {
		cout << "Nhap vao Ho: ";
		getline(cin, ho);
		
		cout << "Nhap vao Dem: ";
		getline(cin, dem);
		
		cout << "Nhap vao Ten: ";
		getline(cin, ten);
		
		sinhNhat.nhap();
		
		cout << "Nhap vao So CMT: ";
		getline(cin, soCMT);		
	}
	
	void xuat() {
		cout << left;
		cout << setw(25) << ho + " " + " " + dem + " " + ten;
		sinhNhat.xuat();
		cout << setw(20) << soCMT << endl;
	}
	
	string getTen() {
		return this->ten;
	}
};

int main()
{
	NhanSu ns[100];
	int n;
	
	cout << "Nhap vao n nhan su: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout << "=======================NHAN SU " << i + 1 << "==========================" << endl;
		ns[i].nhap();
	}
	
	for (int i = 0; i < n - 1; i++)	{
		for (int j = i + 1; j < n; j++)	{
			if (ns[i].getTen() > ns[j].getTen()) {
				swap(ns[i], ns[j]);
			}
		}
	}
	
	cout << left;
	cout << setw(25) << "HO TEN"
	<< setw(20) << "SINH NHAT"
	<< setw(20) << "SO CMT" << endl;
	for (int i = 0; i < n; i++) {
		ns[i].xuat();
	}
	return 0;
}

