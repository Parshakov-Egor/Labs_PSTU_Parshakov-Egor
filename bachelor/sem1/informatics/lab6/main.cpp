#define _CRT_SECURE_NO_WARNINGS // Разрешаем стандартные функции C в Visual Studio.

#include <iostream>
#include <cstring>
#include <clocale>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    const int MAX_WORDS = 100;
    const int WORD_SIZE = 51;

    char text[501];
    char words[MAX_WORDS][WORD_SIZE]; // Слова без повторений.
    int counts[MAX_WORDS] = { 0 };    // Количество вхождений каждого слова.
    int uniqueCount = 0;

    cout << "Введите строку (до 500 символов):" << endl;
    cin.getline(text, 501);

    // Разбиваем строку на слова. Знаки препинания считаются разделителями.
    char* word = strtok(text, " \t.,!?;:-_()[]{}\"'\r\n");

    while (word != nullptr)
    {
        int foundIndex = -1;

        // Проверяем, встречалось ли это слово раньше.
        for (int i = 0; i < uniqueCount; i++)
        {
            if (strcmp(words[i], word) == 0)
            {
                foundIndex = i;
                break;
            }
        }

        if (foundIndex != -1)
        {
            counts[foundIndex]++;
        }
        else if (uniqueCount < MAX_WORDS)
        {
            // Копируем новое слово и ограничиваем его длину размером массива.
            strncpy(words[uniqueCount], word, WORD_SIZE - 1);
            words[uniqueCount][WORD_SIZE - 1] = '\0';
            counts[uniqueCount] = 1;
            uniqueCount++;
        }

        word = strtok(nullptr, " \t.,!?;:-_()[]{}\"'\r\n");
    }

    cout << "\nСлова, которые встречаются ровно один раз:" << endl;
    bool found = false;

    for (int i = 0; i < uniqueCount; i++)
    {
        if (counts[i] == 1)
        {
            cout << words[i] << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Таких слов нет." << endl;

    return 0;
}
