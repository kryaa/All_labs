#include "lab6.h"
namespace lab6
{


    template <typename T>
    NumberArray<T>::NumberArray(int size) : size(size)
    {
        array = new T[size];

        std::cout << "Введите " << size << " элементов типа " << typeid(T).name() << ":\n";
        for (int i = 0; i < size; ++i) {
            while (true) {
                try {
                    if (!(std::cin >> array[i])) {
                        // Очистить поток и выбросить исключение, если тип некорректен
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("Некорректный ввод! Ожидается значение соответствующего типа.");
                    }
                    break; // Ввод успешен, выйти из цикла
                }
                catch (const std::invalid_argument& e) {
                    std::cerr << e.what() << " Значение было округлено до целого.\n";
                }
            }
        }
    }

    template <typename T>
    NumberArray<T>::NumberArray(int size, int type) : size(size)
    {
        array = new T[size];

        if (type == 1)
        {
            for (int i = 0; i < size; ++i)
                array[i] = rand() % 100;
        }

        else if (type == 2)
        {
            for (int i = 0; i < size; ++i)
            {
                array[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;
            }
        }
    }


    template <typename T>
    NumberArray<T>::~NumberArray()
    {
        delete[] array;
    }

    template <typename T>
    void NumberArray<T>::findMinNeighb()
    {
        int count = 0;

        cout << "Числа меньше своих соседей: ";
        for (int i = 0; i < size; ++i)
        {
            if (i == 0 && array[i] < array[i + 1] || i == size - 1 && array[i] < array[i - 1]
                || (i > 0 || i < size - 1) && array[i] < array[i - 1] && array[i] < array[i + 1])
            {
                cout << array[i] << " ";
                count++;
            }
        }
        cout << endl;
        cout << "Количество чисел меньше своих соседей: " << count << endl;
    }

    template <typename T>
    void NumberArray<T>::findMaxNeighb()
    {
        int count = 0;

        cout << "Числа больше своих соседей: ";
        for (int i = 0; i < size; ++i)
        {
            if (i == 0 && array[i] > array[i + 1] || i == size - 1 && array[i] > array[i - 1]
                || (i > 0 || i < size - 1) && array[i] > array[i - 1] && array[i] > array[i + 1])
            {
                cout << array[i] << " ";
                count++;
            }
        }
        cout << endl;
        cout << "Количество чисел больше своих соседей: " << count << endl;
    }


    template class NumberArray<int>;
    template class NumberArray<float>;

}