#include "DATE.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 
using namespace std;


DATE::DATE(unsigned dd, unsigned mm, unsigned yy) /*1 ������������� � ������� ��.��.��*/
{
    //cout << "������ ����������� \n" ;
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

void DATE::Print(char smb) /*3 ������� ���� �� ������� ��*��*��, ��� * - char smb*/
{
    cout << setw(2) << setfill('0') << dd << smb << setw(2) << setfill('0') << mm << smb
        << setw(4) << setfill('0') << yy << endl;
}

unsigned DATE::Valid(unsigned dd, unsigned mm, unsigned yy) /*10 �������� �������� ��.��.��*/
{
    if (yy < 1 || mm < 1 || mm > 12) return 0;

    unsigned months[] = { 0, 31, 28 + (IsYear(yy) ? 1 : 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (dd <= months[mm])
        return 1;
    else {
        cout << "!!! ������������� ������������ ����. ���������� ���� �� ��������� 01.01.0001 !!!" << endl;
        return 0;
    }
}

bool DATE::IsYear(unsigned y) { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
