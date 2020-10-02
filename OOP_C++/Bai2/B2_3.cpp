#include <iostream>
using namespace std;

class MaxAndMin
{
private:
	float a[100];
	int n;
public:
	void nhap() {
		cout << "Nhap vao so phan tu cua mang: ";
		cin >> n;
		
		cout << "NHAP MANG." << endl;
		for (int i = 0; i < n; i++) {
			cout << "Nhap a[" << i << "]: ";
			cin >> a[i];
		}
	}
	
	float max() {
		float max = 0;
		for (int i = 0; i < n; i++) {
			if (max < a[i]) {
				max = a[i];
			}
		}
		return max;
	}	
	
	float min() {
		float min = 1000000000;
		for (int i = 0; i < n; i++) {
			if (min > a[i]) {
				min = a[i];
			}
		}
		return min;
	}
	
	void xuat() {
		cout << "MAXIMUM VALUE IN ARRAY A: " << fixed << max() << endl;
		cout << "MINIMUM VALUE IN ARRAY A: " << fixed << min() << endl;
	}
};

int main ()
{
	MaxAndMin mm1;
	mm1.nhap();
	cout << "=====================================" << endl;
	mm1.xuat();
}
