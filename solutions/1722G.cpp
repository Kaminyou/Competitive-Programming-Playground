#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int cum = 0;
    for (int i = 1; i <= n - 3; ++i) {
        cout << i << " ";
        cum ^= i;
    }
    cout << (1 << 29) << " ";
    cum ^= (1 << 29);
    cout << (1 << 30) << " ";
    cum ^= (1 << 30);
    cout << cum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}