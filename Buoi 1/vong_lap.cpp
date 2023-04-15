#include <iostream>
#include <math.h> // cmath
using namespace std;

int main()
{
    // for (int i = 0; i < 5; i++)
    //     cout << i << endl;
    // int i = 1;
    // for (; i < 10; i++)
    //     cout << "for khuyet khoi tao " << i << endl;

    // for (int i = 0;; i++)
    //     if (i > 10)
    //         break;
    //     else
    //         cout << "for khuyet dk thuc hien " << i << endl;

    // for (int i = 0; i < 10;)
    // {
    //     cout << "for khuyet dk thuc hien " << i << endl;
    //     i++;
    // }
    // for (int i = 0, d = 0; i < 10 && d < 10; i++, d += 3)
    //     cout << i << " " << d << endl;

    // int i = 0;
    // while (i < 0)
    // {
    //     cout << i << endl;
    //     i++;
    // }
    // i = 0;
    // do
    // {
    //     cout << i << endl;
    //     i++;
    // } while (i < 0);

    // int n;
    // cout << "Nhap n: ";
    // cin >> n;
    // for (int i = 1; i <= sqrt(n); i++)
    //     if (n % i == 0)
    //         cout << i << " " << n / i << endl;
    // i: 1->...: i*n
    //

    int n;
    cin >> n;
    // if (n < 2)
    // {
    //     cout << n << " khong phai so nguyen to.";
    //     return 0;
    // }
    // for (int i = 2; i <= sqrt(n); i++)
    // {
    //     if (n % i == 0)
    //     {
    //         cout << n << " khong phai so nguyen to.";
    //         return 0;
    //     }
    // }
    // cout << n << " la so nguyen to.";

    /*
    fbnc
    F(n) = 1 // n < 2
    F(n) = F(n-1) + F(n-2) n >= 2

    int fn1 = 1, fn2 = 1;
    int fn3;
    // if (n < 2)
    //     fn3 = 1;
    // else
    // {
    //     for (int i = 2; i <= n; i++)
    //     {
    //         fn3 = fn2 + fn1;
    //         fn1 = fn2;
    //         fn2 = fn3;
    //     }
    // }// 1, 1, 2, 3, 5, 8
    // cout << fn3;
    if (n <= 0)
    {
        cout << "khong phai!";
    }
    else
    {
        int fn1 = 1, fn2 = 1;
        int fn3;
        if (n < 2)
            fn3 = 1;
        else
        {
            do
            {
                fn3 = fn2 + fn1;
                fn1 = fn2;
                fn2 = fn3;
            } while (fn3 < n);
            if (fn3 == n)
                cout << "phai!";
            else
                cout << "khong phai!";
        }
    }

    // chinh phuong
    if (n > 0)
    {
        int d = sqrt(n);
        if (d * d == n)
            cout << "phai!";
        else
            cout << "Khong phai.";
    }
    else
        cout << "Khong phai.";

    // so dep
    */
    if (n > 0)
    {
        // int m = 0; // m == n
        // for (int i = 1; i < n; i++)
        //     if (n % i == 0)
        //         m += i;

        int m = 1; // m == n
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0)
                if (i == n / i)
                    m += i;
                else
                    m += i + n / i;

        if (m == n)
            cout << "phai.";
        else
            cout << "khong phai.";
    }
    else
        cout << "Khong phai.";
    return 0;
}