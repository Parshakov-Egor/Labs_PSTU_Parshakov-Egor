#include <iostream>
#include <clocale>

using namespace std;

// Первая версия функции: часы и минуты переводит в общее число минут.
int convertTime(int hours, int minutes)
{
    return hours * 60 + minutes;
}

// Вторая версия функции: общее число минут переводит обратно в часы и минуты.
// Результат возвращается через ссылки hours и minutes.
void convertTime(int totalMinutes, int& hours, int& minutes)
{
    hours = totalMinutes / 60;
    minutes = totalMinutes % 60;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int hours, minutes;
    cout << "Введите часы и минуты через пробел: ";
    if (!(cin >> hours >> minutes) || hours < 0 || minutes < 0 || minutes >= 60)
    {
        cout << "Ошибка: часы должны быть неотрицательными, минуты — от 0 до 59." << endl;
        return 1;
    }

    // Компилятор выбирает первую функцию, потому что передано два значения int.
    int totalMinutes = convertTime(hours, minutes);
    cout << "Общее количество минут: " << totalMinutes << endl;

    int restoredHours, restoredMinutes;

    // Здесь выбирается вторая функция: у неё три параметра, два из них — ссылки.
    convertTime(totalMinutes, restoredHours, restoredMinutes);
    cout << "Обратное преобразование: " << restoredHours << " ч "
         << restoredMinutes << " мин" << endl;

    return 0;
}
