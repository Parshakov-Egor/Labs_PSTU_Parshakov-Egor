// Дополнительное задание 6.
// Сформировать матрицу из двух строк и найти сумму всех её элементов.
// Дополнительно выводятся суммы отдельных строк и сама матрица.

#include <iostream>
#include <cstdlib> // rand и srand.
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int ROWS = 2;
    const int MAX_COLUMNS = 20;
    int columns;

    cout << "Суммирование элементов матрицы из двух строк." << endl;
    cout << "Введите количество столбцов (от 1 до 20): ";
    cin >> columns;

    if (!cin || columns < 1 || columns > MAX_COLUMNS)
    {
        cout << "Ошибка: количество столбцов должно быть от 1 до 20." << endl;
        return 1;
    }

    // Массив имеет фиксированный максимальный размер, поэтому программа
    // соответствует стандарту C++ и не использует массив переменной длины.
    int matrix[ROWS][MAX_COLUMNS];

    // Фиксированное зерно делает контрольный пример повторяемым:
    // при каждом запуске будут получены одинаковые псевдослучайные числа.
    srand(16);
    cout << "\nЗаполняю матрицу числами от 0 до 99." << endl;

    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = rand() % 100;
            cout << "matrix[" << i << "][" << j << "] = "
                 << matrix[i][j] << endl;
        }
    }

    cout << "\nПолученная матрица:" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < columns; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    int totalSum = 0;

    // После заполнения выполняем отдельный проход для суммирования.
    // Так этапы формирования и обработки массива не смешиваются.
    for (int i = 0; i < ROWS; ++i)
    {
        int rowSum = 0;
        for (int j = 0; j < columns; ++j)
        {
            rowSum += matrix[i][j];
            cout << "Строка " << i + 1 << ": промежуточная сумма = "
                 << rowSum << endl;
        }

        totalSum += rowSum;
        cout << "Сумма строки " << i + 1 << ": " << rowSum << endl;
    }

    cout << "\nОбщая сумма всех элементов: " << totalSum << endl;
    cout << "Обработано элементов: " << ROWS * columns << "." << endl;

    return 0;
}
