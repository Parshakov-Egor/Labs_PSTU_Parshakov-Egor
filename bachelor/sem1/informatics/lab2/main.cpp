#include <iostream>
#include <cmath>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double eps = 0.0001;
    double s = 0.0;
    int n = 2; // При n = 1 значение a_1 = lg(1!) * e^(-1) = 0

    // Вычисляем a_2
    double an = log10(tgamma(n + 1)) * exp(-n * sqrt(n));

    while (an >= eps)
    {
        s += an;
        n++;
        // Вычисляем следующий член ряда
        an = log10(tgamma(n + 1)) * exp(-n * sqrt(n));
    }

    cout << "Сумма ряда с точностью 0.0001 равна: " << s << endl;

    return 0;
}
