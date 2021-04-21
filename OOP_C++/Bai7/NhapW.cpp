#include <iostream>
using namespace std;

int main() {
	int a[100][200];
	int m, n;
	cin >> m >> n;
	int sum = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			sum += a[i][j];
		}
	}
	cout << sum;
	return 0;
}

