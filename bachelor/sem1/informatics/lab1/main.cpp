#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "=== Задание 1 (Вариант 16) ===" << endl;
    // Вычисление для типа float
    float a_f = 1000.0f, b_f = 0.0001f;
    float c_f = pow(a_f + b_f, 3);
    float d_f = pow(a_f, 3) + 3 * a_f * a_f * b_f;
    float e_f = 3 * a_f * b_f * b_f + pow(b_f, 3);
    float res_f = (c_f - d_f) / e_f;

    // Вычисление для типа double
    double a_d = 1000.0, b_d = 0.0001;
    double c_d = pow(a_d + b_d, 3);
    double d_d = pow(a_d, 3) + 3 * a_d * a_d * b_d;
    double e_d = 3 * a_d * b_d * b_d + pow(b_d, 3);
    double res_d = (c_d - d_d) / e_d;

    cout << "Результат (float):  " << res_f << endl;
    cout << "Результат (double): " << res_d << endl << endl;

    cout << "=== Задание 2 (Вариант 16) ===" << endl;
    int n, m;
    cout << "Введите целые числа n и m через пробел: ";
    cin >> n >> m;

    int n1 = n, m1 = m;
    cout << "1) ++n * ++m = " << (++n1 * ++m1) << " (после: n=" << n1 << ", m=" << m1 << ")" << endl;

    int n2 = n, m2 = m;
    cout << "2) m++ < n   = " << (m2++ < n2) << " (после: n=" << n2 << ", m=" << m2 << ")" << endl;

    int n3 = n, m3 = m;
    cout << "3) n++ > m   = " << (n3++ > m3) << " (после: n=" << n3 << ", m=" << m3 << ")" << endl;

    return 0;
}
