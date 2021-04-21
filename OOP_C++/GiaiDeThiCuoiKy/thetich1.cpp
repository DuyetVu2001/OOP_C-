#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <fstream>

class Box {
	int n;
	int theTich;
	
public:
	int getN() {
		return this->n;
	}
	int getTheTich() {
		theTich = n * n * n;
		return theTich;
	}
	friend istream &operator >> (istream &is, Box &obj)	{
		cout << "+ Nhap vao canh cua hinh lap phuong: ";
		is >> obj.n;
		obj.getTheTich();
		return is;
	}
	friend ostream &operator << (ostream &os, Box &obj) {
		os << "+ The tich cua hinh lap phuong: " << obj.theTich;
		return os;
	}
	Box operator+ (Box &b2) {
		Box b3;
		b3.theTich = getTheTich() + b2.getTheTich();
		return b3;
	}
};

void ghiFile(fstream &ofs, Box b3) {
	ofs << left;
	ofs << setw(20) << "Canh"
	<< setw(20) << "The tich" << endl
	<< setw(20) << b3.getN() 
	<< setw(20) << b3.getTheTich() << endl;
	
}

int main() {
	Box b1, b2, b3;
	cout << "+ Nhap canh box 1, box 2: \n";
	cin >> b1 >> b2;
	cout << "'\n+ Hien thi box 1: \n";
	cout << b1;
	b3 = b1 + b2;
	cout << "\n+ Box 3:\n";
	cout << b3;
	
	fstream ofs("box.txt", ios::out);
	ghiFile(ofs, b1);
	ofs.close();

	return 0;
}

