// Đệ quy
#include <iostream>

using namespace std;

// Tính giai thừa
/*
n! = n*(n-1)! = n*(n-1)*(n-2)! = n*...*0!
f(n) = 1 khi n = 0
    = n*f(n-1) khi n > 0
*/

// Loại 1
long GiaiThua(int n)
{
    if (n == 0)
        return 1;
    return n * GiaiThua(n - 1);
}
// Loại 2: đệ quy đuôi
void GiaiThua(int n, int &kq)
{
    if (n > 0)
    {
        kq *= n;
        GiaiThua(n - 1, kq);
    }
}
int gt = 1;
// Loại 3: đệ quy, lưu giá trị sau mỗi bước vào 1 biến ngoài
void GiaiThua2(int n)
{
    if (n > 0)
    {
        gt *= n;
        GiaiThua2(n - 1);
    }
}
// fbnc
/*
f(n) = 1 khi n <= 2
    = f(n-1) + f(n-2) khi n > 2
*/
// void fib(int n, int &ans)
// {
// 	if(n>2){
// 		ans = fib(n-1,ans) + fib(n-2,ans);
// 	}
// }
int fbnc(int n)
{
    if (n <= 2)
        return 1;
    return fbnc(n - 1) + fbnc(n - 2);
}
// S = 1 + 2 + ... + n;
int S(int n, int i)
{
    if (i > n)
        return 0;
    return i + S(n, i + 1);
}
int S(int n)
{
    if (n > 0)
        return n + S(n - 1);
    return 0;
}
// Tìm ước của a, b
int UCLN1(int a, int b)
{
    while (b != 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int UCLN2(int a, int b)
{
    if (b == 0)
        return a;
    return UCLN2(b, a % b);
}

int main()
{
    // int kq = 1;
    // cout << GiaiThua(5) << endl;
    // GiaiThua(5, kq);
    // cout << kq << endl;
    int a, b;
    cin >> a >> b;
    cout << UCLN1(a, b) << " " << UCLN2(a, b);
    return 0;
}