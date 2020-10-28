#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Person
{
protected:
	string name;
	string birthDay;
	string queQuan;
};

class KySu : public Person
{
private:
	string nganh;
	int namTn;
public:
	int getNamTn() {
		return this->namTn;
	}
	
	void nhap() {
		cout << "Nhap vao Ho va Ten: ";
		getline(cin, name);
		
		cout << "Nhap vao Ngay Thang Nam Sinh: ";
		getline(cin, birthDay);
		
		cout << "Nhap vao Que Quan: ";
		getline(cin, queQuan);
		
		cout << "Nhap vao Nganh Hoc: ";
		getline(cin, nganh);
		
		cout << "Nhap vao nam Tot Nghiep: ";
		cin >> namTn;
		cin.ignore();
	}
	
	void xuat() {
		cout << left;
		cout << setw(20) << name
		<< setw(20) << birthDay
		<< setw(20) << queQuan
		<< setw(15) << nganh
		<< setw(15) << namTn << endl;
	}
};

int main()
{
	KySu ks1[100];
	int n;
	cout << "Nhap vao so luong ky su: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout << "================NHAP THONG TIN KY SU " << i + 1 << "================" << endl;
		ks1[i].nhap();
	}
	
	cout << "\n============================================================================================" << endl;
	cout << left;
	cout << setw(20) << "HO VA TEN"
	<< setw(20) << "NGAY SINH"
	<< setw(20) << "QUE QUAN"
	<< setw(15) << "NGANH"
	<< setw(15) << "NAM TOT NGHIEP" << endl;
	for (int i = 0; i < n; i++) {
		ks1[i].xuat();
	}
	
	int max = -10000000;
	cout << "\n============================THONG TIN KY SU MOI TOT NGHIEP============================" << endl;
	cout << left;
	cout << setw(20) << "HO VA TEN"
	<< setw(20) << "NGAY SINH"
	<< setw(20) << "QUE QUAN"
	<< setw(15) << "NGANH"
	<< setw(15) << "NAM TOT NGHIEP" << endl;
	for (int i = 0; i < n; i++) {
		if (max < ks1[i].getNamTn()) {
			max = ks1[i].getNamTn();
		}	
	}
	for (int i = 0; i < n; i++) {
		if (max == ks1[i].getNamTn()) {
			ks1[i].xuat();
		}	
	}
	return 0;
}
