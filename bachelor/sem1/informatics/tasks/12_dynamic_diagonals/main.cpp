// Дополнительное задание 12.
// Создать динамическую квадратную матрицу и обнулить элементы
// главной и побочной диагоналей.

#include <iostream>
#include <clocale>
#include <new>

using namespace std;

// Создание матрицы разделено на массив указателей и отдельные строки.
int** createMatrix(int size)
{
    int** matrix = new (nothrow) int*[size];
    if (matrix == nullptr)
        return nullptr;

    for (int i = 0; i < size; ++i)
    {
        matrix[i] = new (nothrow) int[size];

        if (matrix[i] == nullptr)
        {
            // Если очередная строка не создана, удаляем только уже выделенные.
            for (int j = 0; j < i; ++j)
                delete[] matrix[j];
            delete[] matrix;
            return nullptr;
        }
    }

    return matrix;
}

void fillMatrix(int** matrix, int size)
{
    int value = 1;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            matrix[i][j] = value;
            ++value;
        }
    }
    cout << "Матрица заполнена последовательными числами." << endl;
}

void printMatrix(int** matrix, int size, const char* title)
{
    cout << "\n" << title << endl;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

void zeroDiagonals(int** matrix, int size)
{
    cout << "\nОбнуление диагоналей:" << endl;
    for (int i = 0; i < size; ++i)
    {
        int secondaryColumn = size - 1 - i;

        cout << "Строка " << i << ": главная диагональ — столбец " << i
             << ", побочная — столбец " << secondaryColumn << "." << endl;

        matrix[i][i] = 0;
        matrix[i][secondaryColumn] = 0;

        // При нечётном размере центральная ячейка принадлежит обеим диагоналям.
        // Повторное присваивание нуля безопасно и не меняет результат.
        if (i == secondaryColumn)
            cout << "  Это центральная ячейка, общая для обеих диагоналей." << endl;
    }
}

void deleteMatrix(int** matrix, int size)
{
    if (matrix == nullptr)
        return;

    cout << "\nОсвобождение памяти матрицы:" << endl;
    for (int i = 0; i < size; ++i)
    {
        delete[] matrix[i];
        cout << "  Строка " << i << " удалена." << endl;
    }
    delete[] matrix;
    cout << "Массив указателей удалён." << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int size;
    cout << "Динамическая матрица: обнуление двух диагоналей." << endl;
    cout << "Введите размер матрицы (от 2 до 20): ";
    cin >> size;

    if (!cin || size < 2 || size > 20)
    {
        cout << "Ошибка: размер должен быть целым числом от 2 до 20." << endl;
        return 1;
    }

    int** matrix = createMatrix(size);
    if (matrix == nullptr)
    {
        cout << "Ошибка: недостаточно памяти для матрицы." << endl;
        return 1;
    }

    cout << "Динамическая матрица " << size << " x " << size << " создана." << endl;
    fillMatrix(matrix, size);
    printMatrix(matrix, size, "Исходная матрица:");
    zeroDiagonals(matrix, size);
    printMatrix(matrix, size, "Матрица после обнуления диагоналей:");
    deleteMatrix(matrix, size);
    matrix = nullptr;

    cout << "Работа программы успешно завершена." << endl;
    return 0;
}
