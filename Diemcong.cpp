#include <bits/stdc++.h>
using namespace std;

int X; // biến toàn cục chứa giá trị X

void Input(vector<int> &A)
{
    int val;
    while (cin >> val)
    {
        if (val == -1)
            break;
        A.push_back(val);
    }
    cin >> X;
}

void Find(vector<int> &A)
{
    bool khong_giam = true, khong_tang = true;
    for (int i = 0; i + 1 < A.size(); i++)
    {
        if (A[i] > A[i + 1])
            khong_giam = false;
        if (A[i] < A[i + 1])
            khong_tang = false;
    }

    if (!khong_giam && !khong_tang)
    {
        cout << "Invalid";
        return;
    }
    int l = 0, r = A.size() - 1; 
    while (true) // giúp hiện trường hợp vi phạm
    {
        cout << "[" << l << "-" << r << "]";
        if (l > r)
        {
            cout << "\nNotFound";
            return;
        }

        int m = (l + r) / 2;
        if (A[m] == X) 
        {
            cout << "\n"
                 << m;
            return;
        }

        if (khong_giam)
        { // mảng tăng
            if (A[m] < X)
                l = m + 1;
            else
                r = m - 1;
        }
        else
        { // mảng giảm
            if (A[m] < X)
                r = m - 1;
            else
                l = m + 1;
        }
        cout << " "; 
    }
    cout << "\nNotFound";
}

int main()
{
    vector<int> A;
    Input(A);
    Find(A);
    return 0;
}
