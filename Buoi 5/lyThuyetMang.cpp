// Đặt bài toán: 2 số nguyên
/*
    int a, b;
    nếu mà bài yêu 100 số => đặt như nào??
    => Dùng mảng/ dãy các số có cùng kiểu dữ để lưu trữ

    Cấu trúc:
    <kiểu dữ liệu> <tên mảng>[<số lượng phần tử - n>] => bộ nhớ cho phép truy cập n biến
    <kiểu dữ liệu> <tên mảng>[] = {1, 2, 3, 4} => mảng 4 phần tử, và các giá trị tương ứng lần lượt
    <kiểu dữ liệu> <tên mảng>[10] = {1, 2, 3, 4} => mảng có 10 phần tử, 4 phần tử đầu có giá trị tương ứng,
    các giá trị còn lại bằng 0

    // chỉ số bắt đầu bằng 0 -> n - 1
    // arr[1];

    // 3 cách
    // a[100] - tương ứng ở hàm main mình có 100 pt a[100]
    // a[] - không giới hạn của main
    // *a - giống cách 2

*/
#include <iostream>
#define n1 5
using namespace std;

void Nhap(int a[100], int &n)
{
    cout << "Nhap sl: ";
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
void Xuat(int d[100], int n)
{
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;
}
int main()
{
    // int a[2];
    // a[0] = a[1] = 1;
    // cout << a[0] << " " << a[1] << endl;
    // int b[] = {-1, 2};
    // cout << b[0] << " " << b[1] << endl;
    // int c[2] = {5};
    // cout << c[0] << " " << c[1] << endl;
    // cout << 2 * sizeof(int) << endl;
    // cout << sizeof(b) / sizeof(int) << endl;
    // int n = 5;
    // // Lỗi
    // // int d[]; - không khai báo sl pt
    // // int a[n] - không tường minh
    // // 100, 1000, 10000

    int d[100], n;
    Nhap(d, n);
    Xuat(d, n);
    return 0;
}

/*
BT: nhập, xuất, tìm kiếm giá trị x - đệ quy
    - Mảng tăng hay k - đệ quy
    - nối mảng b vào a
    - Tìm max, min - đệ quy
    - Tìm snt
    - FBNC - đệ quy
    - Tìm thừa số nt: 40 = 2^3 x 5
    132, 143, 148, 151 - đệ quy
    156
*/