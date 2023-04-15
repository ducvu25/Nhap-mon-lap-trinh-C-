#include <iostream>
#include <cmath>
using namespace std;

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
bool Check(int n)
{
    int m = 0, sum = 0, b = n;
    while (n > 0)
    {
        sum += n % 10;
        m = m * 10 + n % 10;
        n /= 10;
    }
    if (m == b && Prime(sum))
        return true;
    return false;
}

int main()
{
    int a, b;
    bool check = false;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
    {
        if (Check(i))
        {
            check = true;
            cout << i << " ";
        }
    }
    if (!check)
        cout << "NONE";
    return 0;
}
