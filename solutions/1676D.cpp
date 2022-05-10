#include <iostream>
#include <vector>
using namespace std;

void solve(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int dim = m + n - 1;
    vector<int> diagonals(dim, 0);
    vector<int> antidiagonals(dim, 0);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int diagonal = j - i + m - 1;
            int antidiagonal = i + j;
            diagonals[diagonal] += grid[i][j];
            antidiagonals[antidiagonal] += grid[i][j];
        }
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int diagonal = j - i + m - 1;
            int antidiagonal = i + j;
            res = max(res, diagonals[diagonal] + antidiagonals[antidiagonal] - grid[i][j]);
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int m, n;
        cin >> m;
        cin >> n;
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        solve(grid);
    }
    return 0;
}