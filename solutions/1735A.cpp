#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int res = (n - 6) / 3;
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}