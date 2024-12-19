#pragma once

#include "Student.h"

class Node
{
public:
    Student data;
    Node* next;
    Node* prev;

    Node(Student student) : data(student), next(nullptr), prev(nullptr) {}
};



