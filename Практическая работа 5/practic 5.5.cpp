// 5 задание
#include <iostream>

using namespace std;

int main() {
    int A, B;
    if (!(cin >> A >> B)) return 0;

    for (;;) {
        // Условие выхода из цикла
        if (A <= B) {
            break;
        }

        if (A % 2 == 0 && A / 2 >= B) {
            cout << ":2\n";
            A /= 2;
        } else {
            cout << "-1\n";
            A -= 1;
        }
    }

    return 0;
}
