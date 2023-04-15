#include <iostream>
#include <math.h>
using namespace std;

int Reverse(int n)
{
    int m = 0;
    while (n != 0)
    {
        m = m * 10 + (n % 10);
        n /= 10;
    }
    return m;
}
bool sdx(int n)
{
    // if(Reverse(n) == n)
    //     return true;
    // return false;

    int m = 0;
    int b = n;
    while (n != 0)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }
    if (m == b)
        return true;
    return false;
}
bool chinhphuong(int n)
{
    int m = sqrt(n);
    if (m * m == n)
        return true;
    return false;
}
bool Prime(int n)
{
    if (n < 2)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int sumOdd(int n) // 12235 => 1 + 3 + 5 = 9
{
    int sum = 0;
    while (n != 0)
    {
        int a = n % 10;
        if (a % 2 == 1)
            sum += a;
        n /= 10;
    }
    return sum;
}
int SumPrime(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int a = n % 10;
        if (a == 2 || a == 3 || a == 5 || a == 7)
            sum += a;
        n /= 10;
    }
    return sum;
}
int SumCP(int n)
{
    int sum = 0;
    while (n != 0)
    {
        int a = n % 10;
        if (a == 1 || a == 4 || a == 9)
            sum += a;
        n /= 10;
    }
    return sum;
}
int main()
{
    int n;
    cout << "Nhap so n: ";
    cin >> n;
    cout << "Dao cua n: " << Reverse(n) << endl;
    if (sdx(n))
        cout << "So doi xung\n";
    else
        cout << "Khong phai so doi xung\n";

    if (chinhphuong(n))
        cout << "So CP\n";
    else
        cout << "Khong phai so CP\n";

    cout << "Tong cac chu so le trong n: " << sumOdd(n) << endl;
    cout << "Tong cac chu so nt trong n: " << SumPrime(n) << endl;
    cout << "Tong cac chu so cp trong n: " << SumCP(n) << endl;
    return 0;
}