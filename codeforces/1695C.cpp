#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    vector<vector<int>> dpMax(n, vector<int>(m, 0));
    vector<vector<int>> dpMin(n, vector<int>(m, 0));
    int temp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> temp;
            grid[i][j] = (temp == 1 ? true : false);
        }
    }
    if ((n + m - 1) & 1) {
        cout << "NO" << endl;
        return;
    }
    dpMax[0][0] = (grid[0][0] ? 1 : -1);
    dpMin[0][0] = (grid[0][0] ? 1 : -1);
    for (int i = 1; i < n; ++i) {
        dpMax[i][0] = dpMax[i - 1][0] + (grid[i][0] ? 1 : -1);
        dpMin[i][0] = dpMin[i - 1][0] + (grid[i][0] ? 1 : -1);
    }
    for (int j = 1; j < m; ++j) {
        dpMax[0][j] = dpMax[0][j - 1] + (grid[0][j] ? 1 : -1);
        dpMin[0][j] = dpMin[0][j - 1] + (grid[0][j] ? 1 : -1);
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            dpMax[i][j] = max(dpMax[i - 1][j], dpMax[i][j - 1]) + (grid[i][j] ? 1 : -1);
            dpMin[i][j] = min(dpMin[i - 1][j], dpMin[i][j - 1]) + (grid[i][j] ? 1 : -1);
        }
    }
    int maxPath = dpMax[n - 1][m - 1];
    int minPath = dpMin[n - 1][m - 1];
    if (maxPath < 0 || minPath > 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}