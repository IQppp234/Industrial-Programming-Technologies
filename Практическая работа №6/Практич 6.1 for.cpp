// Решение циклом for:
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100][100];

    // заполняем массив
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j < n - 1) {
                a[i][j] = 0;
            }
            else if (i + j == n - 1) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 2;
            }
        }
    }

    // выводим
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            if (j != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
