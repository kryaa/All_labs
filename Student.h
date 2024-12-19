#pragma once

#include <string>
#include <iostream>

using namespace std;

class Student
{
public:
    string name;
    string sname;
    string otch;
    string groupNumber;
    int age;
    float averscore;

    Student(string sname, string name, string otch, string group, int age, float averscore);
    void printStudent();
};


