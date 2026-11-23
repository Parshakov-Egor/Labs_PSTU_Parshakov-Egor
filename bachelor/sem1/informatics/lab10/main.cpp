// Лабораторная работа № 10, вариант 16.
// Тема: динамические массивы.
// Задание: сформировать динамический массив строк и удалить из него
// самую короткую строку. Если таких строк несколько, удаляется первая.

#include <iostream>  // Для cin, cout и endl.
#include <string>    // Для работы со строками std::string.
#include <clocale>   // Для включения русского языка в консоли.
#include <limits>    // Для очистки потока ввода после чтения числа.
#include <new>       // Для версии new, которая не создаёт исключение.

using namespace std;

// Функция запрашивает количество строк и проверяет ввод.
// Отдельная функция нужна, чтобы не перегружать main одинаковыми проверками.
int readStringCount()
{
    int count;

    cout << "Введите количество строк: ";
    cin >> count;

    // Оператор ! проверяет, удалось ли прочитать целое число.
    // Количество не может быть равно нулю, потому что тогда искать
    // самую короткую строку было бы не среди чего.
    if (!cin || count <= 0)
    {
        cout << "Ошибка: нужно ввести целое положительное число." << endl;
        return 0;
    }

    // После cin >> count в потоке остаётся символ перехода на новую строку.
    // Если его не удалить, первый getline прочитает пустую строку.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Количество строк принято: " << count << "." << endl;
    return count;
}

// Функция формирует динамический массив строк.
// Возвращаемый указатель будет хранить адрес первого элемента массива.
string* createStringArray(int count)
{
    cout << "\nВыделяю память для " << count << " строк..." << endl;

    // new[] выделяет память сразу для всего массива.
    // nothrow позволяет получить nullptr при ошибке вместо исключения.
    string* lines = new (nothrow) string[count];

    if (lines == nullptr)
    {
        cout << "Ошибка: не удалось выделить память для массива." << endl;
        return nullptr;
    }

    cout << "Память успешно выделена. Теперь заполните массив." << endl;
    cout << "Пустая строка тоже допускается: её длина равна нулю." << endl;

    // Каждый элемент массива — самостоятельный объект string.
    for (int i = 0; i < count; i++)
    {
        cout << "Строка № " << i + 1 << ": ";
        getline(cin, lines[i]);

        // length() возвращает количество символов, хранящихся в строке.
        // Это значение потом используется для поиска минимума.
        cout << "  Сохранено. Длина строки: " << lines[i].length() << "." << endl;
    }

    cout << "Формирование динамического массива завершено." << endl;
    return lines;
}

// Функция только выводит массив, поэтому изменять его не требуется.
// Заголовок помогает понять, какая версия массива сейчас отображается.
void printStringArray(const string* lines, int count, const string& title)
{
    cout << "\n" << title << endl;
    cout << "Текущее количество элементов: " << count << "." << endl;

    if (lines == nullptr || count == 0)
    {
        cout << "Массив пуст." << endl;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "  [" << i << "] ";

        // Пустую строку показываем специальной подписью, иначе на экране
        // после номера элемента казалось бы, что строки вообще нет.
        if (lines[i].empty())
            cout << "<пустая строка>";
        else
            cout << '"' << lines[i] << '"';

        cout << " — длина " << lines[i].length() << endl;
    }
}

// Функция возвращает индекс первой самой короткой строки.
// Массив при этом не меняется: выполняется только поиск.
int findShortestString(const string* lines, int count)
{
    // В начале считаем первый элемент самым коротким.
    int shortestIndex = 0;

    cout << "\nНачинаю поиск самой короткой строки." << endl;
    cout << "Стартовый минимум: элемент № 0, длина "
         << lines[0].length() << "." << endl;

    // Первый элемент уже рассмотрен, поэтому цикл начинается со второго.
    for (int i = 1; i < count; i++)
    {
        cout << "Сравниваю элемент № " << i
             << " (длина " << lines[i].length()
             << ") с текущим минимумом " << lines[shortestIndex].length()
             << "." << endl;

        // Строгий знак < означает, что при одинаковых длинах сохраняется
        // индекс первой найденной строки, а не последней.
        if (lines[i].length() < lines[shortestIndex].length())
        {
            shortestIndex = i;
            cout << "  Найден новый минимум! Его индекс: "
                 << shortestIndex << "." << endl;
        }
    }

    cout << "Поиск завершён. Индекс самой короткой строки: "
         << shortestIndex << "." << endl;
    return shortestIndex;
}

// Функция удаляет самую короткую строку из динамического массива.
// Указатель и размер передаются по ссылкам, потому что после удаления
// изменятся и адрес массива, и количество его элементов.
bool removeShortestString(string*& lines, int& count)
{
    if (lines == nullptr || count <= 0)
    {
        cout << "Удаление невозможно: массив пуст." << endl;
        return false;
    }

    int shortestIndex = findShortestString(lines, count);

    cout << "\nУдаляется строка с индексом " << shortestIndex << ": \""
         << lines[shortestIndex] << "\"." << endl;

    int newCount = count - 1;
    string* newLines = nullptr;

    // Если в массиве была одна строка, новый массив выделять не нужно.
    if (newCount > 0)
    {
        cout << "Выделяю память для нового массива из "
             << newCount << " элементов." << endl;

        newLines = new (nothrow) string[newCount];

        if (newLines == nullptr)
        {
            cout << "Ошибка выделения памяти. Исходный массив не изменён." << endl;
            return false;
        }

        // Копируем все элементы, кроме выбранного для удаления.
        int newIndex = 0;

        for (int oldIndex = 0; oldIndex < count; oldIndex++)
        {
            if (oldIndex == shortestIndex)
            {
                cout << "  Элемент № " << oldIndex
                     << " пропущен — именно его нужно удалить." << endl;
                continue;
            }

            newLines[newIndex] = lines[oldIndex];
            cout << "  Скопирована строка № " << oldIndex
                 << " в позицию № " << newIndex << " нового массива." << endl;
            newIndex++;
        }
    }
    else
    {
        cout << "Это была единственная строка. Новый массив будет пустым." << endl;
    }

    // Старый массив больше не нужен: его память обязательно освобождаем.
    delete[] lines;

    // Теперь старый указатель получает адрес нового массива.
    lines = newLines;
    count = newCount;

    cout << "Старая память освобождена. Новый размер массива: "
         << count << "." << endl;
    return true;
}

// Отдельная функция освобождения памяти используется перед завершением main.
void deleteStringArray(string*& lines, int& count)
{
    cout << "\nЗавершаю работу и освобождаю память массива." << endl;

    // delete[] безопасен для nullptr, поэтому дополнительная проверка
    // не обязательна, но сообщение делает работу программы понятнее.
    if (lines == nullptr)
        cout << "Динамическая память уже не занята." << endl;
    else
        cout << "Удаляю массив из " << count << " элементов." << endl;

    delete[] lines;
    lines = nullptr;
    count = 0;

    cout << "Память освобождена, указатель обнулён." << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Лабораторная работа № 10. Вариант 16." << endl;
    cout << "Динамический массив строк: удаление самой короткой строки." << endl;
    cout << "-----------------------------------------------------------" << endl;

    int count = readStringCount();

    // При ошибке ввода динамическая память ещё не выделялась,
    // поэтому можно сразу завершить программу.
    if (count == 0)
        return 1;

    string* lines = createStringArray(count);

    if (lines == nullptr)
        return 1;

    printStringArray(lines, count, "Исходный массив строк:");

    // Результат проверяем: при нехватке памяти старый массив останется
    // в исходном состоянии, и его всё равно нужно будет удалить.
    if (removeShortestString(lines, count))
        printStringArray(lines, count, "Массив после удаления самой короткой строки:");
    else
        cout << "Преобразование не выполнено." << endl;

    deleteStringArray(lines, count);

    cout << "\nПрограмма успешно завершена." << endl;
    return 0;
}
