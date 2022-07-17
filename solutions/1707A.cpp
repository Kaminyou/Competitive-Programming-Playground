#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;



void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> tests(n, 0);
    for (int i = 0; i < n; ++i) cin >> tests[i];

    int currQ = 0;
    string res(n, '0');
    for (int i = n - 1; i >= 0; --i) {
        if (currQ >= tests[i]) res[i] = '1';
        else if (currQ < q) {
            currQ++;
            res[i] = '1';
        }
        else res[i] = '0';
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}