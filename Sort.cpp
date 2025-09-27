#include <iostream>
#include <algorithm>

void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++) // duyệt từ 1 đến n
    {
        int item = a[i];             // lưu tạm, tí nữa tìm được vị trí rồi gán
        int j;                       // biến cục bộ để hồi dùng làm vị trí đúng đẻ gán
        for (j = i - 1; i >= 0; j--) // kiểm tra trước i có chỗ để gán không
        {
            if (a[j] < item) // trước i đều theo đúng thự tự thì
                break;       // bỏ qua
            a[j + 1] = a[j]; // cứ dịch sang phải
        }
        a[j + 1] = item; // vì j kết thúc ở vị trí bé hơn nên i được gán ở trước
    }

    void selectionSort(int a[], int n)
    {
        // int min;                    // giả sử vị trí ban đầu nhỏ nhất
        for (int i = 0; i < n - 1; i++) // bắt đầu kiểm tra từ i = 0 đến n - 1 do j đã chạy đến n
        {
            // min = i;
            int min = i;
            for (int j = i + 1; j < n; j++) // kiểm tra những số sau i có nhỏ hơn không
            {
                if (a[j] < a[min])
                {
                    min = j;
                }
            }
            if (min != i) // nếu các số sau i đều lớn hơn thì không cần hoán vị
            {
                std::swap(a[i], a[min]);
            }
        }
    }

    void output(int array[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << array[i] << " ";
        }
    }

    int main()
    {
        int array[] = {3, 6, 8, 4, 10};
        int n = 5;
        // insertionSort(array, n);
        selectionSort(array, n);
        output(array, n);
        return 0;
    }