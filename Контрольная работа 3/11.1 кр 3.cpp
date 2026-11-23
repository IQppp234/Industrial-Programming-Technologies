#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    if (!(cin >> n >> m)) return 0;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(m, -1000000000));
    vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, {-1, -1}));

    dp[0][0] = grid[0][0];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0) continue;
            
            if (i > 0 && dp[i - 1][j] + grid[i][j] > dp[i][j]) {
                dp[i][j] = dp[i - 1][j] + grid[i][j];
                p[i][j] = {i - 1, j};
            }
            if (j > 0 && dp[i][j - 1] + grid[i][j] > dp[i][j]) {
                dp[i][j] = dp[i][j - 1] + grid[i][j];
                p[i][j] = {i, j - 1};
            }
        }
    }

    vector<pair<int, int>> path;
    int curr_i = n - 1, curr_j = m - 1;
    
    while (curr_i != -1 && curr_j != -1) {
        path.push_back({curr_i, curr_j});
        pair<int, int> prev = p[curr_i][curr_j];
        curr_i = prev.first;
        curr_j = prev.second;
    }

    reverse(path.begin(), path.end());

    for (int i = 0; i < path.size(); ++i) {
        cout << path[i].first << " " << path[i].second << "\n";
    }

    return 0;
}
