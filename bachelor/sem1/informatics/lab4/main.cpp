#include <iostream>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int MAX_SIZE = 100;
    int queue[MAX_SIZE]; // Статический массив для хранения очереди.
    int size = 0;        // Реальное количество элементов в очереди.
    int choice = -1;

    cout << "Очередь на массиве (первый пришёл — первый ушёл)" << endl;

    while (choice != 0)
    {
        cout << "\nМеню:" << endl;
        cout << "1 — добавить элемент" << endl;
        cout << "2 — удалить первый элемент" << endl;
        cout << "3 — показать очередь" << endl;
        cout << "0 — выйти" << endl;
        cout << "Ваш выбор: ";

        // Проверяем, что пользователь ввёл число, а не посторонний символ.
        if (!(cin >> choice))
        {
            cout << "Ошибка: введите номер пункта меню." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1)
        {
            if (size == MAX_SIZE)
            {
                cout << "Очередь заполнена, добавление невозможно." << endl;
                continue;
            }

            int value;
            cout << "Введите целое число: ";
            if (!(cin >> value))
            {
                cout << "Ошибка: элемент должен быть целым числом." << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            // Новый элемент всегда записывается в конец очереди.
            queue[size] = value;
            size++;
            cout << "Элемент " << value << " добавлен." << endl;
        }
        else if (choice == 2)
        {
            if (size == 0)
            {
                cout << "Очередь пуста, удалять нечего." << endl;
                continue;
            }

            int removed = queue[0];

            // Удаляем первый элемент и сдвигаем остальные на одну ячейку влево.
            for (int i = 0; i < size - 1; i++)
                queue[i] = queue[i + 1];

            size--;
            cout << "Удалён элемент " << removed << "." << endl;
        }
        else if (choice == 3)
        {
            // Ниже общий блок вывода покажет текущее состояние очереди.
        }
        else if (choice == 0)
        {
            cout << "Работа программы завершена." << endl;
            continue;
        }
        else
        {
            cout << "Такого пункта меню нет." << endl;
            continue;
        }

        // После добавления, удаления и запроса показываем всю очередь.
        cout << "Текущая очередь (начало -> конец): ";
        if (size == 0)
        {
            cout << "пусто";
        }
        else
        {
            for (int i = 0; i < size; i++)
                cout << queue[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
