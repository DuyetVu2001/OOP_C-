#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Vehicle
{
protected:
	string nhanHieu;
	int namSx;
	string hang;
public:
	void nhap();
	void xuat();
};

class Oto : public Vehicle
{
private:
	int soChoNgoi;
	float dungTich;
public:
	void nhap() {
		cout << "Nhan hieu: ";
		getline(cin, nhanHieu);
		
		cout << "Nam san xuat: ";
		cin >> namSx;
		cin.ignore();
		
		cout << "Hang san xuat: ";
		getline(cin, hang);
		
		cout << "So cho ngoi: ";
		cin >> soChoNgoi;
		
		cout << "Dung tich: ";
		cin >> dungTich;
		cin.ignore();
	}
	void xuat() {
		cout << "Nhan hieu: " << nhanHieu << endl;
		cout << "Nam san xuat: " << namSx << endl;		
		cout << "Hang san xuat: " << hang << endl;
		cout << "So cho ngoi: " << soChoNgoi << endl;
		cout << "Dung tich: " << dungTich << endl;
	}
};

class Moto : public Vehicle
{
private:
	long phanKhoi;
public:
	void nhap() {
		cout << "Nhan hieu: ";
		getline(cin, nhanHieu);
		
		cout << "Nam san xuat: ";
		cin >> namSx;
		cin.ignore();
		
		cout << "Hang san xuat: ";
		getline(cin, hang);
		
		cout << "Phan khoi: ";
		cin >> phanKhoi;
		cin.ignore();
	}
	
	void xuat() {
		cout << "Nhan hieu: " << nhanHieu << endl;	
		cout << "Nam san xuat: " << namSx << endl;		
		cout << "Hang san xuat: " << hang << endl;
		cout << "Phan khoi: " << phanKhoi << endl;
	}
};

int main()
{
	Oto oto;
	Moto moto;
	
	cout << "NHAP VAO THONG TIN OTO: " << endl;
	oto.nhap();	
	cout << "\nNHAP VAO THONG TIN MOTO: " << endl;
	moto.nhap();
	
	cout << "\nTHONG TIN OTO: " << endl;
	oto.xuat();	
	cout << "\nTHONG TIN MOTO: " << endl;
	moto.xuat();
	
	return 0;
}

