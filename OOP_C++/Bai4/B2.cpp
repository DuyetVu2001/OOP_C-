#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class NSX
{
private:
	string maNsx;
	string tenNsx;
	string dcNsx;

};

class Hang
{
private:
	string maHang;
	string tenHang;
	string donGia;
	double trongLuong;
	NSX nsx;
public:
	void nhap() {
		cout << "Nhap vao Ma Hang: ";
		getline(cin, maHang);
		
		cout << "Nhap vao Ten Hang: ";
		getline(cin, tenHang);
	}
	
	void xuat() {
		
	}
};

int main()
{
	
	return 0;
}

