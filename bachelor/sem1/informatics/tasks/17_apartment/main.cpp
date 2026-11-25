#include <iostream>
#include <string>
using namespace std;

// Структура, описывающая одну квартиру
struct Apartment
{
    int price;      // стоимость квартиры
    int floor;      // на каком этаже находится
    double size;    // метраж (площадь)
    string street;  // адрес: улица и дом
};

int main()
{
    Apartment v[3]; // массив из трёх квартир

    //  Ввод данных о квартирах 
    for (int i = 0; i < 3; i++)
    {
        cout << "=== Заполнение карточки квартиры № " << i + 1 << " ===" << endl;
        cout << "Введите стоимость квартиры: ";
        cin >> v[i].price;

        cout << "Введите номер этажа: ";
        cin >> v[i].floor;

        cout << "Введите площадь (в кв. метрах): ";
        cin >> v[i].size;

        cout << "Введите адрес (улица и дом): ";
        cin >> ws;                  // убираем лишние пробелы и перевод строки
        getline(cin, v[i].street);  // читаем адрес как строку целиком

        cout << "Карточка квартиры № " << i + 1 << " успешно сохранена." << endl;
        cout << endl;
    }

    //  Запрос цены для поиска 
    int target_price;
    cout << "Какую стоимость квартиры вы хотели бы найти? ";
    cin >> target_price;

    //  Поиск подходящих квартир 
    bool found = false; // признак: нашлась ли хотя бы одна квартира
    int count = 0;      // сколько квартир подошло

    for (int i = 0; i < 3; i++)
    {
        if (target_price == v[i].price) // проверяем совпадение цены
        {
            count++;
            cout << "\n--- Найдена подходящая квартира № " << count << " ---" << endl;
            cout << "Стоимость: " << v[i].price << " руб." << endl;
            cout << "Этаж: " << v[i].floor << endl;
            cout << "Площадь: " << v[i].size << " кв. м" << endl;
            cout << "Адрес: " << v[i].street << endl;
            found = true; // запоминаем, что совпадение было
        }
    }

    //  Итог поиска 
    if (found)
    {
        cout << "\nВсего подходящих квартир: " << count << endl;
    }
    else
    {
        cout << "\nК сожалению, квартир с указанной стоимостью не обнаружено." << endl;
    }

    return 0;
}