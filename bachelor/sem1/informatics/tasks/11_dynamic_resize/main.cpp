// Дополнительное задание 11.
// Изменить длину динамического массива: сначала увеличить, затем уменьшить.
// Старые элементы сохраняются, новые позиции заполняются нулями.

#include <iostream>
#include <clocale>
#include <new>

using namespace std;

void printArray(const int* values, int size, const char* title)
{
    cout << title << " (размер " << size << "): ";
    if (values == nullptr || size == 0)
    {
        cout << "<пусто>" << endl;
        return;
    }

    for (int i = 0; i < size; ++i)
        cout << values[i] << " ";
    cout << endl;
}

// Указатель передаётся по ссылке, поскольку новый блок может иметь другой адрес.
// Функция не меняет старый массив при ошибке выделения памяти.
bool resizeArray(int*& values, int oldSize, int newSize)
{
    if (newSize < 0)
    {
        cout << "Ошибка: отрицательный размер недопустим." << endl;
        return false;
    }

    cout << "\nИзменение размера: " << oldSize << " -> " << newSize << "." << endl;

    int* newValues = nullptr;
    if (newSize > 0)
    {
        // Пустые фигурные скобки обнуляют все новые элементы.
        newValues = new (nothrow) int[newSize]{};
        if (newValues == nullptr)
        {
            cout << "Не удалось выделить память. Старый массив сохранён." << endl;
            return false;
        }
    }

    // При увеличении копируются все старые элементы, при уменьшении — только
    // первые newSize. Поэтому выбирается меньший из двух размеров.
    int copyCount = oldSize < newSize ? oldSize : newSize;
    for (int i = 0; i < copyCount; ++i)
    {
        newValues[i] = values[i];
        cout << "  Копирую values[" << i << "] = " << values[i] << "." << endl;
    }

    if (newSize > copyCount)
        cout << "Позиции с " << copyCount << " по " << newSize - 1
             << " заполнены нулями." << endl;

    delete[] values;
    values = newValues;
    cout << "Старый блок памяти освобождён, указатель обновлён." << endl;
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int size = 8;
    int* values = new (nothrow) int[size]{ 1, 5, 0, -1, 15, 9, 77, 13 };

    if (values == nullptr)
    {
        cout << "Ошибка создания исходного массива." << endl;
        return 1;
    }

    cout << "Работа с длиной динамического массива." << endl;
    printArray(values, size, "Исходный массив");

    int increasedSize;
    cout << "\nВведите новый больший размер: ";
    cin >> increasedSize;

    if (!cin || increasedSize <= size)
    {
        cout << "Ошибка: на первом шаге размер должен быть больше " << size << "." << endl;
        delete[] values;
        return 1;
    }

    if (resizeArray(values, size, increasedSize))
    {
        size = increasedSize;
        printArray(values, size, "После увеличения");
    }

    int decreasedSize;
    cout << "\nВведите новый меньший размер: ";
    cin >> decreasedSize;

    if (!cin || decreasedSize < 0 || decreasedSize >= size)
    {
        cout << "Ошибка: на втором шаге размер должен быть от 0 до "
             << size - 1 << "." << endl;
        delete[] values;
        return 1;
    }

    if (resizeArray(values, size, decreasedSize))
    {
        size = decreasedSize;
        printArray(values, size, "После уменьшения");
    }

    cout << "\nОсвобождаю итоговый массив перед выходом." << endl;
    delete[] values;
    values = nullptr;
    cout << "Память освобождена. Программа завершена." << endl;

    return 0;
}
