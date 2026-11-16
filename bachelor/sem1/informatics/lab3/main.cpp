#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const double PI = 3.14159265358979323846;
    const double a = PI / 5.0;
    const double b = PI;
    const int k = 10;          // Количество разбиений отрезка.
    const int n = 40;          // Количество слагаемых для суммы SN.
    const double eps = 0.0001; // Точность для суммы SE.
    const double h = (b - a) / k;

    cout << "Вычисление функции разложением в ряд" << endl;
    cout << "X - аргумент, SN - 40 слагаемых, SE - заданная точность, Y - точное значение" << endl;
    cout << string(78, '-') << endl;
    cout << setw(12) << "X" << setw(18) << "SN"
         << setw(18) << "SE" << setw(18) << "Y" << endl;
    cout << string(78, '-') << endl;
    cout << fixed << setprecision(6);

    // Внешний цикл перебирает ровно 11 точек от a до b включительно.
    for (int step = 0; step <= k; step++)
    {
        double x = a + step * h;
        double sn = 0.0;

        // Сумма заданного числа слагаемых: cos((2m-1)x)/(2m-1)^2.
        for (int m = 1; m <= n; m++)
        {
            double odd = 2.0 * m - 1.0;
            sn += cos(odd * x) / (odd * odd);
        }

        // Для второй суммы останавливаемся, когда |очередной член| < eps.
        double se = 0.0;
        int m = 1;
        while (true)
        {
            double odd = 2.0 * m - 1.0;
            double term = cos(odd * x) / (odd * odd);

            if (fabs(term) < eps)
                break;

            se += term;
            m++;
        }

        // На отрезке [pi/5; pi] значение x положительно, поэтому |x| = x.
        double y = PI * PI / 8.0 - PI / 4.0 * fabs(x);

        cout << setw(12) << x << setw(18) << sn
             << setw(18) << se << setw(18) << y << endl;
    }

    cout << string(78, '-') << endl;
    return 0;
}
