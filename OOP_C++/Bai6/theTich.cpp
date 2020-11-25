#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Box{
private:
	int dai;
	int rong;
	int cao;
	int theTichHinh;
public:
	friend istream &operator >> (istream &is, Box &obj);
	friend ostream &operator << (ostream &os, Box &obj);
	Box operator+ (Box &box2);
	int getTheTichHinh() {
		this->theTichHinh = dai * rong * cao;
		return this->theTichHinh;
	}
};

istream &operator >> (istream &is, Box &obj) {
	cout << "Nhap vao dai, rong, cao: ";
	is >> obj.dai >> obj.rong >> obj.cao;
	obj.getTheTichHinh();
	return is;
}

ostream &operator << (ostream &os, Box &obj) {
	os << obj.theTichHinh << endl;
	return os;
}

Box Box::operator+ (Box &box2) {
	Box box3;
	box3.theTichHinh = getTheTichHinh() + box2.getTheTichHinh();
	return box3;
}

int main() {
	Box b1, b2, b3;
	cin >> b1 >> b2;
	b3 = b1 + b2;
	cout << "THE TICH: ";
	cout << b1;
	cout << "THE TICH: ";
	cout << b2;
	cout << "THE TICH: ";
	cout << b3;
	return 0;
}
