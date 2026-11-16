#include <iostream>
#include <string>
#include <set>
#include <sstream>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    // Приводим к нижнему регистру и заменяем знаки препинания на пробелы
    string cleaned;
    for (char c : line) {
        unsigned char uc = (unsigned char)c;
        if (isalpha(uc) || isdigit(uc)) {
            cleaned += tolower(uc);
        } else {
            cleaned += ' ';
        }
    }

    // Извлекаем слова, сохраняя порядок первого появления
    set<string> seen;
    istringstream iss(cleaned);
    string word;
    while (iss >> word) {
        if (seen.insert(word).second) {
            cout << word << endl;
        }
    }

    return 0;
}