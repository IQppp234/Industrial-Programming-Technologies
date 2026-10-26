#include <iostream>
using namespace std;

int main() {
    int n, m, w;
    cin >> n >> m >> w;

    // поле с запасом по краям, чтобы не проверять выход за границы
    int field[34][34] = {0};
    bool grib[34][34] = {false};

    for (int k = 0; k < w; k++) {
        int x, y;
        cin >> x >> y;
        grib[x][y] = true;
    }

    // для каждой клетки считаем грибы вокруг
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int count = 0;
            for (int di = -1; di <= 1; di++) {
                for (int dj = -1; dj <= 1; dj++) {
                    if (di == 0 && dj == 0) {
                        continue;
                    }
                    if (grib[i + di][j + dj]) {
                        count++;
                    }
                }
            }
            field[i][j] = count;
        }
    }

    // вывод без пробелов
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grib[i][j]) {
                cout << "*";
            }
            else {
                cout << field[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
