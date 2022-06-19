#include <iostream>
#include <climits>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int curr;
    int maxVal = INT_MIN;
    int x, y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> curr;
            if (curr > maxVal) {
                maxVal = curr;
                x = i;
                y = j;
            }
        }
    }
    long long xLen = max(x + 1, n - x);
    long long yLen = max(y + 1, m - y);
    cout << xLen * yLen << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}