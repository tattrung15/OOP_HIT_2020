#include <iostream>
#include <math.h>

using namespace std;

class PTB2{
private:
    double a;
    double b;
    double c;
public:
    PTB2(){
        this->a = 0;
        this->b = 0;
        this->c = 0;
    }
    PTB2(double a, double b, double c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void Nhap();
    void Xuat();
    void Giai();
};

void PTB2::Nhap(){
    cout << "Nhap he so a: ";
    cin >> a;
    cout << "Nhap he so b: ";
    cin >> b;
    cout << "Nhap he so c: ";
    cin >> c;
}

void PTB2::Xuat(){
    cout << a << "x^2 + " << b << "x + " << c << " = 0" << endl;
}

void PTB2::Giai(){
    if(a == 0){
        if(b == 0){
            if(c == 0){
                cout << "Phuong trinh vo so nghiem" << endl;
            } else {
                cout << "Phuong trinh vo nghiem" << endl;
            }
        } else {
            cout << "Phuong trinh co nghiem x = " << -c / b << endl;
        }
    } else {
        double d = b*b - 4*a*c;
        if(d < 0){
            cout << "Phuong trinh vo nghiem" << endl;
        } else if(d == 0){
            cout << "Phuong trinh co nghiem kep x1 = x2 = " << -b / (2 * a) << endl;
        } else {
            cout << "x1 = " << (-b + sqrt(d))/(2 * a) << endl;
            cout << "x2 = " << (-b - sqrt(d))/(2 * a) << endl;
        }
    }
}

int main(){
    PTB2 p(1, 2, 3);
    p.Xuat();
    p.Giai();
    PTB2 q;
    q.Nhap();
    q.Xuat();
    q.Giai();
    return 0;
}
