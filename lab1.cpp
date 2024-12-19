#include "lab1.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 
using namespace std;
namespace lab1 
{

    DATE::DATE(unsigned dd, month mm, unsigned yy) /*1 Инициализация в формате ДД.ММ.ГГ*/
    {
        cout << "Вызван конструктор \n" << this;
        if (Valid(dd, mm, yy))
        {
            this->dd = dd;
            this->mm = mm;
            this->yy = yy;
        }
        else
        {
            this->dd = 1;
            this->mm = jan;
            this->yy = 1;
        }
    }

    void DATE::Print(char smb) /*3 Вывести дату по формату ДД*ММ*ГГ, где * - char smb*/
    {
        cout << setw(2) << setfill('0') << dd << smb << setw(2) << setfill('0') << mm << smb
            << setw(4) << setfill('0') << yy << " день недели - " << *(day_of_week) << endl;
    }

    unsigned DATE::Valid(unsigned dd, month mm, unsigned yy) /*10 Проверка значений ДД.ММ.ГГ*/
    {
        if (yy < 1 || mm < 1 || mm > 12) return 0;

        unsigned months[] = { 0, 31, 28 + (IsYear(yy) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (dd <= months[mm])
            return 1;
        else {
            cout << "!!! Использованна некорректная дата. Поставлена дата по умолчанию 01.01.0001 !!!" << endl;
            return 0;
        }
    }

    bool DATE::IsYear(unsigned y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }

}
