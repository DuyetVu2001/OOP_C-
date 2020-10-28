#include <iostream>
using namespace std;

bool namNhuan (int n) 
{
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
	{
		return true;
	}
	return false;
}

int soNgayTrongThang (int thang, int nam)
{
	int soNgay;
	
	switch (thang) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			soNgay = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			soNgay = 30;
			break;
		case 2:
			if (namNhuan(nam))
			{
				soNgay = 29;
			}
			else
			{
				soNgay = 28;
			}		
	}
	return soNgay;
}

bool ngayHopLe (int ngay, int thang, int nam) 
{
	if (nam < 1) 
	{
		return false;
	}
	if (thang < 1 || thang > 12) 
	{
		return false;
	}
	if (ngay < 1 || ngay > soNgayTrongThang(thang, nam))
	{
		return false;
	}
	return true;
}

void ngayTruocCuaMotNgay (int ngay, int thang, int nam)
{
	int ngayTruoc = ngay, thangTruoc = thang, namTruoc = nam;
	
	ngayTruoc = ngay - 1;
	//Kiem tra ngay hop le
	if (!ngayHopLe(ngayTruoc, thang, nam))
	{
		thangTruoc = thang - 1;
		ngayTruoc = soNgayTrongThang(thangTruoc, nam);
		//Kiem tra thang hop le
		if (!ngayHopLe(ngayTruoc, thangTruoc, nam)) 
		{
			thangTruoc = 12;
			ngayTruoc = 31;
			namTruoc = nam - 1;
		}
	}
	
	cout << "Ngay truoc cua " << ngay << "/" << thang << "/" << nam << " la: " << ngayTruoc << "/" << thangTruoc << "/" << namTruoc << endl;
}

void ngaySauCuaMotNgay (int ngay, int thang, int nam)
{
	int ngaySau = ngay, thangSau = thang, namSau = nam;
	
	ngaySau = ngay + 1;
	//Kiem tra ngay hop le
	if (!ngayHopLe(ngaySau, thang, nam))
	{
		thangSau = thang + 1;
		ngaySau = 1;
		//Kiem tra thang hop le
		if (!ngayHopLe(ngaySau, thangSau, nam)) 
		{
			thangSau = 1;
			ngaySau = 1;
			namSau = nam + 1;
		}
	}
	
	cout << "Ngay sau cua " << ngay << "/" << thang << "/" << nam << " la: " << ngaySau << "/" << thangSau << "/" << namSau << endl;
}

int main()
{
	int ngay, thang, nam;
	
	cout << "Nhap vao lan luot ngay, thang, nam: ";
	cin >> ngay >> thang >> nam;
	
	ngayTruocCuaMotNgay(ngay, thang, nam);
	ngaySauCuaMotNgay(ngay, thang, nam);
	return 0;
}

