#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m;
int max_pdfs = -1;
vector<string> maze;
vector<vector<bool>> visited;

void solve(int x, int y, int pdfs) {
    if (x < 0 || x >= n || y < 0 || y >= m || maze[x][y] == '1' || visited[x][y]) {
        return;
    }

    if (maze[x][y] == 'E') {
        if (pdfs > max_pdfs) {
            max_pdfs = pdfs;
        }
        return;
    }

    visited[x][y] = true;
    
    int collected = 0;
    if (maze[x][y] == 'P') {
        collected = 1;
    }

    solve(x + 1, y, pdfs + collected);
    solve(x - 1, y, pdfs + collected);
    solve(x, y + 1, pdfs + collected);
    solve(x, y - 1, pdfs + collected);

    visited[x][y] = false;
}

int main() {
    if (!(cin >> n >> m)) return 0;
    
    maze.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> maze[i];
    }

    visited.assign(n, vector<bool>(m, false));
    
    int start_x = 0;
    int start_y = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maze[i][j] == 'S') {
                start_x = i;
                start_y = j;
            }
        }
    }

    solve(start_x, start_y, 0);

    if (max_pdfs == -1) {
        cout << 0 << "\n";
    } else {
        cout << max_pdfs << "\n";
    }

    return 0;
}
