#include "lab4.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 
using namespace std;
namespace lab4
{

    ClocksDate::ClocksDate(unsigned sec, unsigned min, unsigned hours, unsigned dd, unsigned mm, unsigned yy) : DATE(dd, mm, yy)/*1 Инициализация в формате ДД.ММ.ГГ*/
    {
        //cout << "Вызван конструктор ClocksDate\n";
        if (Valid(sec, min, hours))
        {
            this->sec = sec;
            this->min = min;
            this->hours = hours;
        }
        else
        {
            this->sec = 0;
            this->min = 0;
            this->hours = 0;
        }
    }

    ClocksDate::ClocksDate(unsigned sec, unsigned min, unsigned hours, DATE date) : DATE(date)/*1 Инициализация в формате ДД.ММ.ГГ*/
    {
        //cout << "Вызван конструктор ClocksDate\n";
        if (Valid(sec, min, hours))
        {
            this->sec = sec;
            this->min = min;
            this->hours = hours;
        }
        else
        {
            this->sec = 0;
            this->min = 0;
            this->hours = 0;
        }
    }


    void ClocksDate::Print(char smb) /*3 Вывести дату */
    {
        DATE::Print('.');
        cout << "Time: " << setw(2) << setfill('0') << hours << smb << setw(2) << setfill('0') << min << smb
            << setw(2) << setfill('0') << sec << endl;
    }

    unsigned ClocksDate::Valid(unsigned sec, unsigned min, unsigned hours) /*10 Проверка значений ДД.ММ.ГГ*/
    {
        if (sec >= 0 && sec < 60 && min >= 0 && min < 60 && hours >= 0 && hours < 24) return 1;
        else {
            cout << "!!! Использованно некорректное время. Поставлено время по умолчанию 00:00:00 !!!" << endl;
            return 0;
        }
    }

}