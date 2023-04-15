#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    float sum = sqrt(2);
    do
    {
        cin >> n;
    } while (n < 1);

    for (int i = 1; i < n; i++)
    {
        sum = sqrt(2 + sum);
    }
    cout << "S(" << n << ") = " << fixed << setprecision(2) << sum << endl;
    printf("S(%d) = %-10.2f", n, sum);
    return 0;
}
