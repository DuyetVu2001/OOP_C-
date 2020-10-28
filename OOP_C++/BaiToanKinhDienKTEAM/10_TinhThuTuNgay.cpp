#include <iostream>
using namespace std;

bool namNhuan (int nam)
{
	if ((nam % 4 == 0 && nam % 100 != 0) || nam % 100 == 0) 
	{
		return true;
	}
	return false;
}

int soNgayTrongThang (int thang, int nam) 
{
	int soNgay;
	switch (thang)
	{
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

int soThuTuNgay (int ngay, int thang, int nam)
{
	int soThuTuNgay = ngay;
	for (int i = 1; i <= thang - 1; i++)
	{
		soThuTuNgay += soNgayTrongThang(i, nam);
	}
	return soThuTuNgay;
}

int main()
{	
	int ngay, thang, nam;
	
	cout << "Nhap vao lan luot ngay, thang, nam: ";
	cin >> ngay >> thang >> nam;
	
	cout << "So thu tu ngay trong nam la: " << soThuTuNgay(ngay, thang, nam);
	return 0;
}

