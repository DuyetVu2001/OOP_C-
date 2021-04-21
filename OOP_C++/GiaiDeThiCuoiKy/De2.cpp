#include <iostream>
using namespace std;
#include <string>
#include <iomanip>

class NhaSanXuat {
private:
	string Ten_NSX;
	string Dia_Chi;
	
public: 
	string getTen_NSX () {
		return Ten_NSX;
	}
	void nhap () {
		cout << "+ Nhap vao ten NSX: ";
		getline(cin, Ten_NSX);
		
		cout << "+ Nhap vao dia chi NSX: ";
		getline(cin, Dia_Chi);
	}
	void xuat () {
		cout << left;
		cout << setw(20) << Ten_NSX
		<< setw(15) << Dia_Chi;
	}
};

class MAY {
protected:
	string NhanHieu;
	NhaSanXuat x;
	float GiaThanh;
	
public: 
	string getNhanHieu () {
		return this->NhanHieu;
	}
	NhaSanXuat getNhaSanXuat () {
		return x;
	}
	void nhap () {
		cout << "+ Nhap vao nhan hieu: ";
		getline(cin, NhanHieu);
		
		x.nhap();
		
		cout << "+ Nhap vao gia thanh: ";
		cin >> GiaThanh;
		cin.ignore();
	}
	void xuat () {
		cout << left;
		cout << setw(15) << NhanHieu;
		x.xuat();
		cout << setw(15) << GiaThanh;
	}
};

class MAYIN : public MAY {
private:
	int TocDo;
	int DoPhanGiai;
	
public:
	void nhap () {
		MAY::nhap();
		
		cout << "+ Nhap vao toc do in: ";
		cin >> TocDo;
		
		cout << "+ Nhap vao do phan giai: ";
		cin >> DoPhanGiai;
		cin.ignore();
	}
	void xuat () {
		MAY::xuat();
		
		cout << setw(15) << TocDo
		<< setw(15) << DoPhanGiai << endl;
	}
};

void title () {
	cout << left;
	cout << setw(15) << "Nhan Hieu"
	<< setw(20) << "Ten NSX"
	<< setw(15) << "DIA CHIA"
	<< setw(15) << "Gia"
	<< setw(15) << "Toc Do"
	<< setw(15) << "Phan Giai" << endl;
}

void nhapTT(MAYIN mi[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "\n- NHAP VAO THONG TIN MAI IN " << i + 1 << ".\n";
		mi[i].nhap();
	}
}

//a
void xuatTT(MAYIN mi[], int n) {
	cout << "\n\tTHONG TIN\n";
	title();
	for (int i = 0; i < n; i++) {
		mi[i].xuat();
	}
}

//b
void hienThiMF242e(MAYIN mi[], int n) {
	cout << "\n\tTHONG TIN MF242e\n";
	title();
	for (int i = 0; i < n; i++) {
		if (mi[i].getNhanHieu() == "MF242e") {
			mi[i].xuat();
		}
	}
}

//c
void hienThiHP(MAYIN mi[], int n) {
	cout << "\n\tTHONG TIN HP\n";
	title();
	for (int i = 0; i < n; i++) {
		if (mi[i].getNhaSanXuat().getTen_NSX() == "HP") {
			mi[i].xuat();
		}
	}
}

//d
void chenMI(MAYIN mi[], int n) {
	MAYIN miNew;
	int k = 0;
	cout << "\n- NHAP THONG TIN MAY IN: \n";
	miNew.nhap();
	
	do {
		cout << "\n- Nhap vao so nguyen duong k: ";
		cin >> k;
	} while (k < 0 || k > n);
	
	for (int i = n; i > k; i--) {
		mi[i] = mi[i - 1];
	}
	mi[k] = miNew;
	n++;
	
//	Xuat
	cout << "\nTHONG CAP NHAT SAU KHI CHEN\n";
	xuatTT(mi, n);
}

int main() {
	MAYIN mi[100];
	int n = 0;
	
	cout << "- Nhap vao sanh sach n may in: ";
	cin >> n;
	cin.ignore();
	
//	Nhap
	nhapTT(mi, n);
	
//	Xuat may thong tin
	xuatTT(mi, n);
	
	hienThiMF242e(mi, n);
	hienThiHP(mi, n);
	chenMI(mi, n);
	return 0;
}
