#include <iostream>
#include <string.h>
using namespace std;

class PERSON{
protected:
    char hoTen[15];
    char ngaySinh[15];
    char queQuan[15];
};
class KYSU: public PERSON{
private:
    char Nganh[20];
    int namTN;
public:
    void Nhap();
    void Xuat();
    friend int maxTN(KYSU a[], int n);
    friend void show(KYSU a[], int n);
};
void KYSU::Nhap(){
    cout<<"nhap Ho ten: ";
    fflush(stdin);
    gets(hoTen);
    cout<<"nhap ngay sinh: ";
    fflush(stdin);
    gets(ngaySinh);
    cout<<"nhap que quan: ";
    fflush(stdin);
    gets(queQuan);
    cout<<"nhap nganh: ";
    fflush(stdin);
    gets(Nganh);
    cout<<"nhap nam tn: ";
    cin>>namTN;
}
void KYSU::Xuat(){
    cout<<"Ho ten: "<<hoTen<<"\t";
    cout<<"Ngay sinh: "<<ngaySinh<<"\t";
    cout<<"Que quan: "<<queQuan<<endl;
    cout<<"Nganh: "<<Nganh<<"\t ";
    cout<<"Nam TN: "<<namTN<<endl;
}
int maxTN(KYSU a[], int n){
    int maxNam = a[0].namTN;
    for(int i=1;i<n;i++){
        if (a[i].namTN > maxNam){
            maxNam = a[i].namTN;
        }
    }
    return maxNam;
}
void show(KYSU a[], int n){
    int max1 = maxTN(a,3);
    cout<<"------DANH SACH TOT NGHIEP----"<<endl;
    for(int i=0;i<3;i++){
        if (a[i].namTN == max1){
            a[i].Xuat();
        }
    }
}
int main(){
    KYSU a[3];
    for(int i=0;i<3;i++){
        cout<<"Nhap ky su thu "<<i+1<<endl;
        a[i].Nhap();
    }
    cout<<">>>>>>>>>>>>>>>DANH SACH<<<<<<<<<<<<<<"<<endl;
    for(int i=0;i<3;i++){
        a[i].Xuat();
    }
    show(a,3);
    return 0;
}
