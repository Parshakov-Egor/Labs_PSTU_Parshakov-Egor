#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double eps = 0.0001;
    double s = 0;
    int n = 2; // при n = 1 член ряда a1 = lg(1!) * e^(-1) = 0
    double f = 2; // n! при n = 2
    double a = log10(f) * exp(-n * sqrt(n));

    while (a >= eps)
    {
        s = s + a;
        double f_next = f * (n + 1);
        a = a * (log10(f_next) / log10(f)) * exp(n * sqrt(n) - (n + 1) * sqrt(n + 1));
        f = f_next;
        n++;
    }

    cout << "Сумма ряда с точностью 0.0001 равна: " << s << endl;

    return 0;
}
