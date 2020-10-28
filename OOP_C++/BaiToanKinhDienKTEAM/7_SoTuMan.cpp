#include <iostream>
using namespace std;
#include <math.h>

int demSoChuSo(int n) 
{
	int dem(0);
	
	while (n != 0) {
		n /= 10;
		dem++;
	}
	
	return dem;
}

bool soTuMan(int n)
{
	int nTemp = n;
	int sum = 0, i;
	int x = demSoChuSo(n);
	
	while (nTemp != 0) {
		i = nTemp % 10;
		sum += pow(i, x);
		nTemp /= 10;
	}
	return (sum == n);
}

int main()
{
	int n(153);
	int check = soTuMan(n);
	
	if (check == 1) {
		cout << "La so tu man!";
	} else {
		cout << "Khong la so tu man!";
	}
	
	return 0;
}

