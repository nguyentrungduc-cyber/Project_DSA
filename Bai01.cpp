#include <iostream> // cin, cout
#include <ctime>    // time(0) -> srand : random ra khac nhau
#include <cstdlib>  // rand : random, srand : seed
#include <iomanip>  // setprecision
#include <cmath>

using namespace std;

void taoMang(float *&Array, int &soLuong) // can truyen tham so cho Array
{
    // soLuong = [10; 20]
    soLuong = (rand() % (10 + 1)) + 10;
    // [0; 10] + 10 -> [10; 20]

    // Cap phat dong cho Array
    Array = new float[soLuong];

    for (int i = 0; i < soLuong; i++)
    {
        // giaTri = [-268; 339]
        *(Array + i) = (rand() % (2680 + 3390 + 1) - 2680) / 10.0;
        // [0; 6070] - 2680 -> [-2680; 3390] / 10.0 : convert int into float
    }
}
void xuatMang(float *Array, int soLuong) // soLuong khong can tham chieu
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < soLuong; i++)
    {
        cout << *(Array + i) << " ";
    }
    cout << endl;
}
float tongMang(float *Array, int soLuong)
{
    float Tong = 0.0;
    for (int i = 0; i < soLuong; i++)
    {
        Tong += *(Array + i);
    }
    return Tong;
}
float tichMang(float *Array, int soLuong)
{
    float Tich = 1.0;
    for (int i = 0; i < soLuong; i++)
    {
        Tich *= *(Array + i);
    }
    return Tich;
}
int demXuatHien(float *Array, int soLuong, float x)
{
    int dem = 0;
    for (int i = 0; i < soLuong; i++)
    {
        if (abs(*(Array + i) - x) < 0.0001)
            dem++;
    }
    return dem;
}
float phanTuMin(float *Array, int soLuong)
{
    float *Min = Array;
    for (int i = 1; i < soLuong; i++)
    {
        if (*(Array + i) < *Min)
            *Min = *(Array + i);
    }
    return *Min;
}
void daoNguocMang(float *Array, int soLuong)
{
    cout << fixed << setprecision(2);
    for (int i = soLuong - 1; i >= 0; i--) // Bat dau: soLuong - 1
    {
        cout << *(Array + i) << " ";
    }
    cout << endl;
}
void amMang(float *Array, int soLuong)
{
    cout << fixed << setprecision(2);
    for (int i = 0; i < soLuong; i++)
    {
        if (*(Array + i) < 0)
        {
            cout << *(Array + i) << " ";
        }
    }
    cout << endl;
}
void xuatMangNguyen(float *Array, int soLuong)
{
    for (int i = 0; i < soLuong; i++)
    {
        if (static_cast<int>(*(Array + i)) % 2 == 0) // convert float into int
        {
            cout << *(Array + i) << " ";
        }
    }
    cout << endl;
}
int demGiaTriKhoang(float *Array, int soLuong, float x, float y)
{
    int dem = 0;
    for (int i = 0; i < soLuong; i++) // [0; soLuong]
    {
        if ((*(Array + i) >= x) && (*(Array + i) <= y)) dem++; // Kiem tra gia tri trong mang
    }
    return dem;
}
void xuatGiaTriKhoang(float *Array, int soLuong, float x, float y)
{
    for (int i = 0; i < soLuong; i++)
    {
        if ((*(Array + i) >= x) && (*(Array + i) <= y))
        {
            cout << *(Array + i) << " ";
        }
    }
    cout << endl;
}
int main()
{
    srand(time(0));
    float *Array = nullptr;
    int n;
    taoMang(Array, n);
    xuatMang(Array, n);
    // cout << "Tong: " << tongMang(Array, n) << endl;
    // cout << "Tich: " << tichMang(Array, n) << endl;
    // int x;
    // cout << "Nhap so muon dem: ";
    // cin >> x;
    // cout << "So lan xuat hien cua " << x << " : " << demXuatHien(Array, n, x);
    // cout << "Min: " << phanTuMin(Array, n) << endl;
    // daoNguocMang(Array, n);
    // amMang(Array, n);
    //xuatMangNguyen(Array, n);
    float x,y;
    cin >> x >> y;
    // cout << "Trong khoang " << "[" << x << "; " << y << "] co " << demGiaTriKhoang(Array, n, x, y) << " phan tu" << endl;
    xuatGiaTriKhoang(Array, n, x, y);

    delete[] Array;
    return 0;
}