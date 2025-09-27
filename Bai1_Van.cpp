// Nhập số cho đến khi xuất hiện -1, lưu ý -1 không xuất hiện trong output
// Cho sẵn input/ output -> code sao cho y chang
// output 1: hiện index xuất hiện đầu tiên
// output 2: hiện index tất cả
// lưu ý: NotFound chỉ xuất hiện một lần

#include <iostream>
#include <vector>
#include <algorithm>

void Input(std::vector<int> &v)
{
    int giaTri;
    do
    {
        std::cin >> giaTri;
        if (giaTri != -1)
            v.push_back(giaTri);
    } while (giaTri != -1);
}

void Output(std::vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

bool kiemTra(std::vector<int> v, int giaTri)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == giaTri)
            return true;
    }
    return false;
}

void Find01(std::vector<int> v, int giaTri)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == giaTri)
        {
            std::cout << i << " ";
        }
    }
    if (kiemTra(v, giaTri) == false)
    {
        std::cout << "NotFound";
    }
}

void Find02(std::vector<int> v, int giaTri)
{
    std::cout << std::endl;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == giaTri)
        {
            std::cout << i << " ";
            break;
        }
    }
    if (kiemTra(v, giaTri) == false)
    {
        std::cout << "NotFound";
    }
}
int main()
{
    std::vector<int> A;
    Input(A);
    Output(A);
    int k;
    std::cin >> k;
    Find01(A, k);
    Find02(A, k);
    return 0;
}