#include "Student.h"
using namespace std;

// �����������
Student::Student(string sname, string name, string otch, string group, int age, float averscore)
    : name(name), sname(sname), otch(otch), groupNumber(group), age(age), averscore(averscore) {}

// ����������� ���������� � ��������
void Student::printStudent()
{
    cout << "���: " << sname << " " << name << " " << otch << ", ������: " << groupNumber << ", �������: " << age << ", ��.����: " << averscore << endl;
}