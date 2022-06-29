#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    if (k == 1) {
        int ans = (n - 1) / 2;
        cout << ans << endl;
    }
    else {
        int ans = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (v[i] > v[i - 1] + v[i + 1]) ans++;
        }
        cout << ans << endl;
    }

}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}