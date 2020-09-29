#include <iostream>
using namespace std;
#include <iomanip>
#include "Constants.h"
using namespace constants;

float tinhTienTaxi(float soKmNguoiDi) 
{
	float thanhTien(0);
	
	if (soKmNguoiDi <= NGUONG_1) 
		thanhTien = GIA_1 * soKmNguoiDi;
	else //km > 1
		if (soKmNguoiDi <= NGUONG_2) 
			thanhTien = NGUONG_1 * GIA_1 + (soKmNguoiDi - NGUONG_1) * GIA_2;
		else //km > 5
			thanhTien = NGUONG_1 * GIA_1 + (NGUONG_2 - NGUONG_1) * GIA_2 + GIA_3 * (soKmNguoiDi - NGUONG_2);
			if (soKmNguoiDi > NGUONG_3)
				thanhTien = thanhTien * (1.0 - SALE);
				
	return thanhTien;
}

int main()
{
	float soKmNguoiDi(0);
	float thanhTien(0);
	
	cout << "Nhap vao so km nguoi di: ";
	cin >> soKmNguoiDi;
	
	thanhTien = tinhTienTaxi(soKmNguoiDi);
	cout << "So tien phai tra: " << fixed << setprecision(3) << thanhTien << " vnd.";
}
