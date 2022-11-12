#include <iostream>
using namespace std;

void solve() {
    int a, b, c ,d;
    cin >> a >> b >> c >> d;
    if (a == 1 && b == 1 && c == 1 && d == 1) {
        cout << 2 << endl;
        return;
    }
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}