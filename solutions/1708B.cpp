#include <iostream>
#include <vector>
using namespace std;

void solve() {
    long long n, l, r;
    cin >> n >> l >> r;
    vector<int> res(n, 0);
    for (int i = 1; i <= n; ++i) {
        long long multi = l / i;
        long long mod = l % i;
        if (mod == 0) {
            res[i - 1] = l;
            continue;
        }
        multi++;
        if (multi * i > r) {
            cout << "NO" << endl;
            return;
        }
        res[i - 1] = multi * i;
    }
    cout << "YES" << endl;
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