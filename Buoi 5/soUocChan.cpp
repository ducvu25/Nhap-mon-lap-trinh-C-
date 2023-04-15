#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

int UCLN(long n)
{
    int count = 0, i = 1;
    if (n < 2)
        return 0;
    while (i <= sqrt(n))
    {
        if (n % i == 0 && i % 2 == 0)
        {
            count++;
            cout << i << endl;
        }
        i++;
    }
    return count;
}
// số nhỏ: for, while
// số lớn: động đến toán
/*
40 = 2^3*5 = 2, 4, 8, 10, 20, 40: 3 + 3*1
60 = 2^2*3*5 = 2 + 2*1 + 2*1 + 2*1 = 8 => 2 số chẵn, 2 số lẻ: => (2 + 1)* 2 =
=> 2 chẵn: 2 cách
=> 1 chẵn + 1 lẻ => 1
=> 1 chẵn  +2 lẻ => 2 cách
=> 2 chẵn + 1 lẻ =>
   = 2, 4, 6, 12, 10, 20, 30, 60
90 = 2*3^2*5 = 1 + 1*2 + 1*1 + 1*2 = 6 => 1 chẵn, 3 lẻ
   = 2, 6, 18, 10, 30, 90
2^2 * 3^2 * 5: 2 chẵn 3 lẻ

*/
int main()
{
    long a;
    cin >> a;
    cout << UCLN(a);
    return 0;
}