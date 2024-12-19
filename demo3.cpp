#include "lab3.h"
#include <iostream>
#include <ctime>

using namespace std;
namespace lab3
{

	void runDemo()
	{
        srand(time(0));
        setlocale(LC_ALL, "Russian");
        char t;
        while (true)
        {
            cout << "\nВы хотите запустить вычисления? (y/n) ";
            cin >> t;
            if (t == 'n') break;

            int n;
            cout << "Введите количество элементов последовательности (Внимание! программа создаст последовательность в 2 раза брльше): ";
            cin >> n;

            Array* arr = new Array(n);
            int numi;
            for (int i = 0; i < n * 2; i++)
            {
                cin >> numi;
                arr->AddNum(numi, i);
            }

            if (arr->MinSum() == numeric_limits<int>::max())
                cout << "\n!!Последовательность не создана. Минимальное количество элементов не может быть меньше 1!!\n";
            else
            {
                arr->Print();
                cout << "\nМинимальная сумма: " << arr->MinSum()
                    << "\nМаксимальная сумма: " << arr->MaxSumOfAll() << endl;
            }
        }
	}
}