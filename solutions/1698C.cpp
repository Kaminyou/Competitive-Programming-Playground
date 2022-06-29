#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    if (n == 3) {
        long long sum = 0;
        bool flag = false;
        for (int i = 0; i < n; ++i) sum += v[i];
        for (int i = 0; i < n; ++i) {
            if (sum == (long long)v[i]) flag = true;
        }
        if (flag) {
            cout << "YES" << endl;
            return;
        }
        else cout << "NO" << endl;
    }
    else if (n == 4) {
        long long sum = 0;
        for (auto& num : v) sum += num;
        for (int i = 0; i < n; ++i) {
            long long target = sum - v[i];
            bool flag = false;
            for (int i = 0; i < n; ++i) {
                if (v[i] == target) flag = true;
            }
            if (!flag) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
        return;
    }
    else {
        int countZero = 0;
        long long sum = 0; 
        for (int i = 0; i < n; ++i) {
            if (v[i] == 0) countZero++;
            sum += v[i];
        }
        if ((countZero == n - 2) && (sum != 0)) {
            cout << "NO" << endl;
            return;
        }
        if (countZero < n - 2) {
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;

    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}