#define _CRT_SECURE_NO_WARNINGS // Разрешаем стандартную функцию sscanf в Visual Studio.

#include <iostream>
#include <cstdarg>
#include <cstdio>
#include <clocale>

using namespace std;

// Проверка високосного года по григорианскому календарю.
bool isLeapYear(int year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int daysInMonth(int month, int year)
{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (month == 2 && isLeapYear(year))
        return 29;

    return days[month - 1];
}

// Разбирает дату вида дд.мм.гг и проверяет её корректность.
bool parseDate(const char* text, int& day, int& month, int& year)
{
    if (sscanf(text, "%d.%d.%d", &day, &month, &year) != 3)
        return false;

    if (year < 100)
        year += 2000; // В задании год записан двумя цифрами.

    if (year < 1 || month < 1 || month > 12 || day < 1)
        return false;

    return day <= daysInMonth(month, year);
}

// Переводит дату в порядковый номер дня, чтобы разность дат была простым вычитанием.
long dateToSerial(int day, int month, int year)
{
    long result = 0;

    for (int y = 1; y < year; y++)
        result += isLeapYear(y) ? 366 : 365;

    for (int m = 1; m < month; m++)
        result += daysInMonth(m, year);

    return result + day;
}

// Получает несколько дат и выводит расстояние между каждой соседней парой.
// Первый параметр count задаёт количество строк-дат после него.
void days(int count, ...)
{
    if (count < 2)
    {
        cout << "Для вычисления интервала нужно хотя бы две даты." << endl;
        return;
    }

    va_list arguments;
    va_start(arguments, count);

    const char* previous = va_arg(arguments, const char*);

    for (int i = 1; i < count; i++)
    {
        const char* current = va_arg(arguments, const char*);
        int day1, month1, year1;
        int day2, month2, year2;

        if (!parseDate(previous, day1, month1, year1) ||
            !parseDate(current, day2, month2, year2))
        {
            cout << previous << " — " << current << ": ошибка в дате" << endl;
        }
        else
        {
            long difference = dateToSerial(day2, month2, year2) -
                              dateToSerial(day1, month1, year1);

            if (difference < 0)
                difference = -difference;

            cout << previous << " — " << current << ": "
                 << difference << " дн." << endl;
        }

        previous = current;
    }

    va_end(arguments);
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Три даты:" << endl;
    days(3, "01.01.26", "10.01.26", "20.01.26");

    cout << "\nПять дат (есть переход через 29 февраля):" << endl;
    days(5, "28.02.24", "01.03.24", "01.03.25", "01.03.26", "01.01.27");

    cout << "\nВосемь дат:" << endl;
    days(8, "01.01.26", "02.01.26", "03.01.26", "04.01.26",
            "05.01.26", "06.01.26", "07.01.26", "08.01.26");

    return 0;
}
