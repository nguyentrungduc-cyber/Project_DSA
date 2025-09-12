#include <iostream>
#include <cstdlib>
#include <ctime>

bool binarySearch(int array[], int n, int value)
{
    int R = 0;
    int L = n - 1;
    while (L <= R)
    {
        int M = (R - L) / 2;
        if (array[M] == value)
            return true;
        if (value > array[M])
            L = M + 1;
        else if (value < array[M])
            R = M - 1;
    }
    return true;
}

bool interpolationSearch(int array[], int n, int value)
{
    int R = 0;
    int L = n - 1;
    while (L <= R)
    {
        int M = L + ((R - L) / (array[R] - array[L])) * (value - array[L]);
        if (array[M] == value)
            return true;
        if (value > array[M])
            L = M + 1;
        else if (value < array[M])
            R = M - 1;
    }
    return true;
}

int soLuong()
{
    // [30; 50]
    return 30 + rand() % (50 - 30 - 1);
}

int giaTri()
{
    // [100; 999]
    return 100 + rand() % (999 - 100 + 1);
}

void taoMang(int *&array, int &n)
{
    n = soLuong();
    array = new int[n];
    srand(time(0));
    do
    {
        array[0] = giaTri();
    } while (array[0] > 130);
    for (int i = 1; i < n; i++)
    {
        do
        {
            array[i] = giaTri();
        } while ((array[i] - array[i - 1]) > 15);
    }
}

void xuatMang(int array[], int n)
{

    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    int *array = nullptr;
    taoMang(array, n);
    xuatMang(array, n);
    delete[] array;
    return 0;
}
