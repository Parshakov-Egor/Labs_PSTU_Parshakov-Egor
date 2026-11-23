// Дополнительное задание 16.
// Ввести матрицу 2 x 4, вывести её и вычислить сумму каждой строки.
// Дополнительно определяется сумма всех элементов матрицы.

#include <iostream>
#include <iomanip> // setw для ровного вывода матрицы.
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int ROWS = 2;
    const int COLUMNS = 4;
    int matrix[ROWS][COLUMNS];

    cout << "Вычисление сумм строк матрицы 2 x 4." << endl;
    cout << "Введите 8 целых чисел." << endl;

    // Ввод идёт по строкам: сначала четыре элемента первой строки,
    // затем четыре элемента второй строки.
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            cout << "Элемент [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];

            if (!cin)
            {
                cout << "Ошибка: все элементы должны быть целыми числами." << endl;
                return 1;
            }
        }
        cout << "Строка " << i + 1 << " введена полностью." << endl;
    }

    cout << "\nИсходная матрица:" << endl;
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
            cout << setw(6) << matrix[i][j];
        cout << endl;
    }

    int totalSum = 0;
    cout << "\nВычисление сумм:" << endl;

    for (int i = 0; i < ROWS; ++i)
    {
        // Сумму обнуляем перед каждой новой строкой, иначе в неё попадут
        // значения предыдущей строки.
        int rowSum = 0;

        for (int j = 0; j < COLUMNS; ++j)
        {
            rowSum += matrix[i][j];
            cout << "Строка " << i + 1 << ": после элемента " << j + 1
                 << " сумма равна " << rowSum << "." << endl;
        }

        totalSum += rowSum;
        cout << "Итоговая сумма строки " << i + 1 << ": " << rowSum << "." << endl;
    }

    cout << "\nСумма всех элементов матрицы: " << totalSum << "." << endl;
    cout << "Вычисления завершены успешно." << endl;

    return 0;
}
