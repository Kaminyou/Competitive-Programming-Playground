#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> res(n, 0);
    for (int i = 0; i < n; ++i) {
        res[i] = i + 1;
    }
    // odd
    if (n & 1) {
        for (int i = 1; i < n; i += 2) {
            swap(res[i], res[i + 1]);
        }
    }
    else {
        for (int i = 0; i < n; i += 2) {
            swap(res[i], res[i + 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}