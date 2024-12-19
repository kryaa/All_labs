#include <iostream>
#include <limits> 
#include "lab1.h"
#include "lab2.h"
#include "lab3.h"
#include "lab4.h"
#include "lab5.h"
#include "lab6.h"
#include "lab7.h"

int main() {
	setlocale(LC_ALL, "Rus");

	int choice{ 0 };
	while (true) {
		std::cout << "-----------����----------\n\n";
		
		std::cout << "-1. �������� �������\n";
		std::cout << "1. ��������� lab1\n";
		std::cout << "2. ��������� lab2\n";
		std::cout << "3. ��������� lab3\n";
		std::cout << "4. ��������� lab4\n";
		std::cout << "5. ��������� lab5\n";
		std::cout << "6. ��������� lab6\n";
		std::cout << "7. ��������� lab7\n";
		std::cout << "0. ���������\n\n"; 
		std::cout << "-------------------------\n������� ����� ��������� ��� �������:\n";
		std::cin >> choice;

		switch (choice) {
		case -1:
			system("cls");
			break;
		case 1:
			lab1::runDemo();
			break;
		case 2:
			lab2::runDemo();
			break;
		case 3:
			lab3::runDemo();
			break;
		case 4:
			lab4::runDemo();
			break;
		case 5:
			lab5::runDemo();
			break;
		case 6:
			lab6::runDemo();
			break;
		case 7:
			lab7::runDemo();
			break;
		case 0:
			std::cout << "������� ��������.\n";
			return 0;
		default:
			std::cout << "������� ������������ �����.\n";
		}
	}
}