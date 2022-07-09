#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> res(n, 0);
    int index = 0;
    for (int start = 1; start <= n; start += 2) {
        for (int i = 0; start * (1 << i) <= n; ++i) {
            res[index] = start * (1 << i);
            index++;
        }
    }
    cout << 2 << endl;
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}