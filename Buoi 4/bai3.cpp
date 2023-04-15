#include <iostream>

using namespace std;

int S1(int n)
{
    int sum = 0;
    for (int i = n; i >= 1; i--)
    {
        sum += i;
    }
    return sum;
}
int S2(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i * i;
    }
    return sum;
}
double S3(int n)
{
    double sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += 1.0 / i;
    }
    return sum;
}
long S4(int n)
{
    long sum = 1;
    for (int i = 1; i <= n; i++)
    {
        sum *= i;
    }
    return sum;
}
long S5(int n)
{
    long s = 0;
    long m = 1;
    for (int i = 1; i <= n; i++)
    {
        m *= i;
        s += m;
    }
    return s;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << "S1 = " << S1(n) << endl;
    cout << "S2 = " << S2(n) << endl;
    cout << "S3 = " << S3(n) << endl;
    cout << "S4 = " << S4(n) << endl;
    cout << "S5 = " << S5(n) << endl;
    return 0;
}