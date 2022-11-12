#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> position(n, 0);
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        position[temp] = i;
    }
    long long res = 1;
    long long mod = 1e9 + 7;
    int left, right;
    left = right = position[0];
    for (int i = 1; i < n; ++i) {
        if (position[i] < left) left = position[i];
        else if (position[i] > right) right = position[i];
        else {
            res *= (right - left + 1 - i);
            res %= mod;
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}