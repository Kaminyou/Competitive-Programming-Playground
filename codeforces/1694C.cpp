#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    // find the last element
    int last = n - 1;
    
    while (last > 0 && v[last] == 0) last--;
    long long sum = 0;
    for (int i = 0; i < last; i++) {
        sum += v[i];
        if (sum <= 0) {
            cout << "NO" << endl;
            return;
        }
    }
    sum += v[last];
    if (sum != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}