#include "lab5.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 

using namespace std;
namespace lab5
{

	void runDemo()
	{
        setlocale(LC_ALL, "Russian");
        /*string str;
        unsigned day, year, monthInput;     char t;*/ // ��� . 

        //cout << "Date 1:\n";
        //cout << "������� ���� � ������� ��.��.����: ";     
        //cin >> str;    
        //stringstream ss(str);
        //ss >> day >> t >> monthInput >> t >> year;
        //DATE date1(day, static_cast<month>(monthInput), year);     
        ////DATE date1(29, feb, 2024); // ���������� ���     
        //cout << "������� �����������: ";     
        //cin >> t;     
        //date1.Print(t); 
        cout << "������� ������ ���������\n";
        //////��� ��������� �������      
        cout << "Date 1:\n";
        DATE date1(3, 3, 2023); // ���������� ���� 
        date1.Print('-');

        //cout << "Date 3:\n";
        //DATE date3(31, feb, 2021); // ������������ ����     
        //date3.Print('.'); 

        cout << "Date 2:\n";
        DATE date2; // ���� �� ���������     
        date2.Print();

        cout << "Date 3:\n";
        DATE date3; // ���� �� ���������     
        date3.Print();

        //cout << "Date 5:\n";
        //DATE date5(date2); // �����������    
        //date5.Print('.');

        //cout << "Date 6:\n";

        //DATE date6; // �����������   
        //date6 = dynamic_cast<DATE>(date2.Add(date1));
        //date6.Print('.');


        DATE date4 = date1 + date2;
        date4.Print();
        if (date1 == date2) cout << "date1 = date2\n";
        else cout << "date1 != date2\n";
        if (date3 == date2) cout << "date3 = date2\n\n";
        else cout << "date3 != date2\n\n";

        date2 = date1;
        cout << "������������� ���� Date2: " << date2 << endl;
        date2(1, 2, 3);
        cout << "���������� ����� Date2: " << date2 << endl;


        date3 = move(date1);
        cout << "������������ ����: " << date3 << endl;
        cout << "������������ ���� ����� �����������: " << date1 << endl;


        char q;
        while (true)
        {
            cout << "\n�� ������ ��������� ����������? (y/n) ";
            cin >> q;
            if (q == 'n') break;

            cout << "Date 1:\n";
            cout << "������� ���� � ������� ��.��.����: ";
            /*cin >> str;
            stringstream ss(str);
            ss >> day >> t >> monthInput >> t >> year;*/
            DATE mdate1;
            cin >> mdate1;
            cout << "Date 2:\n";
            cout << "������� ���� � ������� ��.��.����: ";
            /*cin >> str;
            stringstream ss1(str);
            ss1 >> day >> t >> monthInput >> t >> year;*/
            DATE mdate2;
            cin >> mdate2;

            DATE mdate3 = mdate1 + mdate2;
            //mdate3.Print();
            cout << mdate3 << endl;
            if (mdate1 == mdate2) cout << "date1 = date2\n";
            else cout << "date1 != date2\n";

        }

	}
}