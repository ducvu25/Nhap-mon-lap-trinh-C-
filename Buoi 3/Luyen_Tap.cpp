#include <iostream>
using namespace std;

void HinhThoi(int n)
{
    int d = 0;
    for (int i = 0; i < 2 * n + 1; i++)
    {
        for (int j = 0; j <= n + d; j++)
            if (j == n - d || j == n + d)
                cout << "*";
            else
                cout << " ";
        if (i < n)
            d++;
        else
            d--;
        cout << endl;
    }
}
void ChuHoa(char &a)
{
    if (a >= 'A' && a <= 'Z')
        a += 32;
}
int SoNhoNhat(int a, int b, int c, int d)
{
    int min = a;
    if (b < min)
    {
        min = b;
    }
    if (c < min)
    {
        min = c;
    }
    if (d < min)
    {
        min = d;
    }
    return min;
}
void Swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}
// 1. Tìm max
// 2. Tìm max2 < n
int Max(int a, int b, int c, int d)
{
    int max = a;

    if (max < b)
        max = b;
    if (max < c)
        max = c;
    if (max < d)
        max = d;

    return max;
}
int Max(int a, int b, int c, int d, int max)
{ // 5 1 2 3 // 3 4 5 1
    int max2;
    if (a < max)
    {
        max2 = a; // 3
    }
    else
    {
        max2 = max + 1; // 6
    }

    if (b < max)
    {
        if (max2 == max + 1 || max2 < b)
        {
            max2 = b;
        }
    }
    if (c < max)
    {
        if (max2 == max + 1 || max2 < c)
        {
            max2 = c;
        }
    }
    if (d < max)
    {
        if (max2 == max + 1 || max2 < d)
        {
            max2 = d;
        }
    }
    return max2;
}
void Sort(int &a, int &b, int &c, int &d)
{
    int max = Max(a, b, c, d),
        max2 = Max(a, b, c, d, max),
        max3 = Max(a, b, c, d, max2),
        max4 = Max(a, b, c, d, max3);
    a = max;
    b = max2;
    c = max3;
    d = max4;
}
int main()
{
    // int n;
    // cout << "Nhap n: ";
    // cin >> n;
    // cout << "Hinh thoi: " << n << endl;
    // HinhThoi(n);
    // cout << "Hinh thoi: " << n + 1 << endl;
    // HinhThoi(n + 1);

    // 1a
    // char c;
    // cout << "Nhap ki tu: ";
    // cin >> c;
    // ChuHoa(c);
    // cout << "Sau khi thay doi: " << c;

    // 1.b
    int a, b, c, d;
    cout << "Nhap: ";
    cin >> a >> b >> c >> d;
    Sort(a, b, c, d);
    cout << a << " " << b << " " << c << " " << d;
    // cout << "Min: " << SoNhoNhat(a, b, c, d);
    //  Bai1. a, d, e, f
    //  Bai2.
    return 0;
}

/*
Bai tu luyen:
 File: 2, 3, 4, 5
 1000 bai code:
 105, 110, 119
 Liệt kê các số đẹp, fbnc trong khoang (a, b)
*/