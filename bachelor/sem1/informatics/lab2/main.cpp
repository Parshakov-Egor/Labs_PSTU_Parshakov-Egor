#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    double eps = 0.0001;
    double s = 0;
    double a = 1.0 / 3.0; // первый член ряда при n = 1
    int n = 1;

    while (a >= eps)
    {
        s = s + a;
        a = a * (n + 1) * (n + 1) / (3.0 * n * n);
        n++;
    }

    cout << "Сумма ряда с точностью 0.0001 равна: " << s << endl;

    return 0;
}
