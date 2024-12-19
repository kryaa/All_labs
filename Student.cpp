#include "Student.h"
using namespace std;

// конструктор
Student::Student(string sname, string name, string otch, string group, int age, float averscore)
    : name(name), sname(sname), otch(otch), groupNumber(group), age(age), averscore(averscore) {}

// отображение информации о студенте
void Student::printStudent()
{
    cout << "ФИО: " << sname << " " << name << " " << otch << ", Группа: " << groupNumber << ", Возраст: " << age << ", Ср.балл: " << averscore << endl;
}