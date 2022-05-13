#include <iostream>
#include <vector>
using namespace std;

void solve(const vector<string>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int boxUp = INT_MAX;
    int boxLeft = INT_MAX;
    int position = INT_MAX;
    int posUp = -1;
    int posLeft = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'R') {
                boxUp = min(boxUp, i);
                boxLeft = min(boxLeft, j);
                if (i + j < position) {
                    position = i + j;
                    posUp = i;
                    posLeft = j;
                }
            }
        }
    }
    if (boxUp - posUp < 0 || boxLeft - posLeft < 0) cout << "NO" << endl;
    else cout << "YES" << endl;

}

int main() {
    int T;
    int m, n;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> m;
        cin >> n;
        vector<string> v(m);
        for (int i = 0; i < m; i++) {
            cin >> v[i];
        }
        solve(v);
    }
    return 0;
}