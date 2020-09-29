#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <string>

class SapXep
{
private:
	int n;
	int a[100];
public:
	void nhap();
	void xuat();
};

void SapXep::nhap()
{
	cout << "Nhap vao so luong phan tu cua mang: ";
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]: ";
		cin >> a[i];
	}
}

void SapXep::xuat()
{
	cout << "\nMang sau khi sap xep: " << endl;
//	sort(a, a+n);
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int k = a[i];
				a[i] = a[j];
				a[j] = k;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

int main() 
{
	SapXep sx;
	sx.nhap();
	sx.xuat();
	
}
