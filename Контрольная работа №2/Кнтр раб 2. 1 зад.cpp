// Решение 1 задачи циклом while:
#include <iostream>
using namespace std;

// Функция быстрого возведения в степень
long long fast_pow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n % 2 == 1) { // Если степень нечетная
            res = res * a;
        }
        a = a * a;
        n = n / 2;
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
