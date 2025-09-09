#include <iostream>

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

int main()
{
    int array[] = {1, 2, 3, 4, 5};
    int n = 5;
    std::cout << "Tim 5(1): " << interpolationSearch(array, n, 5);
    return 0;
}
