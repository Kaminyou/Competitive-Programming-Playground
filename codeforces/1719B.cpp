Mathematical Circus#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k % 4 == 0) {
        cout << "NO" << endl;
        return;
    }
    if (k & 1) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i += 2) {
            cout << i << " " << i + 1 << endl;
        }
        return;
    }
    else {
        cout << "YES" << endl;
        for (int i = 2; i <= n; i += 4) {
            cout << i << " " << i - 1 << endl;
        }
        for (int i = 4; i <= n; i += 4) {
            cout << i - 1 << " " << i << endl;
        }
        return;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}