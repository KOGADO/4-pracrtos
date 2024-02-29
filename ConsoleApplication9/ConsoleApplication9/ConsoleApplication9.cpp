#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <Windows.h>
using namespace std;
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    wstring word = L"";
    int choice;

    wcout << L"Введите слово: ";
    wcin >> word;

    wcout << L"Выберите действие:" << endl;
    wcout << L"1. Вывести слово задом наперед" << endl;
    wcout << L"2. Вывести слово без гласных букв" << endl;
    wcout << L"3. Вывести слово без согласных букв" << endl;
    wcout << L"4. Рандомно вывести буквы данного слова" << endl;
    cin >> choice;

    if (choice == 1) {
        reverse(word.begin(), word.end());
    }
    else if (choice == 2) {
        word.erase(remove_if(word.begin(), word.end(), [](wchar_t c) { return wstring(L"ауоиэыяюеёАУОИЭЫЯЮЕЁ").find(c) != wstring::npos; }), word.end());
    }
    else if (choice == 3) {
        word.erase(remove_if(word.begin(), word.end(), [](wchar_t c) { return wstring(L"бвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ").find(c) != wstring::npos; }), word.end());
    }
    else if (choice == 4) {
        random_device rd;
        mt19937 g(rd());
        shuffle(word.begin(), word.end(), g);
    }
    else {
        cout << "Некорректный выбор.";
        return 0;
    }

    wcout << L"Результат: " << word;

    return 0;
}