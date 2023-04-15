#include <iostream>

using namespace std;
#define PI 3.14  // không thay đổi giá trị được
float pi = 3.14; // có thể thay đổi giá trị

// nhập vào n, vẽ 2 hình thoi có kích thước 2*n + 1 và 2*(n+1) + 1
// Tính tổng 2 số nguyên a, b
// C1: có kiểu trả về:
void TongHieu(int a, int b, int &c, int &d);
int Tong(int a, int b);
void Tong(int a, int b, int &c);
void Swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
int main()
{ // a, d, e, f
    /*
    Cú pháp:
    <Kiểu trả về> <Tên hàm>(<Danh sách biến đầu vào>){ // P1
        <Kiểu trả về> <tên biến trả về> // P2
        // todo - xử lý // P3
        return <tên biến trả về> // P4
    }

    <Kiểu trả về>:
        - Có kiểu trả về: int, float, char, string, int*,
            float*, HocSinh, .... - làm việc có nhận công
        - Không có: void - làm không nhận công

    <Tên hàm> : tuân thủ quy tắc đặt tên biến
    <Danh sách biến>: Gồm các biến có kiểu dữ liệu đi kèm và cách nhau bởi ','
        VD: int a;         int b, float c;           int a, int b

    Chú ý: nếu kiểu trả về là void thì mình có thể bỏ qua phần 2, phần 4 hoặc ở phần 4 return;
    Chú ý 2:
    Trong danh sách biến:
        + Biến có thể thay đổi giá trị: thêm dấu & đằng trước biến
        + Biến không thể thay đổi giá trị: không thay đổi giá trị sau khi ra khỏi hàm
    */

    // int a, b, c, d;
    // cout << "Nhap a, b: ";
    // cin >> a >> b;
    // // cout << "C1: Tong: " << Tong(a, b) << endl;

    // TongHieu(a, b, c, d);
    // cout << c << " " << d;
    // // cout << PI << endl;
    // //  int c = -1;
    // //  Tong(a, b, c);
    // //  cout << "C2: Tong: " << c << endl;

    int a, b;
    cout << "Nhap a, b: ";
    cin >> a >> b;
    Swap(a, b);
    cout << "Gia tri sau: " << a << " " << b;
    return 0;
}
int Tong(int a, int b)
{
    // cout << PI << endl;
    // cout << pi << endl;
    int c;
    c = a + b;
    return c; // a + b
}
// C2: Không có kiểu trả về
void Tong(int a, int b, int &c)
{
    c = a + b;
}
void TongHieu(int a, int b, int &c, int &d)
{
    c = Tong(a, b);
    d = a - b;
}