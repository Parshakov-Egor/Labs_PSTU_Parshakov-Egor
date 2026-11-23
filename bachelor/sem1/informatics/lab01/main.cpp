#include <iostream>
#include <cmath>
#include <clocale>
#include <iomanip>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Задание 1: вычисляем одно выражение сначала в float, затем в double.
    // Промежуточные переменные нужны, чтобы повторить порядок из методички.
    float a = 1000.0f;
    float b = 0.0001f;

    float c = pow(a + b, 3.0f);
    float d = pow(a, 3.0f);
    float e = 3.0f * a * a * b;
    float f = 3.0f * a * b * b;
    float g = pow(b, 3.0f);
    float resultFloat = (c - (d + e)) / (f + g);

    double aDouble = 1000.0;
    double bDouble = 0.0001;

    double cDouble = pow(aDouble + bDouble, 3);
    double dDouble = pow(aDouble, 3);
    double eDouble = 3.0 * aDouble * aDouble * bDouble;
    double fDouble = 3.0 * aDouble * bDouble * bDouble;
    double gDouble = pow(bDouble, 3);
    double resultDouble = (cDouble - (dDouble + eDouble)) / (fDouble + gDouble);

    cout << scientific << setprecision(8);
    cout << "Задание 1" << endl;
    cout << "Результат при типе float:  " << resultFloat << endl;
    cout << "Результат при типе double: " << resultDouble << endl;

    // Задание 2: значения n и m меняются после каждого инкремента.
    int n, m;
    cout << "\nЗадание 2" << endl;
    cout << "Введите два целых числа n и m: ";

    if (!(cin >> n >> m))
    {
        cout << "Ошибка: нужно ввести два целых числа." << endl;
        return 1;
    }

    // Префиксный инкремент сначала увеличивает переменную, затем использует её.
    int first = ++n * ++m;
    cout << "1) ++n * ++m = " << first
         << "; n = " << n << ", m = " << m << endl;

    // Постфиксный инкремент использует старое значение, а потом увеличивает его.
    int second = m++ < n;
    cout << "2) m++ < n = " << second
         << "; n = " << n << ", m = " << m << endl;

    int third = n++ > m;
    cout << "3) n++ > m = " << third
         << "; n = " << n << ", m = " << m << endl;

    return 0;
}
