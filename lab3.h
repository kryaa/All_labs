#pragma once
#include <iostream>
#include <ctime>

using namespace std;

namespace lab3 {
	void runDemo();
	class Array
	{
		int n;
		int* array;

	public:
		Array() : n(1) { array = new int[2 * n]; array[0] = 0; array[1] = 0; }
		Array(int size);
		void AddNum(int n, int index);
		int MinSum();
		int MaxSumOfAll();
		void Print();
		~Array() { delete[] array; }
	};

}