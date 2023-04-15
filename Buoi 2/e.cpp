#include <iostream>
#include <math.h>

using namespace std;
const float e = 2.718;

int main()
{
    float x;
    cout << "Nhap mu x: ";
    cin >> x;
    float sum = 0, tu = 1;
    long gt = 1;
    int i = 1;
    while (tu / gt > 0.000001)
    {
        sum += tu / gt;
        gt *= i;
        tu *= x;
        i++;
    }
    cout << "Tinh toan: " << sum << endl;
    cout << "Thu vien: " << pow(e, x);
    return 0;
}