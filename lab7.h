#pragma once
#include <iostream>
#include <tuple>
#include <iomanip> 
#include <cstring> 
#include <sstream>
#include <string>
#include <type_traits>
using namespace std;

namespace lab7 {
	void runDemo();
    class DEMO
    {


    public:
        DEMO(char c1, float f1, int i, float f2, char c2)
            : f1(f1), f2(f2), i(i), c1(c1), c2(c2) {}

        DEMO()
            : f1(0.0), f2(0.1), i(2), c1('a'), c2('b') {}

        tuple<int, float, char, char, float> GetFields(char c1, float f1, int i, float f2, char c2)
        {
            this->f1 = f1; this->f2 = f2; this->c1 = c1; this->c2 = c2; this->i = i;
            return make_tuple(i, f1, c2, c1, f2);
        }

        tuple<int, float, char, char, float  > GetFields()
        {

            return make_tuple(i, f1, c2, c1, f2);
        }

        friend istream& operator>>(istream& is, DEMO& t);
        friend ostream& operator<<(ostream& os, tuple<char, float, int, float, char>& t);

    protected:
        float f1;
        float f2;
        int i;
        char c1;
        char c2;
    };



    class Manip {
    public:
        Manip(int width, char fillChar, bool fixed_ = false, int precision = -1)
            : width(width), fillChar(fillChar), fixed_(fixed_), precision(precision) {}


        friend ostream& operator<<(ostream& os, Manip& num)
        {
            os << fixed << setw(num.width) << setfill(num.fillChar);
            if (num.fixed_)
            {
                os << hex;
            }
            if (num.precision >= 0)
            {
                os << setprecision(num.precision);
            }

            return os;
        }




    private:
        int width;
        char fillChar;
        bool fixed_;
        int precision;
    };

}