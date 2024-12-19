#include "lab7.h"
#include <iostream> 
#include <iomanip>
#include <sstream> 
#include <fstream> 

using namespace std;
namespace lab7
{

    string toHex(double fnumber, int precision = 10)
    {

        if (precision < 0) {
            throw invalid_argument("Precision must be non-negative.");
        }

        int iPart = static_cast<int>(fnumber);
        double fPart = fabs(fnumber - iPart);

        string hexIntegerPart = "";
        int intPart = abs(iPart);

        do {
            int r = intPart % 16;
            hexIntegerPart = (r < 10 ? static_cast<char>('0' + r) : static_cast<char>('A' + r - 10)) + hexIntegerPart;
            intPart /= 16;
        } while (intPart > 0);

        if (iPart < 0) {
            hexIntegerPart = "-" + hexIntegerPart;
        }

        // Перевод дробной части в 16-ричную
        string hexFractionalPart = "";
        for (int i = 0; i < precision; ++i) {
            fPart *= 16;
            int digit = static_cast<int>(fPart);
            hexFractionalPart += (digit < 10 ? static_cast<char>('0' + digit) : static_cast<char>('A' + digit - 10));
            fPart -= digit;

            if (fPart == 0.0) {
                break;
            }
        }

        if (!hexFractionalPart.empty()) {
            return hexIntegerPart + "." + hexFractionalPart;
        }
        else {
            return hexIntegerPart;
        }
    }

	void runDemo()
	{
        setlocale(LC_ALL, "Rus");
        char q; int t;
        while (true)
        {
            cout << "\nВы хотите запустить программу? (y/n) ";
            cin >> q;
            if (q == 'n') break;


            DEMO demo;
            cout << "Введите данные в порядке: c-в-ц-в-с, \n\t где в-вещественное число, ц-целое число, с-символ\n\n";
            cin >> demo;

            tuple<int, float, char, char, float> t = demo.GetFields();

            Manip manip1(6, '*', false);
            Manip manip2(6, '*', true);
            Manip manip3(6, '*', false, 1);
            Manip manip4(6, '*', false, 0);
            Manip manip5(6, '*', false, 2);
            // Вывод целого числа
            cout << manip1 << get<0>(t) << endl; // 42
            // Вывод целого числа в шестнадцатеричном формате
            cout << manip2 << hex << get<0>(t) << endl; // 2a

             // Вывод числа с плавающей запятой
            cout << manip3 << get<1>(t) << endl;
            cout << manip4 << get<1>(t) << endl;
            cout << manip5 << get<1>(t) << endl;

            cout << manip1 << toHex(get<1>(t), 1) << endl;
            cout << manip1 << toHex(get<1>(t), 0) << endl;
            cout << manip1 << toHex(get<1>(t), 2) << endl << "----------------------------------------------\n";

            cout << fixed << setw(6) << setfill('*') << dec << get<0>(t) // i
                << endl << fixed << setw(6) << setprecision(1) << setfill('*') << get<1>(t) // f1 1
                << endl << fixed << setw(6) << setprecision(0) << setfill('*') << get<1>(t) // f1 0
                << endl << fixed << setw(6) << setprecision(2) << setfill('*') << get<1>(t) // f1 2
                << endl << fixed << setw(6) << setfill('*') << get<2>(t) // c2
                << endl << fixed << setw(6) << setfill('*') << get<3>(t) // c1
                << endl << fixed << setw(6) << setprecision(1) << setfill('*') << get<4>(t) // f2 1
                << endl << fixed << setw(6) << setprecision(0) << setfill('*') << get<4>(t) // f2 0
                << endl << fixed << setw(6) << setprecision(2) << setfill('*') << get<4>(t) // f2 2


                << "\n\n16-ричная система счисления\n"
                << endl << fixed << setw(6) << setfill('*') << hex << get<0>(t) // i
                << endl << fixed << setw(6) << setfill('*') << toHex(get<1>(t), 1) // f1 2
                << endl << fixed << setw(6) << setfill('*') << toHex(get<1>(t), 0) // f1 0
                << endl << fixed << setw(6) << setfill('*') << toHex(get<1>(t), 2) // f1 3
                << endl << fixed << setw(6) << setfill('*') << toHex(get<4>(t), 1)  // f2 2
                << endl << fixed << setw(6) << setfill('*') << toHex(get<4>(t), 0) // f2 0
                << endl << fixed << setw(6) << setfill('*') << toHex(get<4>(t), 2) // f2 3
                ;

            ofstream outFile("output.txt");
            if (!outFile)
            {
                cout << "Failed to open file.";
            }
            else {
                outFile << fixed << setw(6) << setfill('*') << get<0>(t) // i
                    << endl << fixed << setw(6) << setprecision(1) << setfill('*') << get<1>(t) // f1 1
                    << endl << fixed << setw(6) << setprecision(0) << setfill('*') << get<1>(t) // f1 0
                    << endl << fixed << setw(6) << setprecision(2) << setfill('*') << get<1>(t) // f1 2
                    << endl << fixed << setw(6) << setfill('*') << get<2>(t) // c2
                    << endl << fixed << setw(6) << setfill('*') << get<3>(t) // c1
                    << endl << fixed << setw(6) << setprecision(1) << setfill('*') << get<4>(t) // f2 1
                    << endl << fixed << setw(6) << setprecision(0) << setfill('*') << get<4>(t) // f2 0
                    << endl << fixed << setw(6) << setprecision(2) << setfill('*') << get<4>(t) // f2 2


                    << "\n\n16-ричная система счисления\n"
                    << endl << fixed << setw(6) << setfill('*') << hex << get<0>(t) // i
                    << endl << fixed << setw(6) << setfill('*') << toHex(get<1>(t), 1) // f1 2
                    << endl << fixed << setw(6) << setfill('*') << toHex(get<1>(t), 0) // f1 0
                    << endl << fixed << setw(6) << setfill('*') << toHex(get<1>(t), 2) // f1 3
                    << endl << fixed << setw(6) << setfill('*') << toHex(get<4>(t), 1)  // f2 2
                    << endl << fixed << setw(6) << setfill('*') << toHex(get<4>(t), 0) // f2 0
                    << endl << fixed << setw(6) << setfill('*') << toHex(get<4>(t), 2); // f2 3

                outFile.close();
                cout << "\nРезультаты записаны в файл output.txt";
            }
        }
	}
}