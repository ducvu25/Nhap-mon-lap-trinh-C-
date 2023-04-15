#include <iostream>
using namespace std;

int main()
{
    int n, sum = 0, i = 0, a;
    do
    {
        cin >> n;
    } while (n < 0);
    // C1
    while (sum + i < n)
    {
        sum += i;
        i++;
    }
    cout << "S(" << i - 1 << ") = " << sum << endl;
    // C2
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + i;
        if (sum > n)
        {
            sum = sum - i;
            a = i;
            break;
        }
    }
    cout << "S(" << a - 1 << ") = " << sum << " < " << n;
    return 0;
}
