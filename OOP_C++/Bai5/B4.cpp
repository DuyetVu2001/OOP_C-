#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Electronic
{
protected:
	long congSuat;
	long dienAp;
public:
	Electronic(long congSuat, long dienAp);
};

Electronic::Electronic(long congSuat, long dienAp)
{
	this->congSuat = congSuat;
	this->dienAp = dienAp;
}

class MayGiat : public Electronic
{
private:
	long dungTich;
	string loai;
public:
	MayGiat(long congSuat, long dienAp, long dungTich, string loai) : Electronic(congSuat, dienAp) {
		this->dungTich = dungTich;
		this->loai = loai;
	}
	void xuat();
};

void MayGiat::xuat()
{
	cout << "Cong suat: " << congSuat << endl
	<< "Dien ap: " << dienAp << endl
	<< "Dung tich: " << dungTich << endl
	<< "The loai: " << loai << endl;
}

class TuLanh : public Electronic
{
private:
	long dungTich;
	int soNgan;
public:
	TuLanh(long dungTich, int soNgan);
	TuLanh(long congSuat, long dienAp, long dungTich, int soNgan);
	void xuat() {
		cout << "Cong suat: " << congSuat << endl
		<< "Dien ap: " << dienAp << endl
		<< "Dung tich: " << dungTich << endl
		<< "So ngan: " << soNgan << endl;
	}
};

TuLanh::TuLanh(long congSuat, long dienAp, long dungTich, int soNgan) : Electronic(congSuat, dienAp)
{
	this->dungTich = dungTich;
	this->soNgan = soNgan;
}

int main()
{
	MayGiat mg(12, 12, 23, "long dung");
	TuLanh tl(1, 2, 3, 2);
	
	cout << "THONG TIN TU LANH: " << endl;
	tl.xuat();
	
	cout << "\nTHONG TIN MAY GIAT: " << endl;
	mg.xuat();
	return 0;
}

