// Дополнительное задание 2.
// Проверить, упорядочен ли массив по строгому возрастанию.
// Используется флажок bool и цикл while с досрочной остановкой.

#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 100;
    int values[MAX_SIZE];
    int size;

    cout << "Проверка массива на строгое возрастание." << endl;
    cout << "Введите количество элементов (от 1 до 100): ";
    cin >> size;

    if (!cin || size < 1 || size > MAX_SIZE)
    {
        cout << "Ошибка: размер должен быть целым числом от 1 до 100." << endl;
        return 1;
    }

    // Вводим ровно size элементов, не выходя за границы статического массива.
    for (int i = 0; i < size; ++i)
    {
        cout << "Элемент [" << i << "]: ";
        cin >> values[i];
        if (!cin)
        {
            cout << "Ошибка: элемент массива должен быть целым числом." << endl;
            return 1;
        }
    }

    cout << "Введённый массив: ";
    for (int i = 0; i < size; ++i)
        cout << values[i] << " ";
    cout << endl;

    // false означает, что нарушение порядка пока не обнаружено.
    bool hasViolation = false;
    int i = 0;

    cout << "\nСравнение соседних элементов:" << endl;

    // Последняя проверяемая пара имеет индексы size - 2 и size - 1.
    // Поэтому условие i < size - 1 исключает выход за границу массива.
    while (!hasViolation && i < size - 1)
    {
        cout << "  values[" << i << "] = " << values[i]
             << ", values[" << i + 1 << "] = " << values[i + 1];

        // Для строгого возрастания даже равенство соседей является нарушением.
        if (values[i] >= values[i + 1])
        {
            hasViolation = true;
            cout << " — нарушение: левый элемент не меньше правого." << endl;
        }
        else
        {
            cout << " — порядок соблюдён." << endl;
        }

        ++i;
    }

    cout << "\nПроверка завершена." << endl;
    if (hasViolation)
        cout << "Вывод: массив НЕ упорядочен по строгому возрастанию." << endl;
    else
        cout << "Вывод: массив упорядочен по строгому возрастанию." << endl;

    return 0;
}
