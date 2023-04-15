#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    // Tinh sin x voi do chinh xac 0.000001
    float x;
    cout << "Nhap x: ";
    cin >> x;
    float Ln = 0, tu = x;
    int dau = 1, i = 1;
    while (tu / i > 0.000001)
    {
        Ln += dau * tu / i;
        dau = -dau;
        i++;
        tu *= x;
    }
    cout << "Tinh toan: " << Ln << endl;
    cout << "Thu vien: " << log10(x + 1) / log10(2.71);
    /*
    logA(B) = log10(B)/log10(A)*/
    return 0;
}