#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class SinhVien
{
private:	
	string maSv;
	string hoTen;
	double diemToan;
	double diemLy;
	double diemHoa;
public:
	void nhap() {
		cout << "Ma SV: ";
		getline(cin, maSv);
		
		cout << "Ho va ten: ";
		getline(cin, hoTen);
		
		cout << "Diem toan: ";
		cin >> diemToan;
		
		cout << "Diem ly: ";
		cin >> diemLy;
		
		cout << "Diem hoa: ";
		cin >> diemHoa;
		cin.ignore();
	}
	
	double tongDiem() {
		return diemHoa + diemLy + diemToan;
	}
	
	void xuat() {
		cout << setw(15) << left << maSv
		<< setw(20) << left << hoTen
		<< setw(15) << left << diemToan
		<< setw(15) << left << diemLy
		<< setw(15) << left << diemHoa 
		<< tongDiem() << endl;
	}
	
	friend void sapXepDiem(SinhVien sv[], int n);
};

void sapXepDiem(SinhVien sv[], int n) {
	SinhVien k;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (sv[i].tongDiem() > sv[j].tongDiem()) {
				k = sv[i];
				sv[i] = sv[j];
				sv[j] = k;
			}
		}		
	}
}

int main()
{
	SinhVien sv[100];
	int n;
	
	cout << "Nhap vao so sinh vien: ";
	cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		cout << "===================SINH VIEN "<< i + 1 << " ======================" << endl;
		sv[i].nhap();
	}
	
	sapXepDiem(sv, n);
	cout << "====================THONG TIN SINH VIEN=======================" << endl;
	cout << setw(15) << left << "ID"
		<< setw(20) << left << "FULL NAME"
		<< setw(15) << left << "DIEM TOAN"
		<< setw(15) << left << "DIEM LY"
		<< setw(15) << left << "DIEM HOA" 
		<< "TONG DIEM" << endl;
	for (int i = 0; i < n; i++) {
		sv[i].xuat();
	}
}
