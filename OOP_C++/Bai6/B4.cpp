#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class TamThucBacHai
{
private:
	float a;
	float b;
	float c;
	
public:
	TamThucBacHai() {
		
	}
	TamThucBacHai(float a, float b, float c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
	friend ostream &operator << (ostream &os, TamThucBacHai &obj) {
		if (obj.b < 0 && obj.c < 0) {
			os << obj.a << "x2" << obj.b << "x" << obj.c << endl;
		}
		else {
			os << obj.a << "x2+" << obj.b << "x+" << obj.c << endl;	
		}
		return os;
	}
	friend TamThucBacHai operator+ (TamThucBacHai &tt1, TamThucBacHai &tt2) {
		TamThucBacHai tt3;
		tt3.a = tt1.a + tt2.a;
		tt3.b = tt1.b + tt2.b;
		tt3.c = tt1.c + tt2.c;
		return tt3;
	}
	TamThucBacHai operator- (TamThucBacHai &tt2) {
		TamThucBacHai tt3;
		tt3.a = a - tt2.a;
		tt3.b = b - tt2.b;
		tt3.c = c - tt2.c;
		return tt3;
	}
	TamThucBacHai operator-- () {
		TamThucBacHai tt3;
		tt3.a = -a;
		tt3.b = -b;
		tt3.c = -c;
		return tt3;
	}
};

int main()
{
	TamThucBacHai tt1(1, 2, 3), tt2(1, 2, 3), tt3;
	tt3 = tt1 + tt2;
	cout << "\nCONG(+) \n" << tt3;
	
	tt3 = tt1 - tt2;
	cout << "\nCHU(-) \n" << tt3;
	
	tt1 = --tt1;
	tt2 = --tt2;
	
	cout << "DOI DAU: \n" << tt1 << endl << tt2;
	return 0;
}

