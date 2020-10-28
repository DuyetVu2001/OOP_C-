#include <iostream>
using namespace std;

int kiemTraSoDoiXung(int n)
{
	int k = 0, m = n;
	
	while (m != 0) {
		k = k*10 + m%10;
		m /= 10;
	}
	
	if (n == k)
		return 1;
	return 0;
}

int main()
{
	int n = 110000211;
	
	int check = kiemTraSoDoiXung(n);
	
	if (check == 0) {
		cout << "Khong doi xung!";
	} else {
		cout << "Doi xung!";
	}
	return 0;
}

