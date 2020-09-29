#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Date 
{
private:
	string day;
	string month;
	string year;
public:
	void nhap () {
		cout << "Nhap vao ngay sinh: ";
		getline(cin, day);
	
		cout << "Nhap vao thang sinh: ";
		cin >> month;
		
		cout << "Nhap vao nam sinh: ";
		cin >> year;
	}	
	
	void xuat() {
		cout << day << "/" << month << "/" << year;
	}
	
	string getDay() {
		return day;
	}	
	
	string getMonth() {
		return month;
	}
	
	string getYear() {
		return year;
	}
	
};

class SinhVien
{
private:
	string studentId;
	string name;
	Date date;
	string gender;
	string majors;
	double diemTongKet;
	int *tuoi;
public:
	void nhap()	{
		cout << "=============================" << endl;
		cout << "Nhap ma sinh vien: ";
		getline(cin, studentId);
		
		cout << "Nhap ten sinh vien: ";
		getline(cin, name);
		
		date.nhap();
		cin.ignore();
		
		cout << "Nhap vao gioi tinh: ";
		getline(cin, gender);
		
		cout << "Nhap vao nganh hoc: ";
		getline(cin, majors);
		
		cout << "Nhap vao diem tong ket: ";
		cin >> diemTongKet;
		cin.ignore();	
	}
	
	void xuat() {
		cout << setw(10) << left << this->studentId 
		<< setw(30) << left << this->name 
		<< date.getDay() << "/" << date.getMonth() << "/" 
		<< setw(9) << left << date.getYear()
		<< setw(15) << left << this->gender
		<< setw(15) << this->majors 
		<< setprecision(3) << fixed << this->diemTongKet << endl;		
	}
	
	string getStudentId() {
		return this->studentId;
	}
	
	string getName() {
		return this->name;
	}
	
	string getGender() {
		return gender;
	}
	
	string getMajors() {
		return majors;
	}
	
	double getDiemTongKet() {
		return this->diemTongKet;
	}
	
	void copy(SinhVien src) {
		this -> studentId = src.studentId;
		this -> diemTongKet = src.diemTongKet;
		this -> gender = src.gender;
		this -> date = src.date;
		this -> majors = src.majors;
		this -> name = src.name;
		*(this -> tuoi) = *(src.tuoi);
	}
	
};

void chenSinhVienMoi(SinhVien *sv, int k, int n) {
	//Cach chen ko con tro
	for(int i = n; i > k; i--){
		sv[i] = sv[i - 1];
	}
	
	//Cach chen con tro
//	for (int i = n; i > k; i--) {
//		sv[i].copy(sv[i - 1]);
//	}
	sv[k].nhap();
}

int main() 
{	
	int n;
	SinhVien *sv = new SinhVien[100];
		
	cout << "Nhap vao so luong sinh vien can nhap: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		(sv + i) -> nhap();
	}
	
	cout << "=============================" << endl;
	cout << setw(10) << left << "ID"
		<< setw(30) << left << "NAME"
		<< setw(15) << left << "DATE"
		<< setw(15) << left << "GENDER"
		<< setw(15) << "MAJORS" 
		<< "DIEM TK" << endl;
	for (int i = 0; i < n; i++) {
		(sv + i)->xuat();
	}
	
	double max = 0;
	int index = 0;
	cout << "=============================" << endl;
	cout << "Nhung sinh vien co diem tong ket cao nhat: " << endl;
	for (int i = 0; i < n; i++) {
		if ( (*(sv + i)).getDiemTongKet() > max) {
			index = i;
			max = (sv + i) -> getDiemTongKet();
		}
	}
	
	for (int i = 0; i < n; i++) {
		if ((sv + i) -> getDiemTongKet() == max) {
			(sv + i) -> xuat();
		}
	}
	
	int k;
	cout << "=============================" << endl;
	cout << "Nhap vao vi tri can chen: ";
	cin >> k;
	cin.ignore();
	
	chenSinhVienMoi(sv, k, n); //Ham dich va nhap sv
	
	cout << "=============================" << endl;
	cout << setw(10) << left << "ID"
		<< setw(30) << left << "NAME"
		<< setw(15) << left << "DATE"
		<< setw(15) << left << "GENDER"
		<< setw(15) << "MAJORS" 
		<< "DIEM TK" << endl;
	for (int i = 0; i < n + 1; i++) {
		(sv + i)->xuat();
	}
}
