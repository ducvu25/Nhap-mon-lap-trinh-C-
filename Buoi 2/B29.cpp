#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = n; i > 0; i--)
    {
        if (n % i == 0 && i % 2 == 1)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}
