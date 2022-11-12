#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int nn = n * 2;
    vector<int> heights(nn, 0);
    for (int i = 0; i < nn; ++i) cin >> heights[i];
    sort(heights.begin(), heights.end());
    for (int i = 0; i < n; ++i) {
        if (heights[i + n] - heights[i] < x) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}