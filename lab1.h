#pragma once
#include <iostream> 
#include <iomanip> #include <sstream> 
using namespace std;
namespace lab1 {
	void runDemo();
    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    class DATE {
    public:
        DATE() : dd(1), mm(jan), yy(1)
        {
            cout << "Вызван конструктор \n" << this << endl;
            day_of_week = (int*)malloc(sizeof(int));
        } /*12 Инициализация датой 01.01.0001*/
        DATE(const DATE& date) : dd(date.dd), mm(date.mm), yy(date.yy) { cout << "Вызван конструктор копирования\n" << this; } // конструктор копирования
        DATE(unsigned dd, month mm, unsigned yy); /*1 Инициализация в формате ДД.ММ.ГГ*/
        void Print(char smb); /*3 Вывести дату по формату ДД*ММ*ГГ, где * - char smb*/
        unsigned Valid(unsigned dd, month mm, unsigned yy); /*10 Проверка значений ДД.ММ.ГГ*/
        inline DATE Add(const DATE& date);
        void SetDayOfWeek(int num) { day_of_week[0] = num; }
        ~DATE() { cout << "Вызван деструктор\n"; free(day_of_week); }
    private:
        unsigned dd;     month mm;     unsigned yy;
        int* day_of_week;
        //проверка високосного года 
        bool IsYear(unsigned y);
    };


    inline DATE DATE::Add(const DATE& date)
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

        return DATE(new_dd, static_cast<month>(new_mm), new_yy);
    }


}

