#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    // Задание 1 (float)
    float a = 1000, b = 0.0001;
    float c, d, e, f, g, res1;

    c = pow(a + b, 3);
    d = pow(a, 3);
    e = 3 * a * a * b;
    f = 3 * a * b * b;
    g = pow(b, 3);
    res1 = (c - (d + e)) / (f + g);

    cout << "Результат float: " << res1 << endl;

    // Задание 1 (double)
    double a1 = 1000, b1 = 0.0001;
    double c1, d1, e1, f1, g1, res2;

    c1 = pow(a1 + b1, 3);
    d1 = pow(a1, 3);
    e1 = 3 * a1 * a1 * b1;
    f1 = 3 * a1 * b1 * b1;
    g1 = pow(b1, 3);
    res2 = (c1 - (d1 + e1)) / (f1 + g1);

    cout << "Результат double: " << res2 << endl;

    // Задание 2
    int n, m;
    cout << "\nВведите n и m: ";
    cin >> n >> m;

    int r1 = ++n * ++m;
    cout << "1) ++n * ++m = " << r1 << " (n=" << n << ", m=" << m << ")" << endl;

    int r2 = m++ < n;
    cout << "2) m++ < n = " << r2 << " (n=" << n << ", m=" << m << ")" << endl;

    int r3 = n++ > m;
    cout << "3) n++ > m = " << r3 << " (n=" << n << ", m=" << m << ")" << endl;

    return 0;
}
