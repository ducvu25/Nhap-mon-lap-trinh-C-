#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    long long a1 = 0, a2 = 0, a3 = 1, b;
    cin >> n;
    if (n == 1)
    {
        cout << a1;
        return 0;
    }
    if (n == 2)
    {
        cout << a1 << " " << a2;
        return 0;
    }
    cout << a1 << " " << a2 << " " << a3 << " ";
    for (int i = 4; i <= n; i++)
    {
        b = a1 + a2 + a3;
        cout << b << " ";
        a1 = a2;
        a2 = a3;
        a3 = b;
    }
}