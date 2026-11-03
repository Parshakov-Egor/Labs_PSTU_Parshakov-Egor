#include <iostream>

using namespace std;

int main() {
    const int MAX_SIZE = 100;
    int queue[MAX_SIZE];
    int size = 0;

    int choice = -1;

    cout << "=== Лабораторная работа 4. Вариант 16 ===" << endl;
    cout << "=== Очередь на базе одномерного массива (FIFO) ===" << endl;

    while (choice != 0) {
        cout << "\nВыберите действие:" << endl;
        cout << "1 - Добавить элемент в очередь" << endl;
        cout << "2 - Удалить элемент из очереди" << endl;
        cout << "3 - Показать текущую очередь" << endl;
        cout << "0 - Выход" << endl;
        cout << "Ваш выбор: ";
        
        if (!(cin >> choice)) {
            break;
        }

        if (choice == 1) {
            if (size >= MAX_SIZE) {
                cout << "Ошибка: очередь заполнена (максимум " << MAX_SIZE << " элементов)!" << endl;
            } else {
                int value;
                cout << "Введите число: ";
                cin >> value;

                queue[size] = value;
                size++;

                cout << "Элемент " << value << " добавлен в очередь." << endl;

                cout << "Состояние массива (длина = " << size << "): ";
                for (int i = 0; i < size; i++) {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 2) {
            if (size == 0) {
                cout << "Ошибка: очередь пуста, удалять нечего!" << endl;
            } else {
                int removed = queue[0];

                for (int i = 0; i < size - 1; i++) {
                    queue[i] = queue[i + 1];
                }
                size--;

                cout << "Элемент " << removed << " удален из очереди." << endl;

                if (size == 0) {
                    cout << "Очередь теперь пуста." << endl;
                } else {
                    cout << "Состояние массива (длина = " << size << "): ";
                    for (int i = 0; i < size; i++) {
                        cout << queue[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
        else if (choice == 3) {
            if (size == 0) {
                cout << "Очередь пуста." << endl;
            } else {
                cout << "Состояние массива (длина = " << size << "): ";
                for (int i = 0; i < size; i++) {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }
        }
        else if (choice == 0) {
            cout << "Завершение программы." << endl;
        }
        else {
            cout << "Неверный выбор, попробуйте снова." << endl;
        }
    }

    return 0;
}
