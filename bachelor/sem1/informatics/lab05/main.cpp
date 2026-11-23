#include <iostream>
#include <clocale>

using namespace std;

const int MAX_N = 10;

// Выводит квадратную матрицу на экран.
void printMatrix(const int matrix[][MAX_N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
}

// Ищет в столбце наименьший элемент, который больше previous.
// Для первого столбца диагонали ограничения ещё нет, поэтому ищем просто минимум.
int findSuitableRow(const int matrix[][MAX_N], int n, int column,
                    int previous, bool hasPrevious)
{
    int bestRow = -1;

    for (int row = 0; row < n; row++)
    {
        if (hasPrevious && matrix[row][column] <= previous)
            continue;

        if (bestRow == -1 || matrix[row][column] < matrix[bestRow][column])
            bestRow = row;
    }

    return bestRow; // -1 означает, что подходящего элемента нет.
}

// Пытается построить возрастающую последовательность на побочной диагонали.
// Порядок просмотра: от правого верхнего угла к левому нижнему.
bool arrangeDiagonal(int matrix[][MAX_N], int n, int diagonal[])
{
    int previous = 0;
    bool hasPrevious = false;

    for (int row = 0; row < n; row++)
    {
        int column = n - 1 - row;
        int suitableRow = findSuitableRow(matrix, n, column, previous, hasPrevious);

        if (suitableRow == -1)
            return false;

        // Перестановка разрешена внутри столбца, поэтому строки не затрагиваются целиком.
        int temp = matrix[row][column];
        matrix[row][column] = matrix[suitableRow][column];
        matrix[suitableRow][column] = temp;

        diagonal[row] = matrix[row][column];
        previous = diagonal[row];
        hasPrevious = true;
    }

    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int matrix[MAX_N][MAX_N];
    int working[MAX_N][MAX_N];
    int diagonal[MAX_N];
    int n;

    cout << "Введите размер квадратной матрицы (1–10): ";
    if (!(cin >> n) || n < 1 || n > MAX_N)
    {
        cout << "Ошибка: размер должен быть целым числом от 1 до 10." << endl;
        return 1;
    }

    cout << "Введите элементы матрицы построчно:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!(cin >> matrix[i][j]))
            {
                cout << "Ошибка: все элементы должны быть целыми числами." << endl;
                return 1;
            }
            working[i][j] = matrix[i][j];
        }
    }

    cout << "\nИсходная матрица:" << endl;
    printMatrix(matrix, n);

    // На каждом шаге выбираем наименьший возможный элемент, больший предыдущего.
    // Такой выбор оставляет максимум возможностей для следующих столбцов.
    if (arrangeDiagonal(working, n, diagonal))
    {
        cout << "\nВозрастающую побочную диагональ получить можно." << endl;
        cout << "Матрица после перестановок в столбцах:" << endl;
        printMatrix(working, n);

        cout << "Побочная диагональ (справа сверху влево вниз): ";
        for (int i = 0; i < n; i++)
            cout << diagonal[i] << " ";
        cout << endl;
    }
    else
    {
        cout << "\nВозрастающую побочную диагональ получить нельзя:" << endl;
        cout << "в одном из столбцов нет элемента, большего предыдущего." << endl;
    }

    return 0;
}
