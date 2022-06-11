#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        int num;
        cin >> num;
        cout << "-1" << endl;
        return;
    }
    vector<int> v(n, 0);
    vector<int> results(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        results[i] = i + 1;
    }
    
    for (int i = 0; i < n - 1; ++i) {
        if (v[i] == results[i]) swap(results[i], results[i + 1]);
    }

    if (v[n - 1] == results[n - 1]) swap(results[n - 1], results[n - 2]);

    for (int i = 0; i < n; ++i) {
        cout << results[i] << " ";
    }
    cout << endl;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}