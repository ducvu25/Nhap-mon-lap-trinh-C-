#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Tinh sin x voi do chinh xac 0.000001
    float x;
    cout << "Nhap so do(rad): ";
    cin >> x;
    float Cos = 0, tu = 1;
    long gt = 1;
    int dau = 1, i = 0;
    while (tu / gt > 0.000001)
    {
        Cos += dau * tu / gt;
        dau = -dau;
        i++;
        gt *= i * (i + 1);
        tu *= x * x;
    }
    cout << "Tinh toan: " << Cos << endl;
    cout << "Thu vien: " << cos(x);
    return 0;
}