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

class CanBo{
private:
	string id;
	string name;
	Birthday birthday;
	int workingDays;
public:
	void nhap();
	double tinhLuong();
	void xuat();
}; 

void CanBo::nhap()
{
	cout << "Enter the ID: ";
	getline(cin, id);
	
	cout << "Enter your name: ";
	getline(cin, name);
	
	birthday.nhap();
	
	cin.ignore();
	do {
		cout << "Enter the number of working days per month: ";
		cin >> workingDays;
	} while(workingDays <= 0 || workingDays > 31);
	cout << "=================================" << endl;
	
}
double CanBo::tinhLuong()
{
	return (double)workingDays * 250000;
}

void CanBo::xuat()
{
	cout << setw(10) << left << id <<
	setw(25) << left << name <<
	birthday.getDay() << "/" << birthday.getMonth() << "/" << setw(20) << left << birthday.getYear() <<
	setw(20) << left << workingDays << 
	setw(20) << left << setprecision(3) << fixed << tinhLuong() << endl; 
}

int main(){
	CanBo cb1, cb2;
	cb1.nhap();
	
	cb1.xuat();
}
