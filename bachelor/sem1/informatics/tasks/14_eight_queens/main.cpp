// Дополнительное задание 14.
// Задача о восьми ферзях: расставить ферзей на доске 8 x 8 так,
// чтобы ни один из них не атаковал другого. Используется поиск с возвратом.

#include <iostream>
#include <clocale>

using namespace std;

const int BOARD_SIZE = 8;
int board[BOARD_SIZE][BOARD_SIZE] = {};
int solutionCount = 0;

// Выводим только первые три решения полностью.
// Всего решений 92, поэтому печать всех досок сделала бы вывод слишком длинным.
void printBoard()
{
    for (int row = 0; row < BOARD_SIZE; ++row)
    {
        for (int column = 0; column < BOARD_SIZE; ++column)
            cout << (board[row][column] ? " Ф " : " . ");
        cout << endl;
    }
}

// Проверка клетки перед установкой ферзя.
// Предыдущие строки ещё не обработаны ниже текущей строки, поэтому достаточно
// проверить столбец выше и две верхние диагонали.
bool isSafe(int row, int column)
{
    // Вертикаль вверх: два ферзя не должны находиться в одном столбце.
    for (int i = 0; i < row; ++i)
    {
        if (board[i][column])
            return false;
    }

    // Левая верхняя диагональ.
    for (int i = 1; row - i >= 0 && column - i >= 0; ++i)
    {
        if (board[row - i][column - i])
            return false;
    }

    // Правая верхняя диагональ.
    for (int i = 1; row - i >= 0 && column + i < BOARD_SIZE; ++i)
    {
        if (board[row - i][column + i])
            return false;
    }

    return true;
}

// Рекурсивная функция размещает по одному ферзю в каждой строке.
void solve(int row)
{
    // Если номер строки стал 8, все строки с 0 по 7 уже содержат ферзей.
    if (row == BOARD_SIZE)
    {
        ++solutionCount;
        cout << "Найдено решение № " << solutionCount << "." << endl;

        if (solutionCount <= 3)
        {
            printBoard();
            cout << endl;
        }
        return;
    }

    // Перебираем все столбцы текущей строки.
    for (int column = 0; column < BOARD_SIZE; ++column)
    {
        if (isSafe(row, column))
        {
            // Делаем пробный ход.
            board[row][column] = 1;

            // Переходим к следующей строке. Если ветка окажется неудачной,
            // рекурсия вернётся сюда и продолжит перебор столбцов.
            solve(row + 1);

            // Возврат назад: убираем ферзя, чтобы попробовать другую клетку.
            board[row][column] = 0;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Задача о восьми ферзях." << endl;
    cout << "Ф — ферзь, точка — пустая клетка." << endl;
    cout << "Запускаю рекурсивный поиск с возвратом.\n" << endl;

    solve(0);

    cout << "Поиск завершён. Всего найдено расстановок: "
         << solutionCount << "." << endl;
    cout << "На доске полностью показаны первые три решения." << endl;

    if (solutionCount == 92)
        cout << "Контроль совпал с известным количеством решений: 92." << endl;
    else
        cout << "Внимание: количество решений отличается от ожидаемых 92." << endl;

    return 0;
}
