#include <iostream>
using namespace std;

int giaiThua(int n) {
	if (n == 0) {
		return 1;
	}
	return giaiThua(n - 1) * n;
}

int main()
{
	int n(5);
	int giaiThuaCuaN = giaiThua(n); 
	
//	for (int i = n; i > 0; i--) {
//		giaiThuaCuaN *= i;
//	}
	
	cout << "Giai thua cua n la: " << giaiThuaCuaN;
	return 0;
}

