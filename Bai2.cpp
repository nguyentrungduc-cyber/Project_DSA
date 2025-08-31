#include <iostream>
#include <iomanip>
#include <cmath> // fabs(): -1.0002 -> 1.0002, floor(): 1.6 -> 1.0
using namespace std;

void khoiTaoMang(float *&Array, int &soLuong)
{
    soLuong = 10;
    Array = new float[soLuong];
    *(Array + 0) = 0.8;
    *(Array + 1) = 5.6;
    *(Array + 2) = 9.1;
    *(Array + 3) = 7.3;
    *(Array + 4) = 10;
    *(Array + 5) = 5.9;
    *(Array + 6) = 7.2;
    *(Array + 7) = 9.3;
    *(Array + 8) = 8.0;
    *(Array + 9) = 8.7;
}

void khoiTaoMang1(float *&Array, int &soLuong) // "&" sau "*"
{
    cin >> soLuong;
    Array = new float[soLuong];
    for (int i = 0; i < soLuong; i++)
    {
        cin >> *(Array + i);
    }
}

void khoiTaoMang2(float *&Array, int &soLuong) // "&"
{
    soLuong = 10;
    Array = new float[soLuong]{0.8, 5.6, 9.1, 7.3, 10, 5.9, 7.2, 9.3, 8.0, 8.7};
}

void xuatMang(float *Array, int soluong)
{
    cout << fixed << setprecision(1);
    for (int i = 0; i < soluong; i++)
    {
        cout << *(Array + i) << " ";
    }
    cout << endl;
}

bool kiemTraMangDuong(float *Array, int soLuong)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (*(Array + i) <= 0) //"<="
            return false;
    }
    return true;
}

bool kiemTraDoiXung(float *Array, int soLuong)
{
    for (int i = 0; i < (soLuong / 2); i++)
    {
        for (int j = (soLuong - 1); j >= (soLuong / 2); j--)
        {
            if ((*(Array + i)) != (*(Array + j)))
                return false;
        }
    }
    return true;
}

bool kiemTraDoiXung1(float *Array, int soLuong)
{
    for (int i = 0; i < soLuong / 2; i++)
    {
        if (fabs(*(Array + i) - *(Array + (soLuong - i - 1))) > 0.001)
            return false;
        // Do float nen co phan thap phan kha nho, gan bang 0 nen khong the "==", nen dung fabs de chuyen ve duong
        // de so sanh voi "0.001"
    }
    return true;
}

// Kiem tra so nguyen to hoac so chinh phuong <- so chinh phuong <- so nguyen to <- so nguyen
bool kiemTraNguyen(float x)
{
    return floor(x) == x;
}

bool kiemTraNguyenTo(int x) // dung "int"
{
    if (x < 2)
        return false;
    for (int i = 2; i <= sqrt(x); i++) // "<="
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

bool kiemTraChinhPhuong(int x) // Sau khi sqrt roi lay kq * kq = x -> true
{
    int ketQua = sqrt(x);
    return ketQua * ketQua == x;
}

bool KiemTraNguyenTo_ChinhPhuong(float *Array, int soLuong)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (kiemTraNguyen(*(Array + i)))
        {
            int giaTriNguyen = (int)(*(Array + i));
            if ((kiemTraChinhPhuong(giaTriNguyen)) || (kiemTraNguyenTo(giaTriNguyen)))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    float *Array = nullptr;
    int n;
    khoiTaoMang(Array, n);
    // khoiTaoMang2(Array, n);
    // khoiTaoMang1(Array, n);
    // xuatMang(Array, n);
    // cout << kiemTraMangDuong(Array, n);
    // cout << kiemTraDoiXung(Array, n);
    // cout << kiemTraDoiXung1(Array, n);
    cout << KiemTraNguyenTo_ChinhPhuong(Array, n);

    delete[] Array;
}
