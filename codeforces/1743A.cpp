#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int temp;
    for (int i = 0; i < n; ++i) cin >> temp;
    int cnt = (10 - n) * (9 - n) / 2 * 6;
    cout << cnt << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}