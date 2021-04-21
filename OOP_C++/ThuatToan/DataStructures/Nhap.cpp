#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

void deQuy(int l, int r) {
	int m = (l+r) / 2;
	cout << "Lan 1" << endl;
	cout << "r = " << r << ", l = " << l << endl;
	if (l < r) {
		
		cout << "Lan 2" << endl;
		cout << "r = " << r << ", l = " << l << endl;
		deQuy(l, m);
		
		cout << "Lan 3" << endl;
		cout << "r = " << r << ", l = " << l << ", m = " << m << endl;
		deQuy(m+1, r);
	}
}

int main() {
	int l = 0, r = 1;
	
	deQuy(l, r);
	
	
	return 0;
}

