#include <iostream>

using namespace std;

class Vehicle{
  private:
    char nhanHieu[50];
    int namSX;
    char hang[50];
  public:
    void Nhap();
    void Xuat();
};

class Oto : public Vehicle{
  private:
    int soChoNgoi;
    double dungTich;
  public:
    void Nhap();
    void Xuat();
};

class Moto : public Vehicle{
  private:
    double phanKhoi;
  public:
    void Nhap();
    void Xuat();
};

void Vehicle::Nhap(){
  cout << "Nhap nhan hieu: ";
  fflush(stdin);
  gets(nhanHieu);
  cout << "Nhap nam san xuat: ";
  cin >> namSX;
  cout << "Nhap hang: ";
  fflush(stdin);
  gets(hang);
}

void Vehicle::Xuat(){
  cout << "Nhan hieu: " << nhanHieu << endl;
  cout << "Nam san xuat: " << namSX << endl;
  cout << "Hang: " << hang << endl;
}

void Oto::Nhap(){
  Vehicle::Nhap();
  cout << "Nhap so cho ngoi: ";
  cin >> soChoNgoi;
  cout << "Nhap dung tich: ";
  cin >> dungTich;
}

void Oto::Xuat(){
  Vehicle::Xuat();
  cout << "So cho ngoi: " << soChoNgoi << endl;
  cout << "Dung tich: " << dungTich << endl;
}

void Moto::Nhap(){
  Vehicle::Nhap();
  cout << "Nhap phan khoi: ";
  cin >> phanKhoi;
}

void Moto::Xuat(){
  Vehicle::Xuat();
  cout << "Phan khoi: " << phanKhoi << endl;
}

int main(){
  Oto oto;
  Moto moto;
  cout << "--------------------------OTO--------------------------" << endl;
  oto.Nhap();
  cout << "--------------------------MOTO--------------------------" << endl;
  moto.Nhap();
  cout << "--------------------------OTO--------------------------" << endl;
  oto.Xuat();
  cout << "--------------------------MOTO--------------------------" << endl;
  moto.Xuat();
  return 0;
}