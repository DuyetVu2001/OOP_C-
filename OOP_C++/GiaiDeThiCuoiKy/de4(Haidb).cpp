#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

class MAY;
class MAYIN;

class NhaSanXuat
{
    private:
        string Ten_NSX;
        string Dia_Chi;
    public:
        void nhap();
        void xuat();
        friend class MAY;
        friend void INNSX(MAYIN *a, int n);
        friend void WriteToFile(MAYIN *a, fstream &ofs, int n);
};

class MAY
{
    protected:
        string NhanHieu;
        NhaSanXuat x;
        float thanhGia;
    public:
        void nhap();
        void xuat();
};

class MAYIN:public MAY
{
    private:
        int tocDo;
        int DoPhanGiai;
    public:
        void nhap();
        void xuat();
        friend void INMF242e(MAYIN *a, int n);
        friend void INNSX(MAYIN *a, int n);
        friend void ChenK(MAYIN *a, int n);
        friend void WriteToFile(MAYIN *a, fstream &ofs, int n);
        friend void Xoa4(MAYIN *a, int &n);
};

void NhaSanXuat::nhap()
{
    cout<< "Nhap ten NSX : "; getline(cin, Ten_NSX);
    cout<< "Nhap dia chi NSX : "; getline(cin, Dia_Chi);
}
void NhaSanXuat::xuat()
{
    cout<<setw(20)<<left<<Ten_NSX;
    cout<<setw(20)<<left<<Dia_Chi;
}

void MAY::nhap()
{
    x.nhap();
    cout<< "Nhap nhan hieu : "; getline(cin, NhanHieu);
    cout<< "Nhap thanh gia : "; cin>> thanhGia; cin.ignore();
}
void MAY::xuat()
{
    x.xuat();
    cout<<setw(20)<<left<<NhanHieu;
    cout<<setw(20)<<left<<thanhGia;
}

void MAYIN::nhap()
{
    MAY::nhap();
    cout<< "Nhap toc do : " ; cin>>tocDo;
    cout<< "Nhap Do phan giai : "; cin>>DoPhanGiai; cin.ignore();
}
void MAYIN::xuat()
{
    MAY::xuat();
    cout<< setw(20)<<left<<tocDo;
    cout<< setw(20)<<left<<DoPhanGiai<<endl;
}

void title()
{
    cout<<setw(20)<<left<< "Ten NSX";
    cout<<setw(20)<<left<< "Dia chi NSX";
    cout<<setw(20)<<left<< "Nhan Hieu";
    cout<<setw(20)<<left<< "Thanh Gia";
    cout<<setw(20)<<left<< "Toc Do";
    cout<<setw(20)<<left<< "Do Phan Giai"<<endl;
}

void INMF242e(MAYIN *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if(a[i].NhanHieu=="MF242e") a[i].xuat();
    }
}
void INNSX(MAYIN *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if(a[i].x.Ten_NSX=="HP") a[i].xuat();
    }
    
}
void ChenK(MAYIN *a, int n)
{
    MAYIN m;
    int k;
    cout<< "Nhap vi tri ban muon chen : "; cin>>k; cin.ignore();
    m.nhap();
    for (int i = n; i > k; i--)
    {
        a[i] = a[i-1];
    }
    n++;
    a[k] = m;
}

void Xoa4(MAYIN *a, int &n)
{
    for (int i = 0; i < n; i++)
    {
        if(a[i].tocDo==4)
        {
            for (int j = i; j < n-1; j++)
            {
                a[j] = a[j+1];
            }
            n--;
            i--;
        }
    }
}
void WriteToFile(MAYIN *a, fstream &ofs, int n)
{
    ofs<<setw(20)<<left<< "Ten NSX";
    ofs<<setw(20)<<left<< "Dia chi NSX";
    ofs<<setw(20)<<left<< "Nhan Hieu";
    ofs<<setw(20)<<left<< "Thanh Gia";
    ofs<<setw(20)<<left<< "Toc Do";
    ofs<<setw(20)<<left<< "Do Phan Giai"<<endl;
    for (int i = 0; i < n; i++)
    {
        ofs<<setw(20)<<left<< a[i].x.Ten_NSX;
        ofs<<setw(20)<<left<< a[i].x.Dia_Chi;
        ofs<<setw(20)<<left<< a[i].NhanHieu;
        ofs<<setw(20)<<left<< a[i].thanhGia;
        ofs<<setw(20)<<left<< a[i].tocDo;
        ofs<<setw(20)<<left<< a[i].DoPhanGiai<<endl;
    }
}
int main()
{
    MAYIN *a;
    int n;
    cout<< "Nhap so may in : "; cin>>n; 
    cin.ignore();
    a = new MAYIN[n+1];
    for (int i = 0; i < n; i++)
    {
        a[i].nhap();
    }
    cout<< "------------------------------------------------"<<endl;
    fstream ofs("MAYIN.txt", ios::out);
    WriteToFile(a, ofs, n);
    ofs.close();
    title();
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    cout<< "------------------------------------------------"<<endl;
    cout<< "May in co nhan hieu MF242 la: "<<endl;
    title();
    INMF242e(a,n);
    cout<< "------------------------------------------------"<<endl;
    cout<< "May in ten NSX HP la: "<<endl;
    title();
    INNSX(a,n);
    /*cout<< "------------------------------------------------"<<endl;
    cout<< "Bang sau khi chen la : "<<endl;
    ChenK(a, n);
    title();
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }*/
    cout<< "------------------------------------------------"<<endl;
    cout<< "Bang sau khi chen la : "<<endl;
    Xoa4(a,n);
    for (int i = 0; i < n; i++)
    {
        a[i].xuat();
    }
    delete []a;
}
