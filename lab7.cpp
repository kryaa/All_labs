#include "lab7.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 
using namespace std;
namespace lab7
{

    istream& operator>>(istream& is, DEMO& t)
    {
        is >> t.c1 >> t.f1 >> t.i >> t.f2 >> t.c2;
        return is;
    }
}