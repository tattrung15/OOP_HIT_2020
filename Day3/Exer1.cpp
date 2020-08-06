#include <iostream>
#include <iomanip>
#include <string.h>

using namespace std;

class Student;

class DiaChi{
private:
    int soNha;
    int soDuong;
    char tenThanhPho[50];
    friend class Student;
    friend void TimKiem(Student *x, int n);
};

class Student{
private:
    char maSV[15];
    char hoTen[50];
    DiaChi diaChi;
public:
    void Nhap();
    void Xuat();
    friend void SapXep(Student *x, int n);
    friend void TimKiem(Student *x, int n);
};

void Student::Nhap(){
    cout << "\tNhap ma sv: ";
    fflush(stdin);
    gets(maSV);
    cout << "\tNhap ho ten: ";
    fflush(stdin);
    gets(hoTen);
    cout << "\tNhap so nha: ";
    cin >> diaChi.soNha;
    cout << "\tNhap so duong: ";
    cin >> diaChi.soDuong;
    cout << "\tNhap ten thanh pho: ";
    fflush(stdin);
    gets(diaChi.tenThanhPho);
}

void Student::Xuat(){
    cout << setw(10) << maSV;
    cout << setw(25) << hoTen;
    cout << setw(10) << diaChi.soNha;
    cout << setw(10) << diaChi.soDuong;
    cout << setw(25) << diaChi.tenThanhPho;
}

void SapXep(Student *x, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(strcmpi(x[j - 1].hoTen, x[j].hoTen) > 0){
                swap(x[j - 1], x[j]);
            }
        }
    }
}

void TimKiem(Student *x, int n){
    for(int i = 0; i < n; i++){
        if(x[i].diaChi.soNha < 100 || x[i].diaChi.soDuong > 40 || strcmpi(x[i].diaChi.tenThanhPho, "Da Nang") == 0){
            x[i].Xuat();
            cout << endl;
        }
    }
}

int main(){
    Student *x = new Student[5];
    for(int i = 0; i < 5; i++){
        cout << "Nhap thong tin sv thu " << i + 1 << endl;
        x[i].Nhap();
    }
    cout << "-------------------------SAP XEP THEO TEN-------------------------" << endl;
    SapXep(x, 5);
    cout << setw(10) << "Ma SV";
    cout << setw(25) << "Ho ten";
    cout << setw(10) << "So nha";
    cout << setw(10) << "So duong";
    cout << setw(25) << "Ten thanh pho" << endl;
    for(int i = 0; i < 5; i++){
        x[i].Xuat();
        cout << endl;
    }
    cout << "-------------------------SAU KHI LOC-------------------------" << endl;
    cout << setw(10) << "Ma SV";
    cout << setw(25) << "Ho ten";
    cout << setw(10) << "So nha";
    cout << setw(10) << "So duong";
    cout << setw(25) << "Ten thanh pho" << endl;
    TimKiem(x, 5);
    return 0;
}
