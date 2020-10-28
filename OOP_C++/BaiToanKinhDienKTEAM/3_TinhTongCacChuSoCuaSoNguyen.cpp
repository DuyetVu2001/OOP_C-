#include<iostream>
using namespace std;

int tinhTongChuSoCuaSoNguyen(int n)
{
	int sum = 0;
	
	while (n != 0) 
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int main() 
{
	int n;
	cout << "Nhap vao so nguyen n: ";
	cin >> n;
	
	int sum = tinhTongChuSoCuaSoNguyen(n);
	cout << "Tong so chu so cua n la: " << sum;
	return 0;
}
