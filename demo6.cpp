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
            cout << "\n�� ������ ��������� ����������? (y/n) ";
            cin >> q;
            if (q == 'n') break;

            int size;
            cout << "������ int(1) ��� float(2)? ";
            cin >> t;
            cout << "�� ������ ������� � ����������? (y/n)";
            cin >> q;
            if (q == 'n')
            {
                cout << "������� ������ �������: ";
                cin >> size;
                if (t == 1)
                {
                    NumberArray<int> numArray(size, t);
                    cout << "��������������� ������ (int): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }

                else
                {
                    NumberArray<float> numArray(size, t);
                    cout << "��������������� ������ (float): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }

            }
            else
            {
                cout << "������� ������ �������: ";
                cin >> size;
                cout << "������� ������: ";
                if (t == 1)
                {
                    NumberArray<int> numArray(size);
                    cout << "��� ������ (int): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }

                else
                {
                    NumberArray<float> numArray(size);
                    cout << "��� ������ (float): " << numArray << endl;
                    numArray.findMinNeighb();
                    numArray.findMaxNeighb();
                    cout << endl;
                }
            }


        }
	}
}