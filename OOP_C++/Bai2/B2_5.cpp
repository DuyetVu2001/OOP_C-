#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Oto 
{
private:
	string maOto;
	double giaMua;
	int soNamSuDung;
	double tyLeKhauHao;
public:
	void nhap() {
		cout << "Ma OTO: ";
		getline(cin, maOto);
		
		cout << "Gia mua: ";
		cin >> giaMua;
		
		cout << "So nam du dung: ";
		cin >> soNamSuDung;
		
		cout << "Ty le khau hao: ";
		cin >> tyLeKhauHao;
		cin.ignore();
	}
	
	double giaTriXeHienTai() {
		double giaHienTai = giaMua;
		for (int i = 1; i <= soNamSuDung; i++) {
			giaHienTai = giaHienTai - giaHienTai * tyLeKhauHao / 100;
		}
		return giaHienTai;
	}
	
	void xuat() {
		cout << setw(20) << left << maOto
		<< setw(20) << left << giaMua
		<< setw(20) << left << soNamSuDung
		<< setw(20) << left << fixed << setprecision(3) << tyLeKhauHao
		<< fixed << setprecision(3) << giaTriXeHienTai() << endl;
	}
};

int main()
{
	Oto oto1;
	oto1.nhap();
	
	cout << "=============================THONG TIN XE===============================" << endl;
	cout << setw(20) << left << "MA OTO"
	<< setw(20) << left << "GIA MUA"
	<< setw(20) << left << "NAM SD"
	<< setw(20) << left << fixed << setprecision(3) << "TY LE KHAU HAO"
	<< fixed << setprecision(3) << "GIA XE CU" << endl;
	oto1.xuat();
}
