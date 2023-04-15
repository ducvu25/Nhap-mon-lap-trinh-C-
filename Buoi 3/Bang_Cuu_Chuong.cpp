#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            // cout << left << setw(1) << j << " x " << setw(1) << i << " = " << setw(5) << i * j;
            printf("%d x %d = %-5d", j, i, i * j);
        }
        cout << endl;
    }
}