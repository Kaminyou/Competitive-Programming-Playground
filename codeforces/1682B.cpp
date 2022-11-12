#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int res = (1 << 20) - 1;
    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x != i) {
            res &= x;
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}