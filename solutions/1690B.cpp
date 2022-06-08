#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v1(n, 0);
    vector<int> v2(n, 0);
    for (int i = 0; i < n; ++i) cin >> v1[i];
    for (int i = 0; i < n; ++i) cin >> v2[i];
    
    int diff = 0;
    for (int i = 0; i < n; ++i) {
        if (v1[i] - v2[i] < 0) {
            cout << "NO" << endl;
            return;
        }
        diff = max(diff, v1[i] - v2[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (v1[i] - v2[i] < diff && v2[i] != 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}