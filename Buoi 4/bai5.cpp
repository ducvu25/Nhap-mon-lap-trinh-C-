#include <iostream>

using namespace std;

void fbnc(int n)
{ // 1 với n <= 2
  // f(n-1) + f(n-2) với n > 2
    int a[1005];
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
// C1: Tìm số fbnc i sau đó in ra bằng vòng lặp: dễ nhìn, dễ hiểu, đơn giản, nhước điểm: tính đi tính lại nhiều lần
// C2: Vừa tìm vừa in: tính nhanh, khó biểu diễn
void FBNC(int n)
{
    // xét TH >= 1 in ra a[1] => 1
    // xét TH >= 2 in ra a[2] => 1
    // TH còn lại có ct: x = 1, y = 1, z = x + y
    if (n >= 1)
        cout << 1 << " ";
    if (n >= 2)
        cout << 1 << " ";

    int a1 = 1, a2 = 1, a3;
    for (int i = 3; i <= n; i++)
    {
        a3 = a2 + a1;
        cout << a3 << " ";
        a1 = a2;
        a2 = a3;
    }
    cout << endl;
}
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    fbnc(n);
    FBNC(n);
    return 0;
}
