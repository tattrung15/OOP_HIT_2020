#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

class DoanhNghiep;

class Date{
private:
    int day;
    int month;
    int year;
public:
    void Nhap();
    void Xuat();
friend long TongDoanhThuTheoNgayTL(DoanhNghiep *x, int n, int nam);
};

class DiaChi{
private:
    char dienThoai[12];
    char phuong[30];
    char quan[30];
    char thanhPho[30];
friend class DoanhNghiep;
friend void TimDNTheoThanhPho(DoanhNghiep *x, int n, const char *thanhPho);
};

class DoanhNghiep{
private:
    int maDN;
    char tenDN[60];
    Date ngayTL;
    DiaChi diaChi;
    char giamDoc[30];
    long doanhThu;
public:
    void Nhap();
    void Xuat();
friend void TimDNTheoThanhPho(DoanhNghiep *x, int n, const char *thanhPho);
friend long TongDoanhThuTheoNgayTL(DoanhNghiep *x, int n, int nam);
};

void Date::Nhap(){
    cout << "\tNhap ngay: ";
    cin >> day;
    cout << "\tNhap thang: ";
    cin >> month;
    cout << "\tNhap nam: ";
    cin >> year;
}

void Date::Xuat(){
    cout << day << "/" << month << "/" << year;
}

void DoanhNghiep::Nhap(){
    cout << "\tNhap ma doanh nghiep: ";
    cin >> maDN;
    cout << "\tNhap ten doanh nghiep: ";
    fflush(stdin);
    gets(tenDN);
    cout << "\tNhap ngay thanh lap" << endl;
    ngayTL.Nhap();
    cout << "\tNhap dien thoai: ";
    fflush(stdin);
    gets(diaChi.dienThoai);
    cout << "\tNhap phuong: ";
    fflush(stdin);
    gets(diaChi.phuong);
    cout << "\tNhap quan: ";
    fflush(stdin);
    gets(diaChi.quan);
    cout << "\tNhap thang pho: ";
    fflush(stdin);
    gets(diaChi.thanhPho);
    cout << "\tNhap giam doc: ";
    fflush(stdin);
    gets(giamDoc);
    cout << "\tNhap doanh thu: ";
    cin >> doanhThu;
}

void DoanhNghiep::Xuat(){
    cout << setw(5) << maDN;
    cout << setw(25) << tenDN;
    cout << setw(15);
    ngayTL.Xuat();
    cout << setw(12) << diaChi.dienThoai;
    cout << setw(25) << diaChi.phuong;
    cout << setw(25) << diaChi.quan;
    cout << setw(25) << diaChi.thanhPho;
    cout << setw(25) << giamDoc;
    cout << setw(15) << doanhThu;
}

void TieuDe(){
    cout << setw(5) << "Ma DN";
    cout << setw(25) << "Ten DN";
    cout << setw(15) << "Ngay TN";
    cout << setw(12) << "Dien thoai";
    cout << setw(25) << "Phuong";
    cout << setw(25) << "Quan";
    cout << setw(25) << "Thanh pho";
    cout << setw(25) << "Giam doc";
    cout << setw(15) << "Doanh thu" << endl;
}

void TimDNTheoThanhPho(DoanhNghiep *x, int n, const char *thanhPho){
    bool check = false;
    for(int i = 0; i < n; i++){
        if(strcmpi(x[i].diaChi.thanhPho, thanhPho) == 0){
            check = true;
            break;
        }
    }
    if(check){
        cout << "--------------------------DANH SACH DOANH NGHIEP O THANH PHO " << thanhPho << "--------------------------" << endl;
        TieuDe();
        for(int i = 0; i < n; i++){
            if(strcmpi(x[i].diaChi.thanhPho, thanhPho) == 0){
                x[i].Xuat();
                cout << endl;
            }
        }
    } else {
        cout << "Khong co doanh nghiep o thanh pho " << thanhPho << endl;
    }
}

long TongDoanhThuTheoNgayTL(DoanhNghiep *x, int n, int nam){
    long tong = 0;
    for(int i = 0; i < n; i++){
        if(x[i].ngayTL.year == nam){
            tong += x[i].doanhThu;
        }
    }
    return tong;
}

int main(){
    int n;
    cout << "Nhap so doanh nghiep: ";
    cin >> n;
    DoanhNghiep *x = new DoanhNghiep[n];
    for(int i = 0; i < n; i++){
        cout << "Nhap thong tin doanh nghiep thu " << i + 1 << endl;
        x[i].Nhap();
    }
    TimDNTheoThanhPho(x, n, "Ha Noi");
    cout << "Tong doanh thu nhung doanh nghiep thanh lap nam 2015: " << TongDoanhThuTheoNgayTL(x, n, 2015);
    return 0;
}