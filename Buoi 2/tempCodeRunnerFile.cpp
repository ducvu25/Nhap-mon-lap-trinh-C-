#include <iostream>
using namespace std;

int main()
{
    int n, dau = 1;
    float x, sum = 0;
    cin >> n >> x;
    float denta = x;
    // sum += denta*dau
    // dau = -dau;
    for (int i = 0; i <= n; i++)
    {
        sum += denta * dau;
        dau = -dau;
        denta *= x * x;
    }
    cout << sum;
    return 0;
}