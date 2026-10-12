#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Символ 1 ('C'): вывод имени и фамилии студента на английском языке
void printStudentInfo() {
    // Укажи здесь свои имя и фамилию на латинице
    cout << "Balbashov Sergey" << endl;
}

// Символ 2 ('r'): поиск корней многочлена ax^2 + bx + c = 0 с учетом всех краевых случаев
void solveEquation(double a, double b, double c) {
    // Проверка случая a = 0 (многочлен вырождается и перестает быть квадратным)
    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {
                // Если a=0, b=0, c=0, то корень — любое действительное число
                cout << "Корень - любое действительное число" << endl;
            } else {
                // Уравнение вида c = 0 при ненулевом c не имеет решений
                cout << "Корней нет" << endl;
            }
        } else {
            // Линейное уравнение вида bx + c = 0 => x = -c / b
            double x = -c / b;
            cout << "Один корень (линейное уравнение): x = " << x << endl;
        }
    } else {
        // Полноценное квадратное уравнение: вычисляем дискриминант
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0.0) {
            // Два действительных корня
            double x1 = (-b + sqrt(discriminant)) / (2 * a);
            double x2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "Два корня: x1 = " << x1 << ", x2 = " << x2 << endl;
        } else if (discriminant == 0.0) {
            // Один корень кратности 2
            double x = -b / (2 * a);
            cout << "Один корень: x = " << x << endl;
        } else {
            // Дискриминант отрицательный — действительных корней нет
            cout << "Действительных корней нет" << endl;
        }
    }
}

// Символ 3 ('s'): запрос целого числа и проверка его делимости на 3 без остатка
void checkDivisibilityByThree() {
    int number;
    cout << "Введите целое число: ";
    cin >> number;

    // Проверяем остаток от деления числа на 3
    if (number % 3 == 0) {
        cout << "Число " << number << " делится на 3 без остатка" << endl;
    } else {
        cout << "Число " << number << " не делится на 3 без остатка" << endl;
    }
}

int main() {
    // Считывание коэффициентов квадратного многочлена ax^2 + bx + c
    double a, b, c;
    cout << "Введите коэффициенты a, b, c: ";
    cin >> a >> b >> c;

    // Считывание управляющего символа в следующей строке
    char command;
    cout << "Введите символ (C, r, s): ";
    cin >> command;

    // Выбор действия в зависимости от переданного символа по Варианту 3
    switch (command) {
        case 'C':
            printStudentInfo();
            break;
        case 'r':
            solveEquation(a, b, c);
            break;
        case 's':
            checkDivisibilityByThree();
            break;
        default:
            cout << "Неизвестный символ" << endl;
            break;
    }

    return 0;
}