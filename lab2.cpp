#include "lab2.h"
using namespace std;
namespace lab2
{
    DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    DoublyLinkedList::~DoublyLinkedList()
    {
        while (head)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // добавление студента
    void DoublyLinkedList::addStudent(Student student)
    {
        Node* newNode = new Node(student);
        if (!head)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // поиск однофамильцев
    void DoublyLinkedList::findSameSurname(string surname)
    {
        Node* current = head;
        bool t = true;
        while (current)
        {
            if (current == head)
                cout << "Однофамильцы с фамилией '" << surname;

            if (surname.back() == 'a')
                surname = surname.substr(0, surname.size() - 1);

            if (current->data.sname == surname || current->data.sname == surname + "a")
            {
                if (t) cout << ": \n";
                current->data.printStudent(); t = false;
            }


            current = current->next;
        }

        if (t)
            cout << " не найдены!\n";

    }

    // вывод студентов
    void DoublyLinkedList::printStudents()
    {
        Node* current = head;
        while (current)
        {
            current->data.printStudent();
            current = current->next;
        }
    }
}