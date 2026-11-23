// Дополнительное задание 4.
// Проверить, является ли вводимая последовательность строго возрастающей.
// Признак окончания ввода — число 0. Сам ноль в последовательность не входит.

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    int previous;
    int current;

    cout << "Проверка последовательности на возрастание." << endl;
    cout << "Вводите целые числа. Для завершения введите 0." << endl;
    cout << "Первое число: ";
    cin >> previous;

    if (!cin)
    {
        cout << "Ошибка: ожидалось целое число." << endl;
        return 1;
    }

    if (previous == 0)
    {
        cout << "Последовательность пуста, проверять нечего." << endl;
        return 0;
    }

    cout << "Второе число: ";
    cin >> current;

    if (!cin)
    {
        cout << "Ошибка: ожидалось целое число." << endl;
        return 1;
    }

    if (current == 0)
    {
        cout << "Введён только один элемент. Для сравнения нужно минимум два числа." << endl;
        return 0;
    }

    bool isIncreasing = true;
    int position = 2; // current является вторым элементом последовательности.

    // Цикл продолжается, пока не встретится ноль или первое нарушение.
    while (current != 0 && isIncreasing)
    {
        cout << "Пара № " << position - 1 << ": " << previous
             << " и " << current << "." << endl;

        if (previous >= current)
        {
            isIncreasing = false;
            cout << "  Нарушение: следующее число не больше предыдущего." << endl;
        }
        else
        {
            cout << "  Пара расположена правильно." << endl;
            previous = current;

            cout << "Следующее число (или 0): ";
            cin >> current;
            if (!cin)
            {
                cout << "Ошибка: ожидалось целое число." << endl;
                return 1;
            }
            ++position;
        }
    }

    cout << "\nВвод и проверка завершены." << endl;
    if (isIncreasing)
        cout << "Результат: последовательность строго возрастающая." << endl;
    else
        cout << "Результат: последовательность не является строго возрастающей." << endl;

    return 0;
}
