#include <iostream>
#include <vector>

void Input(std::vector<int> &v)
{
    int giaTri; // khởi tạo ngoài để tránh while chưa khái báo
    do
    {
        std::cin >> giaTri;
        if (giaTri != -1) // cần kiểm tra trước khi push
           v.push_back(giaTri);
    } while (giaTri != -1); // lưu ý ";"
}

void Find(const std::vector<int> &v)
{
    if (v.empty()) {
        std::cout << "NotFound";
        return;
    }

    std::vector<int> dem(v.size(), 0); // dùng "()" thay vì "[]"

    // Đếm số lần xuất hiện
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] == v[j])
            {
                dem[i]++;
            }
        }
    }

    // Tìm phần tử xuất hiện nhiều nhất
    int demMax = dem[0];
    int viTri = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (dem[i] > demMax)
        {
            demMax = dem[i];
            viTri = i;
        }
    }

    if (demMax > 1)
    {
        std::cout << "Phan tu xuat hien nhieu nhat: " 
                  << v[viTri] << " (so lan: " << demMax << ")";
    }
    else if (demMax == 1)
        std::cout << "NotFound";
}

int main()
{
    std::vector<int> A;
    Input(A);
    Find(A);

    return 0;
}
