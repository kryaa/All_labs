#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

namespace lab6 {
	void runDemo();
    template <typename T>
    class NumberArray
    {
        T* array;
        int size;

    public:
        NumberArray(int size);
        NumberArray(int size, int type);
        ~NumberArray();

        friend ostream& operator<<(ostream& os, const NumberArray& num)
        {
            for (int i = 0; i < num.size; ++i)
                os << num.array[i] << " ";
            return os;
        }

        void findMinNeighb();
        void findMaxNeighb();
    };


}