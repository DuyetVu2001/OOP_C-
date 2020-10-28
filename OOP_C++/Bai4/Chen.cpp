#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class HiLu
{
private:
	string a, b, c;
public:
	void nhap() {
		cout << "Nhap vao lan luot a b c: ";
		getline(cin, a);
		getline(cin, b);
		getline(cin, c);
	}
	void xuat() {
		cout << left;
		cout << setw(10) << a
		<< setw(10) << b
		<< setw(10) << c << endl;
	}
};

void chenHi(HiLu *a, int k, int n)
{
	for (int i = n; i > k; i--) 
	{
		a[i] = a[i - 1];
	}
	a[k].nhap();
}

void xoaHi(HiLu *a, int k, int n)
{
	for (int i = k; i < n - 1; i++) {
		a[i] = a[i + 1];
	}
}

int main()
{
	int n = 3;
	HiLu hi[100];
	
	for (int i = 0; i < n; i++)
	{
		hi[i].nhap();
	}
	
	cout << left;
	cout << setw(10) << "A"
	<< setw(10) << "B"
	<< setw(10) << "C" << endl;
	for (int i = 0; i < n; i++)
	{
		hi[i].xuat();
	}
	//chen them 1
	int k = 1;
	chenHi(hi, k, n);
	n++;	
	cout << endl;
	cout << left;
	cout << setw(10) << "A"
	<< setw(10) << "B"
	<< setw(10) << "C" << endl;
	for (int i = 0; i < n; i++)
	{
		hi[i].xuat();
	}
	
	//Xoa
	k = 1;
	xoaHi(hi, k, n);
	n--;
	cout << endl;
	cout << left;
	cout << setw(10) << "A"
	<< setw(10) << "B"
	<< setw(10) << "C" << endl;
	for (int i = 0; i < n; i++)
	{
		hi[i].xuat();
	}
	
	return 0;
}

