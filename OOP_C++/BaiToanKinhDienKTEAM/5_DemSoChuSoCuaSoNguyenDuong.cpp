#include <iostream>
using namespace std;

int demSoChuSo(int n) 
{
	if (n < 10)
		return 1;
	return 1 + demSoChuSo(n / 10);
}

int main()
{
	int n(1234);
	cout << demSoChuSo(n);
	return 0;
}

