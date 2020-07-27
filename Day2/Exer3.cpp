#include <iostream>
#include <iomanip>

using namespace std;

class HangHoa{
private:
    char maHang[10];
    char tenHang[100];
    long donGia;
    int soLuong;
public:
    void Nhap();
    void Xuat();
};

void HangHoa::Nhap(){
    cout << "Nhap ma hang: ";
    fflush(stdin);
    gets(maHang);
    cout << "Nhap ten hang: ";
    fflush(stdin);
    gets(tenHang);
    cout << "Nhap don gia: ";
    cin >> donGia;
    cout << "Nhap so luong: ";
    cin >> soLuong;
}

void HangHoa::Xuat(){
    cout << setw(10) << maHang;
    cout << setw(30) << tenHang;
    cout << setw(15) << donGia;
    cout << setw(10) << soLuong;
    cout << setw(20) << soLuong*donGia << endl;
}

int main(){
    int n;
    cout << "Nhap so luong hang hoa: ";
    cin >> n;
    HangHoa *dsHangHoa = new HangHoa[n];
    for(int i =0; i < n; i++){
        cout << "Nhap thong tin mat hang thu " << i + 1 << endl;
        dsHangHoa[i].Nhap();
    }
    cout << "-------------------------------DANH SACH CAC HANG HOA-------------------------------" << endl;
    cout << setw(10) << "Ma hang";
    cout << setw(30) << "Ten hang";
    cout << setw(15) << "Don gia";
    cout << setw(10) << "So luong";
    cout << setw(20) << "Thanh tien" << endl;
    for(int i = 0; i < n; i++){
        dsHangHoa[i].Xuat();
    }
    return 0;
}
