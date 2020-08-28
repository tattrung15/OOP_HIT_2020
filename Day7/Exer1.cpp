#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class SachGK;

class TacGia{
  private:
    char tenTacGia[100];
    char diaChiTG[100];
  public:
    friend class SachGK;
};

class NXB{
  private:
    char tenNXB[100];
    char diaChiNXB[100];
  public:
    friend class SachGK;
    friend void TimSachTheoTenNXB(SachGK *ds, int n, const char *tenNXB);
};

class IDSach{
  private:
    char maSach[15];
    char tenSach[100];
  public:
    void Nhap();
    void Xuat();
    friend void TimSachTheoTenSach(SachGK *ds, int n, const char *tenSach);
};

class SachGK : public IDSach{
  private:
    TacGia x;
    NXB y;
  public:
    void Nhap();
    void Xuat();
    friend void TimSachTheoTenNXB(SachGK *ds, int n, const char *tenNXB);
    friend void TimSachTheoTenSach(SachGK *ds, int n, const char *tenSach);
};

void IDSach::Nhap(){
  cout << "\tNhap ma sach: ";
  fflush(stdin);
  gets(maSach);
  cout << "\tNhap ten sach: ";
  fflush(stdin);
  gets(tenSach);
}

void IDSach::Xuat(){
  cout << setw(15) << maSach;
  cout << setw(25) << tenSach;
}

void SachGK::Nhap(){
  IDSach::Nhap();
  cout << "\tNhap ten tac gia: ";
  fflush(stdin);
  gets(x.tenTacGia);
  cout << "\tNhap dia chi tac gia: ";
  fflush(stdin);
  gets(x.diaChiTG);
  cout << "\tNhap ten NXB: ";
  fflush(stdin);
  gets(y.tenNXB);
  cout << "\tNhap dia chi NXB: ";
  fflush(stdin);
  gets(y.diaChiNXB);
}

void SachGK::Xuat(){
  IDSach::Xuat();
  cout << setw(25) << x.tenTacGia;
  cout << setw(25) << x.diaChiTG;
  cout << setw(25) << y.tenNXB;
  cout << setw(25) << y.diaChiNXB;
}

void TieuDe(){
  cout << setw(15) << "Ma sach";
  cout << setw(25) << "Ten sach";
  cout << setw(25) << "Ten tac gia";
  cout << setw(25) << "Dia chi tac gia";
  cout << setw(25) << "Ten NXB";
  cout << setw(25) << "Dia chi NXB" << endl;
}

void DanhSachSachGK(SachGK *ds, int n){
  TieuDe();
  for(int i = 0; i < n; i++){
    ds[i].Xuat();
    cout << endl;
  }
}

void TimSachTheoTenNXB(SachGK *ds, int n, const char *tenNXB){
  bool check = false;
  for(int i = 0; i < n; i++){
    if(strcmpi(ds[i].y.tenNXB, tenNXB) == 0){
      check = true;
      break;
    }
  }
  if(check){
    cout << "---------------------------DANH SACH SGK CUA NXB "<< tenNXB << "---------------------------" << endl;
    TieuDe();
    for(int i = 0; i < n; i++){
      if(strcmpi(ds[i].y.tenNXB, tenNXB) == 0){
        ds[i].Xuat();
        cout << endl;
      }
    }
  } else {
    cout << "Khong ton tai sach co NSX: " << tenNXB << endl;
  }
}

void TimSachTheoTenSach(SachGK *ds, int n, const char *tenSach){
  bool check = false;
  for(int i = 0; i < n; i++){
    if(strcmpi(ds[i].tenSach, tenSach) == 0){
      check = true;
      break;
    }
  }
  if(check){
    cout << "---------------------------DANH SACH SGK CO TEN "<< tenSach << "---------------------------" << endl;
    TieuDe();
    for(int i = 0; i < n; i++){
      if(strcmpi(ds[i].tenSach, tenSach) == 0){
        ds[i].Xuat();
        cout << endl;
      }
    }
  } else {
    cout << "Khong ton tai sach co ten: " << tenSach << endl;
  }
}

void ChenSachViTri(SachGK *ds, int &n, int k){
  ds = (SachGK *) realloc(ds, n + 1);// cap phat lai bo nho dong
  SachGK sach;
  cout << "Nhap thong tin sach moi" << endl;
  sach.Nhap();
  for(int i = n - 1; i >= k - 1; i--){
    ds[i + 1] = ds[i];
  }
  ds[k - 1] = sach;
  n++;
}

int main(){
  int n, k;
  cout << "Nhap so luong sach: ";
  cin >> n;
  SachGK *ds = new SachGK[n];
  for(int i = 0; i < n; i++){
    cout << "Nhap thong tin sach thu " << i + 1 << endl;
    ds[i].Nhap();
  }
  cout << "---------------------------DANH SACH SGK VUA NHAP---------------------------" << endl;
  DanhSachSachGK(ds, n);
  TimSachTheoTenNXB(ds, n, "Giao Duc");
  TimSachTheoTenSach(ds, n, "LTHDT");
  cout << "Nhap k: ";
  cin >> k;
  ChenSachViTri(ds, n, k);
  cout << "---------------------------DANH SACH SGK SAU KHI CHEN---------------------------" << endl;
  DanhSachSachGK(ds, n);
  return 0;
}