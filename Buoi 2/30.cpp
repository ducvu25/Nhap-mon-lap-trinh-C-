#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum = sum + i;
        }
    }
    if (n == sum)
    {
        cout << n << " la so hoan hao.";
    }
    else
    {
        cout << n << " ko phai la so hoan hao.";
    }
    return 0;
}
