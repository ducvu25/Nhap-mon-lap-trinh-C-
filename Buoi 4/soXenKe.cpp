#include <iostream>
#include <math.h>
using namespace std;

bool Check(int n)
{
    // delta = 1
    // 32 => 2, 3
    int delta = 1, x = n % 10 + 1;
    while (n != 0)
    {
        delta -= abs(n % 10 - x);
        if (delta != 0)
            return false;
        delta = 1;
        x = n % 10;
        n /= 10;
    }
    return true;
    // delta -= abs(n%10 - x)

    // delta sau == 0
    // neu ma khac 0 => 0 phai
}
int main()
{
    int a, b;
    bool check = false;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (Check(i))
        {
            check = true;
            cout << i << " ";
        }
    if (!check)
        cout << "NONE";
    // cout << Check(25);
    return 0;
}