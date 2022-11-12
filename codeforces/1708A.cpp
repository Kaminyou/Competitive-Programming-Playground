#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int base = v[0];
    bool flag = false;
    for (int i = 1; i < n; ++i) {
        if (flag) {
            if (v[i] != 0) {
                cout << "NO" << endl;
                return;
            }
        }
        if (v[i] == 0) {
            flag = true;
            continue;
        }
        if (v[i] % base != 0) {
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