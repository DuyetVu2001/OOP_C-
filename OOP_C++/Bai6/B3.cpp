#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class SoPhuc {
private:
	int thuc; //Phan thuc
	int ao; //Phan ao
	
public: 
	SoPhuc() {
	}
	SoPhuc(int thuc, int ao) {
		this->thuc = thuc;
		this->ao = ao;
	}
	friend istream &operator >> (istream &is, SoPhuc &obj) {
		cout << "Nhap phan thuc: ";
		is >> obj.thuc;
		cout << "Nhap phan ao: ";
		is >> obj.ao;
		return is;
	}
	friend ostream &operator << (ostream &os, SoPhuc &obj);
	SoPhuc operator+ (SoPhuc &b) {
		SoPhuc c;
		c.thuc = thuc + b.thuc;
		c.ao = ao + b.ao;
		return c;
	}
	friend SoPhuc operator- (SoPhuc &a, SoPhuc &b);
};

SoPhuc operator- (SoPhuc &a, SoPhuc &b) {
	SoPhuc c;
	c.thuc = a.thuc - b.thuc;
	c.ao = a.ao - b.ao;
	return c;
}

ostream &operator << (ostream &os, SoPhuc &obj) {
		cout << obj.thuc << " + i*" << obj.ao << endl;
		return os;
	}

int main()
{
	SoPhuc SP1, SP2, SP3, SP4;
	
	cout << "- Nhap vao so phuc thu nhat. \n";
	cin >> SP1;
	cout << "- Nhap vao so phuc thu hai. \n";
	cin >> SP2;
	
	SP3 = SP1 + SP2;
	SP4 = SP1 - SP2;
	
	cout << "\nTong hai so phuc: SP1 + SP2 = ";
	cout << SP3;
	cout << "Hieu hai so phuc: SP1 - SP2 = ";
	cout << SP4;
	return 0;
}

