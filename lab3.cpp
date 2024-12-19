#include "lab3.h"
namespace lab3
{
    Array::Array(int size) : n(size)
    {
        array = new int[2 * n];
        for (int i = 0; i < 2 * n; ++i)
            array[i] = rand() % 100;
    }

    void Array::AddNum(int n, int index)
    {
        array[index] = n;
    }
    int Array::MinSum()
    {
        int mins = numeric_limits<int>::max();;

        for (int i = 0; i < n; ++i)
        {
            int sum = array[i] + array[n + i];
            if (sum < mins)
                mins = sum;

        }

        return mins;
    }

    int Array::MaxSumOfAll()
    {
        int maxsum = numeric_limits<int>::min(), sum;
        for (int i = 0; i < 2 * n; i++)
        {
            sum = 0;
            for (int j = 0; j <= i; j++)
                sum += array[j];
            if (sum > maxsum)
                maxsum = sum;
        }
        return maxsum;
    }

    void Array::Print()
    {
        cout << "\n—генерированный массив:\n ";
        for (int i = 0; i < 2 * n; ++i)
            cout << array[i] << " ";
    }
}