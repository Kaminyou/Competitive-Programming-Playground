#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    cout << "1 ";
    cout << n << " ";
    for (int i = 2; i < n; ++i) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}