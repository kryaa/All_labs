#include "lab1.h"
namespace lab1 
{

	void runDemo() 
	{
        setlocale(LC_ALL, "Russian");     string str;
        //unsigned day, year, monthInput;     char t; // дл€ . 

        //cout << "Date 1:\n";
        //cout << "¬ведите дату в формате дд.мм.гггг: ";     
        //cin >> str;    
        //stringstream ss(str);
        //ss >> day >> t >> monthInput >> t >> year;
        //DATE date1(day, static_cast<month>(monthInput), year);     
        ////DATE date1(29, feb, 2024); // високосный год     
        //cout << "¬ведите разделитель: ";     
        //cin >> t;     
        //date1.Print(t); 

        ////еще некоторые примеры      
        //cout << "Date 2:\n"; 
        //DATE date2(3, apr, 2023); // корректна€ дата 
        //date2.Print('-');

        //cout << "Date 3:\n";
        //DATE date3(31, feb, 2021); // некорректна€ дата     
        //date3.Print('.'); 

        //cout << "Date 4:\n";
        //DATE date4; // дата по умолчанию     
        //date4.Print('/'); 

        //cout << "Date 5:\n";
        //DATE date5(date2); // копирование    
        //date5.Print('.');

        //cout << "Date 6:\n";
        //DATE date6; // копирование   
        //date6 = date2.Add(date1);
        //date6.Print('.');

        DATE* date = (DATE*)malloc(sizeof(DATE));
        new (date) DATE();
        date->SetDayOfWeek(7);
        date->Print('.');
        date->~DATE();
        free(date);
	}
}
