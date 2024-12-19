#include <iostream>
using namespace std;
#include "lab2.h"
namespace lab2
{

	void runDemo()
	{

        setlocale(LC_ALL, "Russian");
        DoublyLinkedList* studentList = new DoublyLinkedList;

        studentList->addStudent(Student("Ivanov", "Ivan", "Ivanovich", "111101", 21, 4.3));
        studentList->addStudent(Student("Petrova", "Alisa", "Sergeevna", "111101", 20, 3.8));
        studentList->addStudent(Student("Sidorov", "Andrew", "Aleksandrovich", "331103", 18, 5.0));
        studentList->addStudent(Student("Ivanova", "Anna", "Petrovna", "221104", 22, 4.1));

        cout << "Список студентов:" << endl;
        studentList->printStudents();
        char n;
        while (true)
        {
            cout << "\nВы хотите осуществить поиск? (y/n) ";
            cin >> n;
            if (n == 'n') break;

            string search;
            cout << "\nВведите фамилию для поиска однофамильцев: ";
            cin >> search;

            studentList->findSameSurname(search);
        }
        delete studentList;
	}
}