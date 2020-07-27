#include <iostream>
#include <math.h>

using namespace std;

class HCN{
private:
    double chieuDai;
    double chieuRong;
public:
    void Nhap();
    void Ve();
    double ChuVi();
    double DienTich();
};

void HCN::Nhap(){
    cout << "Nhap chieu dai: ";
    cin >> chieuDai;
    cout << "Nhap chieu rong: ";
    cin >> chieuRong;
}

void HCN::Ve(){
    for(int i = 1; i <= (int)chieuDai; i++){
        for(int j = 1; j <= (int)chieuRong; j++){
            if(i == 1 || i == chieuDai || j == 1 || j == chieuRong){
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

double HCN::ChuVi(){
    return (chieuDai + chieuRong) * 2;
}

double HCN::DienTich(){
    return chieuDai * chieuRong;
}

int main(){
    HCN hcn;
    hcn.Nhap();
    hcn.Ve();
    cout << "Chu vi hinh chu nhat: " << hcn.ChuVi() << endl;
    cout << "Dien tich hinh chu nhat: " << hcn.DienTich();
    return 0;
}
