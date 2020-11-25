#include <iostream>

using namespace std;

class HHCN{
  private:
    int chieuDai, chieuRong, chieuCao;
  public:
    HHCN(){}
    HHCN(int chieuDai, int chieuRong, int chieuCao){
      this->chieuDai = chieuDai;
      this->chieuRong = chieuRong;
      this->chieuCao = chieuCao;
    }
    int TheTich();
    int operator+(HHCN &x);
    int operator-(HHCN &x);
    int operator>(HHCN &x);
    friend ostream& operator<<(ostream &os, HHCN x);
};

int HHCN::TheTich(){
  return chieuDai*chieuRong*chieuCao;
}

ostream& operator<<(ostream &os, HHCN x){
  os << x.TheTich() << endl;
  return os;
}

int HHCN::operator+(HHCN &x){
    return this->TheTich() + x.TheTich();
}
int HHCN::operator-(HHCN &x){
    return this->TheTich() - x.TheTich();
}
int HHCN::operator>(HHCN &x){
   if(this->TheTich() > x.TheTich())
    return 1;
   else
    return 0;
}
int main(){
  HHCN h(2, 5, 7);
  cout << "The tich: " << h;
  HHCN d(3, 4, 5);
  cout << "The tich: " << d;
  cout << "The tich sau khi cong: " << h + d << endl;
  cout << "The tich sau khi cong: " << h - d << endl;
  if(h>d){
    cout << "HHCN h > HHCN d" << endl;
  }
  else
    cout << "HHCN h < HHCN d";
  return 0;
}
