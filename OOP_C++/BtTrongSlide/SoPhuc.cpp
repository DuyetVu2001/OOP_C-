#include <iostream>
using namespace std;

class SoPhuc
{
private:
	float thuc, ao;
public:
	SoPhuc() {
		thuc = 0;
		ao = 0;
	}
	SoPhuc(int thuc, int ao) {
		this->thuc = thuc;
		this->ao = ao;
	}
	
	void xuat() {
		if (thuc < 0) {
			cout << thuc << "+" << ao << "i" << endl;
		}
		else {
			cout << thuc << "+" << ao << "i" << endl;
		}
	}
	
	SoPhuc operator- () {
		SoPhuc z;
		z.thuc = -thuc;
		z.ao = -ao;
		return z;
	}
};

int main()
{
	SoPhuc a(1, 2);
	a = -a;
	a.xuat();
	return 0;
}

