#include <iostream>
using namespace std;

//Kiem tra nam nhuan
bool namNhuan (int n) 
{
	if ((n % 4 == 0 && n % 100 != 0) || n % 400 == 0)
	{
		return true;
	}
	return false;
}

void inRaNamNhuan (int nStart, int nEnd)
{
	for (int i = nStart; i <= nEnd; i++) 
	{
		if (namNhuan(i))
		{
			cout << i << "\t";
		}
	}
}

int main()
{
	int nStartYear;
	int nEndYear;
	
	cout << "Enter the starting year: ";
	cin >> nStartYear;
	
	cout << "Enter the ending year: ";
	cin >> nEndYear;
	
	inRaNamNhuan(nStartYear, nEndYear);
	return 0;
}

