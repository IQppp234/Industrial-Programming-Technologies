// Решение циклом while:
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100][100];

    // заполняем массив
    int i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            if (i + j < n - 1) {
                a[i][j] = 0;
            }
            else if (i + j == n - 1) {
                a[i][j] = 1;
            }
            else {
                a[i][j] = 2;
            }
            j++;
        }
        i++;
    }

    // выводим
    i = 0;
    while (i < n) {
        int j = 0;
        while (j < n) {
            cout << a[i][j];
            if (j != n - 1) {
                cout << " ";
            }
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}
