// Дополнительное задание 8.
// Сортировка одномерного массива методом выбора минимального элемента.

#include <iostream>
#include <clocale>

using namespace std;

void printArray(const int values[], int size)
{
    for (int i = 0; i < size; ++i)
        cout << values[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    const int SIZE = 10;
    int values[SIZE] = { -5, 1, 7, 5, 9, 10, 3, -8, 0, 11 };

    cout << "Сортировка методом выбора." << endl;
    cout << "Исходный массив: ";
    printArray(values, SIZE);

    // На позицию i по очереди ставится минимум из ещё не отсортированной части.
    for (int i = 0; i < SIZE - 1; ++i)
    {
        int minimumIndex = i;
        cout << "\nПроход № " << i + 1 << ": ищу минимум от индекса "
             << i << " до " << SIZE - 1 << "." << endl;
        cout << "Начальный кандидат: values[" << i << "] = "
             << values[i] << "." << endl;

        // Поиск начинается со следующего элемента, потому что values[i]
        // уже выбран в качестве начального кандидата.
        for (int j = i + 1; j < SIZE; ++j)
        {
            cout << "  Сравниваю " << values[j] << " с текущим минимумом "
                 << values[minimumIndex] << "." << endl;

            if (values[j] < values[minimumIndex])
            {
                minimumIndex = j;
                cout << "    Новый минимум находится на индексе "
                     << minimumIndex << "." << endl;
            }
        }

        // Обмен нужен только если минимум находится не на своём месте.
        if (minimumIndex != i)
        {
            int temp = values[i];
            values[i] = values[minimumIndex];
            values[minimumIndex] = temp;
            cout << "Меняю местами позиции " << i << " и "
                 << minimumIndex << "." << endl;
        }
        else
        {
            cout << "Минимум уже стоит на нужной позиции, обмен не требуется." << endl;
        }

        cout << "Массив после прохода: ";
        printArray(values, SIZE);
    }

    cout << "\nОтсортированный массив: ";
    printArray(values, SIZE);
    cout << "Сортировка выбором завершена." << endl;

    return 0;
}
