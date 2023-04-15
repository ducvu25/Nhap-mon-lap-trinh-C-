#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Tinh sin x voi do chinh xac 0.000001
    float x;
    cout << "Nhap so do(rad): ";
    cin >> x;
    float Sin = 0, tu = x;
    long gt = 1;
    int dau = 1, i = 1;
    while (tu / gt > 0.000001)
    {
        Sin += dau * tu / gt;
        dau = -dau;
        i++;
        gt *= i * (i + 1);
        tu *= x * x;
    }
    cout << "Tinh toan: " << Sin << endl;
    cout << "Thu vien: " << sin(x);
    return 0;
}