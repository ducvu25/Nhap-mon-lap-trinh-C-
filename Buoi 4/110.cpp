#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int i, j, k;
    int num;
    cout << "Nhap so tien: ";
    cin >> num;
    // 1000 =>
    if (num % 1000 != 0)
        num -= num % 1000;

    for (k = 0; k <= num / 5000; ++k)
        for (j = 0; j <= (num - k * 5000) / 2000; ++j)
            if (num - k * 5000 - j * 2000 >= 0)
            {
                cout << left << "So to 1000: " << setw(1) << (num - k * 5000 - j * 2000) / 1000 << setw(10) << " So to 2000: " << setw(1) << j << setw(10) << " So to 5000: " << setw(1) << k << endl;
            }
    return 0;
}
