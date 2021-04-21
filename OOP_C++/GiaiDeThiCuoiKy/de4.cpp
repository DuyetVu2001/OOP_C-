#include <iostream>
using namespace std;
#include <string>
#include <iomanip>
#include <fstream>

class NSX {
private:
	string tenNSX, diaChi;
	
public:
	string getDiaChi() {
		return this->diaChi;
	}
	string getTenNSX() {
		return this->tenNSX;
	}
	void nhap() {
		cout << "+ Nhap ten NSX: ";
		getline(cin, tenNSX);
		
		cout << "+ Nhap dia chi NSX: ";
		getline(cin, diaChi);
	}
	void xuat() {
		cout << left;
		cout << setw(20) << tenNSX
		<< setw(20) << diaChi;
	}
};

class May {
protected: 
	string nhanHieu;
	NSX x;
	float giaThanh;	

public: 
	float getGiaThanh() {
		return this->giaThanh;
	}
	NSX getX() {
		return this->x;
	}
	string getNhanHieu() {
		return this->nhanHieu;
	}
	void nhap() {
		cout << "+ Nhap vao nhan hieu: ";
		getline(cin, nhanHieu);
		
		x.nhap();
		
		cout << "+ Nhap vao gia thanh: ";
		cin >> giaThanh;
	}
	void xuat() {
		cout << left;
		cout << setw(20) << nhanHieu;
		x.xuat();
		cout << setw(20) << giaThanh;
	}
};

class MayIn : public May {
private: 
	int tocDo, doPhanGiai;

public: 
	int getTocDo () {
		return this->tocDo;
	}
	int getDoPhanGiai () {
		return this->doPhanGiai;
	}
	void nhap() {
		May::nhap();
		
		cout << "+ Nhap vao toc do: ";
		cin >> tocDo;
		
		cout << "+ Nhap vao do phan giai: ";
		cin >> doPhanGiai;
		cin.ignore();
	}
	void xuat() {
		May::xuat();
		
		cout << setw(20) << tocDo
		<< setw(20) << doPhanGiai << endl;
	}
};

void title() {
	cout << left;
	cout << setw(20) << "Nhan hieu"
	<< setw(20) << "Ten NSX"
	<< setw(20) << "Dia chi"
	<< setw(20) << "Gia thanh"
	<< setw(20) << "Toc do"
	<< setw(20) << "Do PG" << endl;
}

void nhapTT(MayIn m[], int n) {
	for (int i = 0; i < n; i++) {
		m[i].nhap();
	}
}

void xuatTT(MayIn m[], int n) {
	title();
	for (int i = 0; i < n; i++) {
		m[i].xuat();
	} 
}

void xuatMF242e(MayIn m[], int n) {
	cout << "\n-MF242e: \n";
	title();
	for (int i = 0; i < n; i++) {
		if (m[i].getNhanHieu() == "MF242e") {
			m[i].xuat();
		}
	} 
}

void tenHP(MayIn m[], int n) {
	cout << "\n-HP: \n";
	title();
	for (int i = 0; i < n; i++) {
		if (m[i].getX().getTenNSX() == "HP") {
			m[i].xuat();
		}
	} 
}

void sapXepGia(MayIn m[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (m[i].getGiaThanh() > m[j].getGiaThanh()) {
				swap(m[i], m[j]);
			}
		}
	} 
	cout << "\n-Sau khi sap xep gia: \n";
	xuatTT(m, n);
}

void chen(MayIn m[], int &n) {
	int k;
	MayIn mayNew;
	
	cout << "\n- Nhap vao vi tri can chen: ";
	cin >> k;
	cin.ignore();
	
	mayNew.nhap();
	
	for (int i = n; i > k; i--) {
		m[i] = m[i - 1];
	}
	n++;
	m[k] = mayNew;
	cout << "\n-TT sau chen: \n";
	xuatTT(m, n);
}

void xoaHP(MayIn m[], int &n) {
	for (int i = 0; i < n; i++) {
		if (m[i].getX().getDiaChi() == "HaNoi") {
			for (int j = i; j < n - 1; j++) {
				m[j] = m[j + 1];
			}
			i--;
			n--;
		}
	} 
	cout << "\n-TT sau xoa Hanoi: \n";
	xuatTT(m, n);
}

void WriteToFile(MayIn *m, fstream &ofs, int n) {
	cout << left;
	ofs << setw(20) << "Nhan hieu";
	ofs << setw(20) << "Ten NSX";
	ofs << setw(20) << "Dia chi";
	ofs << setw(20) << "Gia thanh";
	ofs << setw(20) << "Toc do";
	ofs << setw(20) << "Do PG" << endl;
	
	for (int i = 0; i < n; i++) {
		cout << left;
		ofs << setw(20) << m[i].getNhanHieu();
		ofs << setw(20) << m[i].getX().getTenNSX();
		ofs << setw(20) << m[i].getX().getDiaChi();
		ofs << setw(20) << m[i].getGiaThanh();
		ofs << setw(20) << m[i].getTocDo();
		ofs << setw(20) << m[i].getDoPhanGiai() << endl;
	}
}

int main() {
	MayIn m[100];
	int n;
	
	cout << "- Nhap vao danh sach n may in: ";
	cin >> n;
	cin.ignore();
	
	nhapTT(m, n);
	xuatTT(m, n);
	xuatMF242e(m, n);
	tenHP(m, n);
	sapXepGia(m, n);
	chen(m, n);
	xoaHP(m, n);
	
	fstream ofs("May.txt", ios::out);
	WriteToFile(m, ofs, n);
	ofs.close();
	return 0;
}
