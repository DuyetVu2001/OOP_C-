#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class MaTran
{
private:
	double **a;
	int m;
	int n;
	
public:
	friend istream &operator >> (istream &is, MaTran &obj)
	{
		cout << "Nhap vao lan luot m, n: ";
		cin >> obj.m >> obj.n;
		
		obj.a = new double* [obj.m];
		for (int i = 0; i < obj.m; i++)
		{
			obj.a[i] = new double[obj.n];
		}
		
		for (int i = 0; i < obj.m; i++) 
		{
			for (int j = 0; j < obj.n; j++)
			{
				cout << "Nhap a[" << i << "][" << j << "]: ";
				cin >> obj.a[i][j];
			}
		}
		return is;
	}
	friend ostream &operator << (ostream &os, MaTran &obj) 
	{
		for (int i = 0; i < obj.m; i++) 
		{
			for (int j = 0; j < obj.n; j++)
			{
				cout << left;
				cout << setw(5) << obj.a[i][j];
			}
			cout << endl << endl;
		}
		return os;
	}
	MaTran operator- (); //Doi dau ma tran
	MaTran operator- (MaTran &maTran2);//Tru hai ma tran
	MaTran operator+ (MaTran &maTran2);
};

MaTran MaTran::operator-() {
	MaTran maTran1;
	maTran1.m = m;
	maTran1.n = n;
	//Cap phat dong
	maTran1.a = new double* [m];
	for (int i = 0; i < m; i++) {
		maTran1.a[i] = new double [n];
	}
	//Doi dau ma tran
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			maTran1.a[i][j] = a[i][j] * (-1);
		}
	}
	return maTran1;
}

MaTran MaTran::operator- (MaTran &maTran2) {
	MaTran maTran1;
	maTran1.m = m;
	maTran1.n = n;
	//Cap phat dong
	maTran1.a = new double* [m];
	for (int i = 0; i < m; i++) {
		maTran1.a[i] = new double [n];
	}
	//Tru hai ma tran
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			maTran1.a[i][j] = a[i][j] - maTran2.a[i][j];
		}
	}
	return maTran1;
}

MaTran MaTran::operator+ (MaTran &maTran2) {
	MaTran maTran1;
	maTran1.m = m;
	maTran1.n = n;
	//Cap phat dong
	maTran1.a = new double* [m];
	for (int i = 0; i < m; i++) {
		maTran1.a[i] = new double [n];
	}
	//Cong hai ma tran
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			maTran1.a[i][j] = a[i][j] + maTran2.a[i][j];
		}
	}
	return maTran1;
}

int main()
{
	MaTran mt1, mt2, mt3;
	
	cin >> mt1;
	cin >> mt2;
	
	cout << "Doi dau hai ma tran: " << endl;
	mt1 = -mt1;
	cout << mt1 << endl;
	mt2 = -mt2;
	cout << mt2 << endl;
	
	cout << "Cong hai ma tran: " << endl;
	mt3 = mt1 + mt2;
	cout << mt3 << endl;
	
	cout << "Tru hai ma tran: " << endl;
	mt3 = mt1 - mt2;
	cout << mt3 << endl;
	return 0;
}
