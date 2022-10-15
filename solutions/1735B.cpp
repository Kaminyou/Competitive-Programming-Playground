#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (v.size() == 1) {
        cout << 0 << endl;
        return;
    }
    if (v[0] == 1) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i] > 1) res += (v[i] - 1);
        }
        cout << res << endl;
        return;
    }
    int minVal = v[0];
    int criteria = v[0] * 2;
    int divide = criteria - 1;
    int res = 0;
    for (int i = 1; i < n; ++i) {
        if (v[i] >= criteria) {
            int multi = v[i] / divide;
            int remain = v[i] - multi * divide;
            if (remain > 0) multi++;
            res += (multi - 1);
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}