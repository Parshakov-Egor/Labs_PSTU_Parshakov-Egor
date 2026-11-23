// Дополнительное задание 9.
// Сортировка одномерного массива методом вставок.

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

    cout << "Сортировка методом вставок." << endl;
    cout << "Исходный массив: ";
    printArray(values, SIZE);
    cout << "Первый элемент условно считается уже отсортированной частью." << endl;

    // i указывает на очередной элемент неотсортированной части.
    for (int i = 1; i < SIZE; ++i)
    {
        int current = values[i];
        int j = i - 1;

        cout << "\nВставка элемента " << current << " с индекса " << i << "." << endl;
        cout << "Слева находится отсортированная часть: ";
        for (int k = 0; k < i; ++k)
            cout << values[k] << " ";
        cout << endl;

        // Двигаемся влево, пока есть элементы и они больше current.
        // Каждый такой элемент сдвигается на одну позицию вправо.
        while (j >= 0 && values[j] > current)
        {
            cout << "  " << values[j] << " больше " << current
                 << ": сдвигаю его в позицию " << j + 1 << "." << endl;
            values[j + 1] = values[j];
            --j;
        }

        // После цикла j указывает на элемент перед местом вставки.
        values[j + 1] = current;
        cout << "Вставляю " << current << " в позицию " << j + 1 << "." << endl;
        cout << "Массив после вставки: ";
        printArray(values, SIZE);
    }

    cout << "\nОтсортированный массив: ";
    printArray(values, SIZE);
    cout << "Все элементы перенесены в отсортированную часть." << endl;

    return 0;
}
