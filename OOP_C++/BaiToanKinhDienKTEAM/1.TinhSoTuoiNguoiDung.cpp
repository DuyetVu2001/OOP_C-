#include <iostream>
using namespace std;

int main()
{
	int namSinh(0);// Khoi tao nam sinh la 0
	int namHienTai(2020);
	
	cout << "Nhap vao nam sinh: ";
	cin >> namSinh;
	
	cout << "Vay ban " << namHienTai - namSinh << " tuoi.";
	
	return 0;
}
