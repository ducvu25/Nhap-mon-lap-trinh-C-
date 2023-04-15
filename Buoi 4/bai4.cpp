#include <iostream>

using namespace std;

int UCLN1(int m, int n)
{
    if (n < m)
        swap(m, n);
    for (int i = m; i >= 0; i--)
    {
        if (m % i == 0 && n % i == 0)
        {
            return i;
        }
    }
    return 1;
}
int UCLN2(int a, int b)
{
    while (a != b)
    {
        if (a > b)
            a -= b;
        if (a < b)
            b -= a;
    }
    return a;
}
int UCLN3(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
// co UCLN => BCNN = a*b / UCLN
int main()
{
    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    cout << "UCLN(" << a << ", " << b << ")= " << UCLN1(a, b) << endl;
    cout << "UCLN(" << a << ", " << b << ")= " << UCLN2(a, b) << endl;
    cout << "UCLN(" << a << ", " << b << ")= " << UCLN3(a, b) << endl;
    return 0;
}