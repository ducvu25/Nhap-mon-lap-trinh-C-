#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 2)
    {
        cout << n << " khong phai so nguyen to.";
        return 0;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << n << " khong phai so nguyen to.";
            return 0;
        }
    }
    cout << n << " la so nguyen to.";
    return 0;
}
