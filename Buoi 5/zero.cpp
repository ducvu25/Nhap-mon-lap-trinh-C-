#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

bool check = true;
int s5 = 0, s2 = 0;

void Update(int n)
{
    if (!check)
        return;

    if (n == 0)
    {
        s5 = s2 = 0;
        check = false;
    }
    while (n % 2 == 0)
    {
        s2++;
        n /= 2;
    }
    while (n % 5 == 0)
    {
        s5++;
        n /= 5;
    }
}

int main()
{
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        Update(x);
        // if (!check)
        //     break;
    }
    if (s5 > s2)
        cout << s2;
    else
        cout << s5;
    return 0;
}