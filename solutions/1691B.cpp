#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    
    int index = 0;
    while (index < n) {
        int start = index;
        while (index + 1 < n && v[index + 1] == v[start]) index++;
        if (index - start + 1 == 1) {
            cout << "-1" << endl;
            return;
        }
        v[start] = index + 1;
        for (int i = 0; i < index - start; ++i) {
            v[start + i + 1] = start + 1 + i;
        }
        index++;
    }

    for (int i = 0; i < n; ++i) {
        if (i == n - 1) cout << v[i] << endl;
        else cout << v[i] << " ";
    }
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}