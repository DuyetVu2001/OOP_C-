#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

bool luyThua(int fo) {
	int p = 1;
	for (int i = 1; i < fo; i++) {
		p *= i;
	}
	if(p == 16) {
		return true;
	}
	return false;
}

int main()
{
	if (luyThua(4)) {
		cout << "YES";
	}
	cout << "NO";
	return 0;
}

