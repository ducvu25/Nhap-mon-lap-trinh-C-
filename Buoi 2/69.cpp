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

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, x, sum = 0, count = 0;
    cin >> n >> x;
    for (int i = 1; i <= 2 * n + 1; i += 2)
    {
        sum = sum + pow(-1, count) * pow(x, i);
        count++;
    }
    cout << sum;
}
