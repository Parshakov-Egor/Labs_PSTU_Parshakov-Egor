#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a = 0.1;
    double b = 1.0;
    int k = 10;
    double h = (b - a) / k;
    int n = 40;
    double eps = 0.0001;

    cout << "X\t\tSN\t\tSE\t\tY" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (double x = a; x <= b + h / 2.0; x += h) {
        double sn = 0.0;
        double a_term = x;
        sn = sn + a_term;

        for (int i = 1; i < n; i++) {
            a_term = a_term * (x * x) / (2.0 * i * (2.0 * i + 1.0));
            sn = sn + a_term;
        }

        double se = 0.0;
        double e_term = x;
        int m = 1;

        while (fabs(e_term) >= eps) {
            se = se + e_term;
            e_term = e_term * (x * x) / (2.0 * m * (2.0 * m + 1.0));
            m++;
        }

        double y = sinh(x);

        cout << x << "\t" << sn << "\t" << se << "\t" << y << endl;
    }

    return 0;
}
