#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class Truong {
private:
	string maTruong;
	string tenTruong;
	string diaChi;
	
public:
	void nhap() {
		cout << "+ Nhap ma truong: ";
		getline(cin, maTruong);
		cout << "+ Nhap ten truong: ";
		getline(cin, tenTruong);
		cout << "+ Nhap dia chi: ";
		getline(cin, diaChi);
	}
	void xuat() {
		cout << left;
		cout << setw(15) << maTruong
		<< setw(15) << tenTruong
		<< setw(15) << diaChi;
	}
};

class Khoa {
private:
	string maKhoa;
	string tenKhoa;
	string truongKhoa;
	
public:
	void nhap() {
		cout << "+ Nhap ma khoa: ";
		getline(cin, maKhoa);
		cout << "+ Nhap ten khoa: ";
		getline(cin, tenKhoa);
		cout << "+ Nhap truong khoa: ";
		getline(cin, truongKhoa);
	}
	void xuat() {
		cout << left;
		cout << setw(15) << maKhoa
		<< setw(15) << tenKhoa
		<< setw(15) << truongKhoa << endl;
	}
};

class Ban {
private:
	string maBan;
	string tenBan;
	string ngayThanLap;
	
public:
	void nhap() {
		cout << "+ Nhap ma ban: ";
		getline(cin, maBan);
		cout << "+ Nhap ten ban: ";
		getline(cin, tenBan);
		cout << "+ Nhap ngay than lap: ";
		getline(cin, ngayThanLap);
	}
	void xuat() {
		cout << left;
		cout << setw(15) << maBan
		<< setw(15) << tenBan
		<< setw(15) << ngayThanLap << endl;
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
		
		cout << "Nhap vao so khoa: ";
		cin >> n;
		cin.ignore();
		//Nhap khoa
		for (int i = 0; i < n; i++) {
			cout << "\n- NHAP THONG TIN KHOA " << i + 1 << ". " << endl;
			x[i].nhap();
		}
		
		cout << "Nhap vao so ban: ";
		cin >> m;
		cin.ignore();
		//Nhap ban
		for (int i = 0; i < m; i++) {
			cout << "\n- NHAP THONG TIN ban " << i + 1 << ". " << endl;
			y[i].nhap();
		}
	}
	void xuatTruong() {
		Truong::xuat();
	}
	void xuatKhoa() {
		//Xuat tt ban
		for (int i = 0; i < m; i++) {
			y[i].xuat();
		}
	}
	void xuatBan() {	
		//Xuat tt khoa
		for (int i = 0; i < n; i++) {
			x[i].xuat();
		}
	}
};

void titleTruong() {
	cout << left;
	cout << setw(15) << "Ma truong"
	<< setw(15) << "Ten truong"
	<< setw(15) << "Dia chi" << endl;
}

void titleKhoa() {
	cout << endl << left;
	cout << setw(15) << "Ma khoa"
	<< setw(15) << "Ten khoa"
	<< setw(15) << "Truong khoa" << endl;
}

void titleBan() {
	cout << endl << left;
	cout << setw(15) << "Ma ban"
	<< setw(15) << "Ten ban"
	<< setw(15) << "Ngay TL" << endl;
}

int main() {
	TruongDH tr;
	tr.nhap();
	//truong
	titleTruong();
	tr.xuatTruong();
	//ban
	titleBan();
	tr.xuatBan();
	//khoa
	titleKhoa();
	tr.xuatKhoa();
	return 0;
}

