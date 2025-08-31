#include <iostream>
#include <iomanip>

using namespace std;

struct NhanVien
{
    string maNV, hoTenNV;
    double luongCB, luongThang;
    int ngayLamViec;

    void NhapNV();
    void XuatNV();
    double capNhapLuongThang();
};

struct DSNhanVien
{
    NhanVien *DanhSach;
    int soLuongNV;

    void NhapDS(); // khong can tham so dau vao
    void XuatDS();
    double tongLuongNV();
    ~DSNhanVien();
};

void NhanVien::NhapNV()
{
    cout << "Nhap manv: ";
    getline(cin, maNV);
    cout << "Nhap ho ten nv: ";
    getline(cin, hoTenNV);
    cout << "Nhap luong cb, ngay lv: ";
    cin >> luongCB >> ngayLamViec;
    cin.ignore();
}

void NhanVien::XuatNV()
{
    cout << maNV << endl;
    cout << hoTenNV << endl;
    cout << luongCB << " " << endl;
    cout << ngayLamViec << endl;
    cout << fixed << setprecision(0) << capNhapLuongThang() << endl;
}

double NhanVien::capNhapLuongThang()
{
    luongThang = luongCB + ngayLamViec * 180000;
    if (luongCB > 8000000)
        luongThang *= 1.05;
    if (luongCB < 5000000)
        luongThang *= 1.1;
    return luongThang;
}

void DSNhanVien::NhapDS()
{
    DanhSach = nullptr;
    cin >> soLuongNV;
    cin.ignore();
    DanhSach = new NhanVien[soLuongNV];
    for (int i = 0; i < soLuongNV; i++)
    {
        (DanhSach + i)->NhapNV(); // bo "*"
    }
}

void DSNhanVien::XuatDS()
{
    for (int i = 0; i < soLuongNV; i++)
    {
        (DanhSach + i)->XuatNV();
    }
    cout << "Tong luong nv: " << tongLuongNV() << endl;
}

double DSNhanVien::tongLuongNV()
{
    double ketQua = 0.0;
    for (int i = 0; i < soLuongNV; i++)
    {
        if ((DanhSach + i)->luongCB < 5000000)
        {
            ketQua += (DanhSach + i)->capNhapLuongThang();
        }
    }
    return ketQua;
}

DSNhanVien::~DSNhanVien()
{
    delete[] DanhSach;
}

int main()
{
    DSNhanVien Schannel;
    Schannel.NhapDS();
    Schannel.XuatDS();

    return 0;
}