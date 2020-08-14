#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class PhongMay;

class MayTinh{
private:
    char maMay[10];
    char tenMay[20];
    float tocDoCPU;
    char hangSX[15];
    char diaChiSX[30];
    friend class PhongMay;
    friend void DSMayTinh(PhongMay p);
    friend void SapXep(PhongMay p);
    friend void ThongTinMayTinh(MayTinh mt);
    friend void TKTheoHangSXVaDiaChiSX(PhongMay p, const char *hangSX, const char *diaChiSX);
    friend void TKMTCoTocDoCPUMax(PhongMay p);
};

class PhongMay{
private:
    char tenPhongMay[20];
    char nguoiQuanLy[30];
    MayTinh *x;
    int n;
public:
    void Nhap();
    void Xuat();
    friend void DSMayTinh(PhongMay p);
    friend void SapXep(PhongMay p);
    friend void TKTheoHangSXVaDiaChiSX(PhongMay p, const char *hangSX, const char *diaChiSX);
    friend void TKMTCoTocDoCPUMax(PhongMay p);
};

void PhongMay::Nhap(){
    cout << "Nhap ten phong may: ";
    fflush(stdin);
    gets(tenPhongMay);
    cout << "Nhap nguoi quan ly: ";
    fflush(stdin);
    gets(nguoiQuanLy);
    cout << "Nhap so luong may tinh: ";
    cin >> n;
    x = new MayTinh[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin may thu " << i + 1 << endl;
        cout << "\tNhap ma may: ";
        fflush(stdin);
        gets(x[i].maMay);
        cout << "\tNhap ten may: ";
        fflush(stdin);
        gets(x[i].tenMay);
        cout << "\tNhap toc do CPU: ";
        cin >> x[i].tocDoCPU;
        cout << "\tNhap hang sx: ";
        fflush(stdin);
        gets(x[i].hangSX);
        cout << "\tNhap dia chi NSX: ";
        fflush(stdin);
        gets(x[i].diaChiSX);
    }
}

void TieuDe(){
    cout << setw(10) << "Ma may";
    cout << setw(20) << "Ten may";
    cout << setw(12) << "Toc do CPU";
    cout << setw(15) << "Hang SX";
    cout << setw(20) << "Dia chi SX" << endl;
}

void PhongMay::Xuat(){
    cout << "Ten phong may: " << tenPhongMay << endl;
    cout << "Nguoi quan ly: " << nguoiQuanLy << endl;
    TieuDe();
    DSMayTinh(*this);
}

void DSMayTinh(PhongMay p){
    for(int i = 0; i < p.n; i++){
        cout << setw(10) << p.x[i].maMay;
        cout << setw(20) << p.x[i].tenMay;
        cout << setw(8) << p.x[i].tocDoCPU;
        cout << setw(15) << p.x[i].hangSX;
        cout << setw(20) << p.x[i].diaChiSX << endl;
    }
}

void ThongTinMayTinh(MayTinh mt){
    cout << setw(10) << mt.maMay;
    cout << setw(20) << mt.tenMay;
    cout << setw(8) << mt.tocDoCPU;
    cout << setw(15) << mt.hangSX;
    cout << setw(20) << mt.diaChiSX << endl;
}


void SapXep(PhongMay p){
    for(int i = 0; i < p.n - 1; i++){
        for(int j = p.n - 1; j > i; j--){
            if(strcmpi(p.x[j - 1].tenMay, p.x[j].tenMay) > 0){
                //swap(p.x[j - 1], p.x[j]);
                MayTinh temp = p.x[j - 1];
                p.x[j - 1] = p.x[j];
                p.x[j] = temp;
            }
        }
    }
}

void TKTheoHangSXVaDiaChiSX(PhongMay p, const char *hangSX, const char *diaChiSX){
    bool check = false;
    for(int i = 0; i < p.n; i++){
        if(strcmpi(p.x[i].hangSX, hangSX) == 0 && strcmpi(p.x[i].diaChiSX, diaChiSX) == 0){
            check = true;
        }
    }
    if(check){
        TieuDe();
        for(int i = 0; i < p.n; i++){
            if(strcmpi(p.x[i].hangSX, hangSX) == 0 && strcmpi(p.x[i].diaChiSX, diaChiSX) == 0){
                ThongTinMayTinh(p.x[i]);
            }
        }
    } else {
        cout << "Khong ton tai.";
    }
}

void TKMTCoTocDoCPUMax(PhongMay p){
    float maxCPU = p.x[0].tocDoCPU;
    for(int i = 1; i < p.n; i++){
        if(p.x[i].tocDoCPU > maxCPU){
            maxCPU = p.x[i].tocDoCPU;
        }
    }
    TieuDe();
    for(int i = 0; i < p.n; i++){
        if(p.x[i].tocDoCPU == maxCPU){
            ThongTinMayTinh(p.x[i]);
        }
    }
}

int main(){
    PhongMay p1;
    p1.Nhap();
    cout << "--------------------------------" << endl;
    p1.Xuat();
    SapXep(p1);
    cout << "-------------------SAU KHI SAP XEP-------------------" << endl;
    TieuDe();
    DSMayTinh(p1);
    cout << "-------------------DS may tinh dell sx o HN-------------------" << endl;
    TKTheoHangSXVaDiaChiSX(p1, "Dell", "Ha Noi");
    cout << "-------------------DS may tinh toc do CPU lon nhat-------------------" << endl;
    //TieuDe();
    TKMTCoTocDoCPUMax(p1);
    return 0;
}
