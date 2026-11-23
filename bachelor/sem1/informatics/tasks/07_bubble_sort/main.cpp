// Дополнительное задание 7.
// Сортировка одномерного массива методом пузырька (обменная сортировка).

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
    int values[SIZE] = { -5, 1, 7, 5, 9, 10, 3, -8, 0, -16 };

    cout << "Сортировка методом пузырька." << endl;
    cout << "Исходный массив: ";
    printArray(values, SIZE);

    // После каждого внешнего прохода очередной минимум всплывает влево,
    // поэтому внутренний цикл заканчивается на позиции i + 1.
    for (int i = 0; i < SIZE - 1; ++i)
    {
        bool swapped = false;
        cout << "\nПроход № " << i + 1 << "." << endl;

        for (int j = SIZE - 1; j > i; --j)
        {
            cout << "Сравнение [" << j - 1 << "] и [" << j << "]: "
                 << values[j - 1] << " и " << values[j] << "." << endl;

            if (values[j - 1] > values[j])
            {
                // Три оператора обмена используют временную переменную temp.
                int temp = values[j - 1];
                values[j - 1] = values[j];
                values[j] = temp;
                swapped = true;

                cout << "  Выполнен обмен. Теперь: ";
                printArray(values, SIZE);
            }
        }

        // Если обменов не было, массив уже отсортирован.
        // Досрочный выход уменьшает количество лишних проверок.
        if (!swapped)
        {
            cout << "На этом проходе обменов нет — сортировка завершена досрочно." << endl;
            break;
        }
    }

    cout << "\nОтсортированный массив по возрастанию: ";
    printArray(values, SIZE);
    cout << "Работа алгоритма завершена." << endl;

    return 0;
}
