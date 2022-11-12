#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];

    // first k
    vector<bool> hasValue(n, false);
    for (int i = 0; i < k; ++i) {
        hasValue[v[i] - 1] = true;
    }
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
        if (hasValue[i] == false) cnt++;
    }
    cout << cnt << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}