// Дополнительное задание 3.
// Дан двумерный массив. Найти максимальный элемент и его индексы.

#include <iostream>
#include <clocale>

using namespace std;

// Функция печатает матрицу и подписывает номера строк.
void printMatrix(const int matrix[][4], int rows)
{
    for (int i = 0; i < rows; ++i)
    {
        cout << "Строка " << i << ": ";
        for (int j = 0; j < 4; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int ROWS = 3;
    const int COLUMNS = 4;
    int matrix[ROWS][COLUMNS] = {
        { 1, 2, 5, 6 },
        { 5, 4, 2, 1 },
        { 42, 60, 23, 5 }
    };

    cout << "Поиск максимального элемента в матрице 3 x 4." << endl;
    printMatrix(matrix, ROWS);

    // Первый элемент становится начальным максимумом.
    int maximum = matrix[0][0];
    int maxRow = 0;
    int maxColumn = 0;

    cout << "\nНачальный максимум: " << maximum << " в ячейке [0][0]." << endl;

    // Два вложенных цикла позволяют рассмотреть каждую ячейку ровно один раз.
    for (int i = 0; i < ROWS; ++i)
    {
        for (int j = 0; j < COLUMNS; ++j)
        {
            cout << "Проверяю [" << i << "][" << j << "] = "
                 << matrix[i][j] << "." << endl;

            if (matrix[i][j] > maximum)
            {
                maximum = matrix[i][j];
                maxRow = i;
                maxColumn = j;
                cout << "  Максимум обновлён: " << maximum << endl;
            }
        }
    }

    cout << "\nОбработка матрицы завершена." << endl;
    cout << "Максимальное значение: " << maximum << endl;
    cout << "Индексы (нумерация с нуля): [" << maxRow << "][" << maxColumn << "]" << endl;
    cout << "Позиция для пользователя: строка " << maxRow + 1
         << ", столбец " << maxColumn + 1 << "." << endl;

    return 0;
}
