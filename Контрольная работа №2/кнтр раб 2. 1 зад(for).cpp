// Решение 1 задачи циклом for:
#include <iostream>
using namespace std;

// Функция быстрого возведения в степень
long long fast_pow(long long a, long long n) {
    long long res = 1;
    
    // Начальное условие пропущено (n уже есть).
    // Условие работы: пока n > 0.
    // Действие после каждой итерации: n = n / 2.
    for (; n > 0; n = n / 2) {
        if (n % 2 == 1) { // Если степень нечетная
            res = res * a;
        }
        a = a * a;
    }
    
    return res;
}

int main() {
    long long a, n;
    // Ввод основания и степени
    cin >> a >> n;
    cout << fast_pow(a, n) << endl;
    return 0;
}
