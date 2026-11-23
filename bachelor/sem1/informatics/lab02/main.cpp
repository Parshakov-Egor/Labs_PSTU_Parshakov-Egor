#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const double eps = 0.0001;
    double sum = 0.0;

    // Первый член ряда при n = 1 равен нулю, поэтому начинаем с n = 2.
    int n = 2;
    double factorial = 2.0; // Факториал текущего n: 2! = 2.
    double term = log10(factorial) * exp(-n * sqrt(n));
    int addedTerms = 0;

    cout << "Учитываемые члены ряда:" << endl;
    cout << fixed << setprecision(10);

    // Добавляем члены, пока текущий член не станет меньше точности eps.
    while (term >= eps)
    {
        cout << "n = " << n << ", a(n) = " << term << endl;
        sum += term;
        addedTerms++;

        // Переходим к следующему члену по рекуррентному соотношению.
        // Факториал также получаем из предыдущего: (n + 1)! = n! * (n + 1).
        int nextN = n + 1;
        double nextFactorial = factorial * nextN;
        double logarithmRatio = log10(nextFactorial) / log10(factorial);
        double exponentRatio = exp(n * sqrt(n) - nextN * sqrt(nextN));

        term = term * logarithmRatio * exponentRatio;
        factorial = nextFactorial;
        n = nextN;
    }

    cout << "\nПервый член меньше точности: n = " << n
         << ", a(n) = " << term << endl;
    cout << "Количество сложенных членов: " << addedTerms << endl;
    cout << "Сумма ряда с точностью " << eps << ": " << sum << endl;

    return 0;
}
