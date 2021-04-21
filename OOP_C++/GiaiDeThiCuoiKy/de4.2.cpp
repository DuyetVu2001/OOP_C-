#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Arr {
private: 
	int *a;
	int n;
	
public:
	friend istream &operator >> (istream &is, Arr &obj) {
		cout << "+ Nhap vao kich thuoc mang: ";
		is >> obj.n;
		
		obj.a = new int[obj.n];
		
		for (int i = 0; i < obj.n; i++) {
			cout << "+ Nhap a[" << i + 1 << "]: ";
			is >> obj.a[i];
		}
		return is;
	}
	friend ostream &operator << (ostream &os, Arr &obj) {
		for (int i = 0; i < obj.n; i++) {
			os << obj.a[i] << endl;
		}
		return os;
	}
	friend Arr operator - (Arr &arr1) {
		for (int i = 0; i < arr1.n; i++) {
			arr1.a[i] *= (-1);
		}
		return arr1;
	}
	Arr operator ++ () {
		Arr arr1;
		arr1.a = new int[n];
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					swap(a[i], a[j]);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			arr1.a[i]= a[i];
		}
		return arr1;
	}
};

int main() {
	Arr a1;
	cin >> a1;
	cout << a1;
	
	++a1;
	cout << a1;
	-a1;
	cout << a1;
	return 0;
}

