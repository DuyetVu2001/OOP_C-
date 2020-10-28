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

int main()
{
	int ngay, thang, nam;
	cout << "Nhap vao ngay thang nam: ";
	cin >> ngay >> thang >> nam;
	
	if (ngayHopLe(ngay, thang, nam)) 
	{
		cout << "Yes!";
	}
	else 
	{
		cout << "No!";
	}
	return 0;
}

