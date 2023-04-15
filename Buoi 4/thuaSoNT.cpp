#include <iostream>

using namespace std;

void PhanTich(long n)
{
    long i = 2;
    int d = 0;
    bool check = true;
    while (n != 1)
    {
        if (n % i == 0)
        {
            if (check)
            {
                d++;
                check = false;
            }
            n /= i;
        }
        else
        {
            i++;
            check = true;
        }
        // cout << i << endl;
    }
    cout << d;
}
int main()
{
    long n;
    cin >> n;
    PhanTich(n);
    return 0;
}