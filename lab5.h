#pragma once
#include <iostream> 
#include <iomanip> #include <sstream> 
using namespace std;

namespace lab5 {
	void runDemo();
    enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, dek };

    class DATE
    {
    public:
        DATE() : dd(1), mm(1), yy(1)
        {
            // cout << "������ ����������� \n" << this << endl;
        } /*12 ������������� ����� 01.01.0001*/
        DATE(const DATE& date) : dd(date.dd), mm(date.mm), yy(date.yy) {  } // ����������� �����������
        DATE(unsigned dd, unsigned mm, unsigned yy); /*1 ������������� � ������� ��.��.��*/
        DATE(DATE* date) : dd(date->dd), mm(date->mm), yy(date->yy) {  } // ����������� �����������

        virtual void Print(char smb); /*3 ������� ���� �� ������� ��*��*��, ��� * - char smb*/
        virtual void Print();
        virtual unsigned Valid(unsigned dd, unsigned mm, unsigned yy); /*10 �������� �������� ��.��.��*/
        inline DATE* Addd(DATE* date);

        DATE operator+ (DATE date);
        bool operator== (DATE date);
        void operator()(unsigned day, unsigned month, unsigned year);
        DATE& operator=(const DATE& date);
        DATE& operator=(DATE&& date);
        friend istream& operator>>(istream& is, DATE& date);
        friend ostream& operator<<(ostream& os, DATE& date);

        ~DATE() {// cout << "������ ����������\n";  
        }
        unsigned GetDay() { return dd; };
        void SetDay(unsigned ndd) { dd = ndd; };
    protected:
        unsigned dd;     unsigned mm;     unsigned yy;
        //�������� ����������� ���� 
        bool IsYear(unsigned y);
    };


    inline DATE* DATE::Addd(DATE* date)
    {
        unsigned new_dd = this->dd + date->dd;
        unsigned new_mm = this->mm + date->mm;
        unsigned new_yy = this->yy + date->yy;

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
        DATE* date2 = new DATE(new_dd, new_mm, new_yy);
        return date2;
    }

}