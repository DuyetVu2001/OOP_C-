#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Khoa {
private:
	string maKhoa, tenKhoa, truongKhoa;
	
public:
	void nhap() {
		cout << "+ Nhap vao ma khoa: ";
		getline(cin, maKhoa);
		
		cout << "+ Nhap vao ten khoa: ";
		getline(cin, tenKhoa);
		
		cout << "+ Nhap vao truong khoa: ";
		getline(cin, truongKhoa);
	}
	void xuat() {
		cout << left;
		cout << setw(15) << maKhoa
		<< setw(15) << tenKhoa
		<< setw(20) << truongKhoa << endl;
	}
};

class Ban {
private: 
	string maBan, tenBan, ngayThanhLap;

public:
	void nhap() {
		cout << "+ Nhap vao ma ban: ";
		getline(cin, maBan);
		
		cout << "+ Nhap vao ten ban: ";
		getline(cin, tenBan);
		
		cout << "+ Nhap vao ngay thanh lap: ";;
		getline(cin, ngayThanhLap);
	}
	void xuat() {
		cout << left;
		cout << setw(15) << maBan
		<< setw(15) << tenBan
		<< setw(20) << ngayThanhLap << endl;
	}
};

class Truong {
protected:
	string maTruong, tenTruong, diaChi;
	
public: 
	void nhap() {
		cout << "+ Nhap vao ma truong: ";
		getline(cin, maTruong);
		
		cout << "+ Nhap vao ten truong: ";
		getline(cin, tenTruong);
		
		cout << "+ Nhap vao dia chi: ";
		getline(cin, diaChi);
	}
	void xuat() {
		cout << left;
		cout << setw(15) << maTruong
		<< setw(20) << tenTruong
		<< setw(15) << diaChi << endl;
	}
};

class TruongDH : public Truong {
private:
	Khoa x[100];
	int n;
	Ban y[100];
	int m;
	
public:
	void nhap() {
		Truong::nhap();
		
		cout << "\n- Nhap vao so khoa: ";
		cin >> n;
		cin.ignore();
		
		for (int i = 0; i < n; i++) {
			cout << "\n- NHAP VAO THONG TIN KHOA " << i + 1 << ".\n";
			x[i].nhap();
		}
		
		cout << "\n- Nhap vao so ban: ";
		cin >> m;
		cin.ignore();
		
		for (int i = 0; i < m; i++) {
			cout << "\n- NHAP VAO THONG TIN BAN " << i + 1 << ".\n";
			y[i].nhap();
		}
	}
	void xuat() {
		Truong::xuat();
	}
	void xuatBan() {
		for (int i = 0; i < n; i++) {
			x[i].xuat();
		}
	}
	void xuatKhoa() {
		for (int i = 0; i < m; i++) {
			y[i].xuat();
		}
	}
};

void titleTruong() {
	cout << left;
	cout << setw(15) << "Ma Truong"
	<< setw(20) << "Ten Truong"
	<< setw(15) << "Dia Chi" << endl;
}

void titleKhoa() {
	cout << left;
	cout << setw(15) << "Ma Khoa"
	<< setw(15) << "Ten Khoa"
	<< setw(20) << "Truong Khoa" << endl;
}

void titleBan() {
	cout << left;
	cout << setw(15) << "Ma Ban"
	<< setw(15) << "Ten Ban"
	<< setw(20) << "Ngay Thanh Lap" << endl;
}

void nhap(TruongDH trDH) {
	trDH.nhap();
}

void xuat(TruongDH trDH) {
	titleTruong();
	trDH.xuat();
	
	titleKhoa();
	trDH.xuatKhoa();
	
	titleBan();
	trDH.xuatBan();
}

int main () {
	TruongDH trDH;
	trDH.nhap();
	
	titleTruong();
	trDH.xuat();
	
	titleKhoa();
	trDH.xuatKhoa();
	
	titleBan();
	trDH.xuatBan();
	return 0;
}
