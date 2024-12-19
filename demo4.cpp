#include "lab4.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 

using namespace std;

namespace lab4
{

	void runDemo()
	{
        setlocale(LC_ALL, "Russian");
        //string str;
        //unsigned day, year, monthInput;     char t; // для . 

        //cout << "Date 1:\n";
        //cout << "Введите дату в формате дд.мм.гггг: ";     
        //cin >> str;    
        //stringstream ss(str);
        //ss >> day >> t >> monthInput >> t >> year;
        //DATE date1(day, static_cast<month>(monthInput), year);     
        ////DATE date1(29, feb, 2024); // високосный год     
        //cout << "Введите разделитель: ";     
        //cin >> t;     
        //date1.Print(t); 

        //////еще некоторые примеры      
        cout << "Date 1:\n";
        DATE date1(3, 3, 2023); // корректная дата 
        date1.Print('-');

        //cout << "Date 3:\n";
        //DATE date3(31, feb, 2021); // некорректная дата     
        //date3.Print('.'); 

        cout << "Date 2:\n";
        DATE date2; // дата по умолчанию     
        date2.Print('/');

        //cout << "Date 5:\n";
        //DATE date5(date2); // копирование    
        //date5.Print('.');

        //cout << "Date 6:\n";

        //DATE date6; // копирование   
        //date6 = dynamic_cast<DATE>(date2.Add(date1));
        //date6.Print('.');

        cout << "ПРИМЕРЫ\nВведена дата\n";
        DATE* date = new DATE(3, 3, 2023);
        date->Print('.');
        cout << "Введена дата и время\n";
        ClocksDate* times = new ClocksDate(23, 12, 15, 3, 3, 2023);
        times->Print(':');
        cout << "Введено некорректное время\n";
        ClocksDate* times2 = new ClocksDate(45, 12, 25, 3, 3, 2023);
        times2->Print(':');
        cout << "Введена некорректная дата и время\n";
        ClocksDate* times3 = new ClocksDate(45, 12, 25, 31, 2, 2023);
        times3->Print(':');
        cout << "-----------------------------------------\n";

        ClocksDate times4(12, 15, 10, 4, 4, 2024);
        ClocksDate times5(23, 12, 15, 3, 3, 2023);
        ClocksDate* times6 = times4.Add(&times5);
        times6->Print(':');
        ClocksDate* times7 = times4.Add(&date1);
        ClocksDate times8(12, 15, 10, 4, 4, 2024);
        ClocksDate times9(23, 12, 15, 3, 3, 2023);

        DATE* newtime = dynamic_cast<DATE*>(times8.Add(&times9));
        if (newtime == nullptr) cout << "Error null\n";
        else newtime->Print('.');
        delete date;
        delete times;
        delete times2;
        delete times3;
        delete times6;

        delete times7;
	}
}