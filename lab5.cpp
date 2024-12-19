#include "lab5.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 
using namespace std;
namespace lab5
{

    DATE::DATE(unsigned dd, unsigned mm, unsigned yy) /*1 Инициализация в формате ДД.ММ.ГГ*/
    {
        //cout << "Вызван конструктор \n" ;
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
            << setw(4) << setfill('0') << yy << endl;
    }

    void DATE::Print() /*3 Вывести дату по формату ДД*ММ*ГГ, где * - char smb*/
    {
        cout << "Ваша дата: " << setw(2) << setfill('0') << dd << "." << setw(2) << setfill('0') << mm << "."
            << setw(4) << setfill('0') << yy << endl;
    }

    unsigned DATE::Valid(unsigned dd, unsigned mm, unsigned yy) /*10 Проверка значений ДД.ММ.ГГ*/
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

    DATE DATE::operator+ (DATE date)
    {
        unsigned new_dd = this->dd + date.dd;
        unsigned new_mm = this->mm + date.mm;
        unsigned new_yy = this->yy + date.yy;

        unsigned months[] = { 0, 31, 28 + (IsYear(yy) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (new_dd > months[new_mm])
        {
            new_dd -= months[new_mm];
            new_mm++;
        }
        if (new_mm > 12)
        {
            new_mm -= 12;
            new_yy++;
        }

        return DATE(new_dd, new_mm, new_yy);
    }


    bool DATE::operator== (DATE date)
    {
        if (this->dd == date.dd && this->mm == date.mm && this->yy == date.yy)
            return 1;
        else return 0;
    }

    void  DATE::operator()(unsigned day, unsigned month, unsigned year)
    {
        if (Valid(day, month, year))
        {
            dd = day;
            mm = month;
            yy = year;
        }
        else
        {
            cout << "Некорректная дата";
        }
    }

    DATE& DATE::operator=(const DATE& date)
    {
        if (this != &date)
        {
            dd = date.dd;
            mm = date.mm;
            yy = date.yy;
        }
        return *this;
    }

    DATE& DATE::operator=(DATE&& date)
    {
        if (this != &date)
        {
            dd = date.dd;
            mm = date.mm;
            yy = date.yy;
            date.dd = 1;
            date.mm = 1;
            date.yy = 1;
        }
        return *this;
    }

    istream& operator>>(istream& is, DATE& date)
    {
        char delimiter;
        is >> date.dd >> delimiter >> date.mm >> delimiter >> date.yy;
        return is;
    }

    ostream& operator<<(ostream& os, DATE& date)
    {
        os << setw(2) << setfill('0') << date.dd << '.'
            << setw(2) << setfill('0') << date.mm << '.'
            << date.yy;
        return os;
    }
}