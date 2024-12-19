#pragma once
#include "DATE.h"
#include <iostream> 
#include <iomanip> 
#include <sstream> 
using namespace std;
namespace lab4 {
	void runDemo();
    class ClocksDate : public DATE
    {
    public:
        ClocksDate() : sec(0), min(0), hours(0), DATE()
        {
            // cout << "Вызван конструктор ClocksDate\n" ;
        } /*12 Инициализация */
        ClocksDate(unsigned sec, unsigned min, unsigned hours, unsigned dd, unsigned mm, unsigned yy); /*1 Инициализация */
        ClocksDate(unsigned sec, unsigned min, unsigned hours, DATE date); /*1 Инициализация */
        ClocksDate(ClocksDate* date) : sec(date->sec), min(date->min), hours(date->hours) { } // конструктор копирования
        void Print(char smb); //3 
        unsigned Valid(unsigned sec, unsigned min, unsigned hours); /*10 Проверка */
        inline ClocksDate* Add(DATE* time);
        ~ClocksDate() {//cout << "Вызван деструктор ClocksDate\n"; 
        }
    private:
        unsigned sec;     unsigned min;     unsigned hours;

    };

    inline ClocksDate* ClocksDate::Add(DATE* newdate)
    {
        DATE* date = this->Addd(newdate);
        ClocksDate* newtime = dynamic_cast<ClocksDate*>(newdate);
        if (newtime)
        {
            newtime->sec = this->sec + newtime->sec;
            newtime->min = this->min + newtime->min;
            newtime->hours = this->hours + newtime->hours;

            if (newtime->sec > 59)
            {
                newtime->sec -= 60;
                newtime->min++;
            }
            if (newtime->min > 59)
            {
                newtime->min -= 60;
                newtime->hours++;
            }
            if (newtime->hours > 24)
            {
                date->SetDay(date->GetDay() + 1);
                newtime->hours -= 24;
            }
            ClocksDate* times2 = new ClocksDate(newtime->sec, newtime->min, newtime->hours, *(date));
            return times2;
        }
        else {
            cout << "Error null\n";
            return newtime;
        }
    }


}