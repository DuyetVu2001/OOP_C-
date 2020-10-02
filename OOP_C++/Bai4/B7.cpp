#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Date
{
private:
	string birthDay;
	int year;	
public:
	void nhap() {
		cout << "ENTER YOUR BIRTHDAY: ";
		getline(cin, birthDay);
		
		cout << "ENTER THE YEAR OF ESTABLISHED: ";
		cin >> year;
		cin.ignore();
	}
	
	void xuat() {
		cout << setw(15) << left << birthDay;
	}
	
	int getYear() {
		return this->year;
	}
};

class DiaChi
{
private:
	string phoneNumber;
	string ward;
	string district;
	string city;
public:
	void nhap() {
		cout << "ENTER THE PHONENUMBER: ";
		getline(cin, phoneNumber);
		
		cout << "ENTER THE WARD: ";
		getline(cin, ward);
		
		cout << "ENTER THE DISTRICT: ";
		getline(cin, district);
		
		cout << "ENTER THE CITY: ";
		getline(cin, city);
	}
	string getCity(){
		return city;
	}
	void xuat() {
		cout << setw(15) << left << phoneNumber
		<< setw(15) << left << ward
		<< setw(15) << left << district
		<< setw(15) << left << city;
	}
};

class DoanhNghiep
{
private:
	int ID;
	string name;
	Date dayEstablished;
	DiaChi address;
	string director;
	long doanhThu;		
public:
	void nhap() {
		cout << "ID: ";
		cin >> ID;
		cin.ignore();
		
		cout << "ENTER THE NAME: ";
		getline(cin, name);
		
		dayEstablished.nhap();
		address.nhap();
		
		cout << "ENTER REVENUE: ";
		cin >> doanhThu;
		cin.ignore();
	}
	
	DiaChi getAddress () {
		return address;
	}
	
	Date getDayEstablished() {
		return dayEstablished;
	}
	
	long getDoanhThu() {
		return doanhThu;	
	}
	
	int getID() {
		return ID;
	}
	
	void xuat() {
		cout << setw(10) << left << ID
		<< setw(20) << left << name;
		dayEstablished.xuat();
		address.xuat();
		cout << setw(15) << left << doanhThu;
	}
};

int main()
{
	DoanhNghiep dn[100];
	int n;
	long tongDoanhThu = 0;
	
	cout << "Nhap vao so doanh nghiep: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++)	{
		cout << "=====================DOANH NGHIEP " << i + 1 << "====================" << endl;
		dn[i].nhap();
	}
	
	cout << "=========================THONG TIN DOANH NGHIEP==========================" << endl;
	cout << setw(10) << left << "ID"
	<< setw(20) << left << "NAME"
	<< setw(15) << left << "BIRTHDAY"
	<< setw(15) << left << "PHONENUMBER"
	<< setw(15) << left << "WARD" 
	<< setw(15) << left << "DISTRICT" 
	<< setw(15) << left << "CITY" 
	<< setw(15) << left << "REVENUE";
	for (int i = 0; i < n; i++) {
		dn[i].xuat();
	}	
	
	cout << "========================THONG TIN DOANH NGHIEP O THANH PHO HA NOI=========================" << endl;
	cout << setw(10) << left << "ID"
	<< setw(20) << left << "NAME"
	<< setw(15) << left << "BIRTHDAY"
	<< setw(15) << left << "PHONENUMBER"
	<< setw(15) << left << "WARD" 
	<< setw(15) << left << "DISTRICT" 
	<< setw(15) << left << "CITY" 
	<< setw(15) << left << "REVENUE";
	for (int i = 0; i < n; i++) {
		if (dn[i].getAddress().getCity() == "Ha Noi")
			dn[i].xuat();
	}	
	
	cout << "\nTONG DOANH THU CUA NHUNG DOANH NGHIEP THANH LAP NAM 2015: ";
	for (int i = 0; i < n; i++) {
		if (dn[i].getDayEstablished().getYear() == 2015) {
			tongDoanhThu += dn[i].getDoanhThu();
		}
	}
	cout << endl << tongDoanhThu;
	
	int maDn;
	cout << "\nNhap vao ma doanh nghiep can sua: ";
	cin >> maDn;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		if(dn[i].getID() == maDn) {
			cout << "========SUA LAI THONG TIN DOANH NGHIEP CO ID LA " << maDn << " =========" << endl;
			dn[i].nhap();
			
			cout << "=========================THONG TIN DOANH NGHIEP (UPDATE)==========================" << endl;
			cout << setw(10) << left << "ID"
			<< setw(20) << left << "NAME"
			<< setw(15) << left << "BIRTHDAY"
			<< setw(15) << left << "PHONENUMBER"
			<< setw(15) << left << "WARD" 
			<< setw(15) << left << "DISTRICT" 
			<< setw(15) << left << "CITY" 
			<< setw(15) << left << "REVENUE";
			for (int i = 0; i < n; i++) {
				dn[i].xuat();
			}
			break;
		}
	}
}
