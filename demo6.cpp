#include "lab6.h"
#include <iostream>
#include <ctime>

using namespace std;
namespace lab6
{


	void runDemo()
	{
        srand(static_cast<unsigned int>(time(0)));
        setlocale(LC_ALL, "Russian");


        char q; int t;
        while (true)
        {
            cout << "\nВы хотите запустить вычисления? (y/n) ";
            cin >> q;
            if (q == 'n') break;

            int size;
            cout << "Массив int(1) или float(2)? ";
            cin >> t;
            cout << "Вы хотите вводить с клавиатуры? (y/n)";
            cin >> q;
            if (q == 'n')
            {
                cout << "Введите размер массива: ";
                cin >> size;
                if (t == 1)
                {
                    NumberArray<int> numArray(size, t);
                    cout << "Сгенерированный массив (int): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }

                else
                {
                    NumberArray<float> numArray(size, t);
                    cout << "Сгенерированный массив (float): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }

            }
            else
            {
                cout << "Введите размер массива: ";
                cin >> size;
                cout << "Введите массив: ";
                if (t == 1)
                {
                    NumberArray<int> numArray(size);
                    cout << "Ваш массив (int): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }

                else
                {
                    NumberArray<float> numArray(size);
                    cout << "Ваш массив (float): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }
            }


        }
	}
}