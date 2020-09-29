#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Birthday
{
private:
	int day;
	int month;
	int year;
public:
	void nhap(){
		cout << "Please enter your date of birth: ";
		cin >> day;
		
		cout << "Then, enter your month of birth: ";
		cin >> month;
		
		cout << "Finally, enter your year of birth: ";
		cin >> year;
	}
	
	int getDay(){
		return day;
	}
	int getMonth(){
		return month;
	}
	int getYear(){
		return year;
	}
};

class HocSinh 
{
private:
	string name;
	string gender;
	float averageScore;
	Birthday birthday;
	string xepLoaiDaoDuc;	
public:
	void nhap();
	void xuat();
};

void HocSinh::nhap() 
{
	cout << "Please enter your name: ";
	getline(cin, name);
	
	cout << "Enter your gender: ";
	getline(cin, gender);
	
	cout << "Enter your average score: ";
	cin >> averageScore;	

	birthday.nhap();
	
	cin.ignore();
	cout << "Xep loai dao duc cua ban: ";
	getline(cin, xepLoaiDaoDuc);	
	
	cout << "=================================" << endl;
}

void HocSinh::xuat()
{
	cout << setw(25) << left << name 
	<< setw(15) << left << gender 
	<< setw(20) << left << averageScore 
	<< birthday.getDay() << "/" << birthday.getMonth() << "/" << setw(14) << left << birthday.getYear() 
	<< xepLoaiDaoDuc << endl;
}

int main() 
{
	HocSinh hs1, hs2;
	hs1.nhap();
	
	
	cout << setw(25) << left << "Name" 
	<< setw(15) << left << "Gender" 
	<< setw(20) << left << "averageScore" 
	<< setw(20) << left << "Birthday" 
	<< "Xep loai dao duc" << endl;
	hs1.xuat();
	
	return 0;
}









