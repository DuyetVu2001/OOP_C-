#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Array
{
private:
	int *value;
	int n;
public:
	Array();
	Array(int n);
	~Array();
	void nhap();
	void xuat();
};

Array::Array() 
{
	this-> n = 0;
}

Array::Array(int n) 
{
	this->n = n;	
	this->value = new int[n];
	for (int i = 0; i < n; i++) {
		*(this->value + i) = 0;
	}
}

Array::~Array() 
{
	n = 0;
	delete [] value;
}

void Array::nhap() 
{
	if (n == 0) {
		cout << "Nhap vao so phan tu cua mang: ";
		cin >> n;
	}
	if (value == NULL) value = new int[n];
	
	for (int i = 0; i < n; i++) {
		cout << "Nhap a[" << i << "]: ";
		cin >> *(this->value + i);
	}
}

void Array::xuat() 
{
	cout << "\nMang vua nhap: " << endl;
	for (int i = 0; i < n; i++) {
		cout << *(this->value + i) << endl;
	}
}

int main()
{
	Array a1;
	a1.nhap();
	a1.xuat();
	return 0;
}

