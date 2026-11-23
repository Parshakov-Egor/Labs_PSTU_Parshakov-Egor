// Дополнительное задание 1.
// Дан одномерный массив. За один проход найти минимум и максимум,
// индексы их первого появления и количество повторений этих значений.

#include <iostream> // Потоки ввода и вывода.
#include <clocale>  // Русский язык в консоли.

using namespace std;

// Функция вывода вынесена отдельно, чтобы не повторять цикл печати.
void printArray(const int values[], int size)
{
    cout << "Массив: ";
    for (int i = 0; i < size; ++i)
        cout << values[i] << " ";
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    // Набор специально содержит несколько минимумов и максимумов.
    const int SIZE = 10;
    int values[SIZE] = { 15, 5, -10, 7, 8, -99, 78, 78, -99, -99 };

    cout << "Задание: поиск минимального и максимального элементов." << endl;
    printArray(values, SIZE);

    // Начальные значения берём из первого элемента, а не из нуля:
    // иначе программа могла бы ошибиться на массиве только отрицательных чисел.
    int minimum = values[0];
    int maximum = values[0];
    int firstMinimumIndex = 0;
    int firstMaximumIndex = 0;
    int minimumCount = 0;
    int maximumCount = 0;

    cout << "\nНачинаю единственный проход по массиву." << endl;

    for (int i = 0; i < SIZE; ++i)
    {
        cout << "Элемент [" << i << "] = " << values[i] << endl;

        // Для максимума используются два независимых условия:
        // сначала проверяем новый рекорд, затем возможное равенство.
        if (values[i] > maximum)
        {
            maximum = values[i];
            firstMaximumIndex = i;
            maximumCount = 1; // Старые повторения относились к прежнему максимуму.
            cout << "  Найден новый максимум: " << maximum << endl;
        }
        else if (values[i] == maximum)
        {
            ++maximumCount;
            cout << "  Этот элемент равен текущему максимуму." << endl;
        }

        // Проверка минимума не зависит от проверки максимума.
        // Это важно, например, для массива, состоящего из одинаковых чисел.
        if (values[i] < minimum)
        {
            minimum = values[i];
            firstMinimumIndex = i;
            minimumCount = 1;
            cout << "  Найден новый минимум: " << minimum << endl;
        }
        else if (values[i] == minimum)
        {
            ++minimumCount;
            cout << "  Этот элемент равен текущему минимуму." << endl;
        }
    }

    cout << "\nРезультаты обработки:" << endl;
    cout << "Максимум: " << maximum
         << ", первый индекс: " << firstMaximumIndex
         << ", номер в массиве: " << firstMaximumIndex + 1
         << ", повторений: " << maximumCount << endl;
    cout << "Минимум: " << minimum
         << ", первый индекс: " << firstMinimumIndex
         << ", номер в массиве: " << firstMinimumIndex + 1
         << ", повторений: " << minimumCount << endl;
    cout << "Проход завершён, все " << SIZE << " элементов обработаны." << endl;

    return 0;
}
