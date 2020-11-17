#include <iostream>
using namespace std;

class Vecto
{
private:
	int x, y;
public:
	friend istream &operator >> (istream &is, Vecto &obj) {
		cout << "Nhap x, y: ";
		is >> obj.x >> obj.y;
		return is;
	}
	
	friend ostream &operator << (ostream &os, Vecto &obj) {
		os << "(" << obj.x << "," << obj.y << ")" << endl;
		return os;
	}
	
	friend Vecto operator+ (Vecto a, Vecto b)
	{
		Vecto c;
		c.x = a.x + b.x;
		c.y = a.y + b.y;
		return c;
	}
	
	Vecto operator- (Vecto b)
	{
		Vecto c;
		c.x = x - b.x;
		c.y = y - b.y;
		return c;
	}
};

int main()
{
	Vecto a, b, c;
	cin >> a;
	cin >> b;
	
	c = a + b;
	cout << c;
	
	c = a - b;
	cout << c;
	return 0;
}
