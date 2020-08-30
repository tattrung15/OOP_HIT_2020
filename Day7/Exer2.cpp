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
    HHCN operator+(int d);
    friend ostream& operator<<(ostream &os, HHCN x);
};

int HHCN::TheTich(){
  return chieuDai*chieuRong*chieuCao;
}

HHCN HHCN::operator+(int d){
  this->chieuDai += d;
  this->chieuRong += d;
  this->chieuCao += d;
  return *this;
}

ostream& operator<<(ostream &os, HHCN x){
  os << x.TheTich() << endl;
  return os;
}

int main(){
  HHCN h(2, 5, 7);
  cout << "The tich: " << h;
  int d;
  cout << "Nhap d: ";
  cin >> d;
  HHCN hs = h + d;
  cout << "The tich sau khi cong them do dai cac chieu: " << hs;
  return 0;
}
