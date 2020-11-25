#include <bits/stdc++.h>
using namespace std;

class Box{
private:
	int dai, rong, cao;
	
public:
	friend istream &operator >> (istream &is, Box &obj);
	friend ostream &operator << (ostream &os, Box &obj);
	int theTich();
	int operator+ (Box &box2);
	int operator> (Box &box2);
};

int Box::theTich() {
	return dai * rong * cao;
}

istream &operator >> (istream &is, Box &obj) {
	cout << "+ Nhap vao chieu dai, rong, cao: ";
	is >> obj.dai >> obj.rong >> obj.cao;
	return is;
}

ostream &operator << (ostream &os, Box &obj){
	os << obj.theTich() << endl;
	return os;
}

int Box::operator+ (Box &box2) {
	return this->theTich() + box2.theTich();
}

int Box::operator> (Box &box2) {
	if (this->theTich() > box2.theTich()) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	Box b1, b2, b3;
	cin >> b1;
	cin >> b2;
	cout << b1 + b2 << endl;

	if (b1 > b2) {
		cout << "B1";
	}
	else {
		cout << "B2";
	}
}
