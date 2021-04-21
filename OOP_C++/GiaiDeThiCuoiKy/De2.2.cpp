#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Mang {
private:
	int *a;
	int n;
	
public:
	friend istream &operator >> (istream &is, Mang &arr) {
		cout << "- Nhap vao so phan tu cua ma tran: ";
		is >> arr.n;
//		Cap phat dong
		arr.a = new int[arr.n];
//		Nhap gia tri cua cac phan tu
		for (int i = 0; i < arr.n; i++) {
			cout << "+ a[" << i + 1 << "]: ";
			is >> arr.a[i];
		}
		return is;
	}
	friend ostream &operator << (ostream &os, Mang &arr) {
		for (int i = 0; i < arr.n; i++) {
			os << arr.a[i] << endl;
		}
		return os;
	}
	Mang operator ++ () {
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i] > a[j]) {
					swap(a[i], a[j]);
				}
			}
		}
	}
	friend Mang operator - (Mang &arr) {
		for (int i = 0; i < arr.n; i++) {
			arr.a[i] = (-1) * arr.a[i];
		}
		return arr;
	}
};

int main() {
	Mang arr;
	
	cin >> arr;
	cout << arr;
	++arr;
	cout << arr;
	arr = -arr;
	cout << arr;
	return 0;
}
