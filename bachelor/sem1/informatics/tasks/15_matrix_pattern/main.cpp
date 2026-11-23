// Дополнительное задание 15.
// Заполнить квадратную матрицу нулями и единицами по условию:
// 0 ставится выше главной диагонали и выше побочной диагонали,
// то есть при i < j и i + j < n - 1. Остальные элементы равны 1.

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 20;
    int matrix[MAX_SIZE][MAX_SIZE];
    int size;

    cout << "Построение матрицы из нулей и единиц." << endl;
    cout << "Введите размер n (от 2 до 20): ";
    cin >> size;

    if (!cin || size < 2 || size > MAX_SIZE)
    {
        cout << "Ошибка: n должно быть целым числом от 2 до 20." << endl;
        return 1;
    }

    int zeroCount = 0;
    int oneCount = 0;

    cout << "\nПравило: если i < j и i + j < n - 1, записывается 0." << endl;
    cout << "Во всех остальных ячейках записывается 1." << endl;

    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            // Индексы начинаются с нуля, поэтому побочная диагональ
            // описывается равенством i + j == size - 1.
            if (i < j && i + j < size - 1)
            {
                matrix[i][j] = 0;
                ++zeroCount;
                cout << "Ячейка [" << i << "][" << j << "] — ноль." << endl;
            }
            else
            {
                matrix[i][j] = 1;
                ++oneCount;
            }
        }
    }

    cout << "\nПолученная матрица:" << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }

    cout << "\nМатрица сформирована." << endl;
    cout << "Нулей: " << zeroCount << ", единиц: " << oneCount
         << ", всего ячеек: " << size * size << "." << endl;

    return 0;
}
