#pragma once
#include "Node.h"
#include <vector>

namespace lab2 {
	void runDemo();
    class DoublyLinkedList
    {
    private:
        Node* head;
        Node* tail;

    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        void addStudent(Student student);
        void findSameSurname(string surname);
        void printStudents();
    };

}