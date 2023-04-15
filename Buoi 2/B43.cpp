#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    // n = abs(n);
    while (n != 0) // n > 0)
    {
        n = n / 10;
        count++;
    }
    // -123 => -12 => -1 => 0
    cout << count;
    return 0;
}
