#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string lids;
    cin >> lids;
    vector<int> magazines(n, 0);
    for (int i = 0; i < n; ++i) cin >> magazines[i];
    //cout << lids << endl;
    vector<long long> haveLibDp(n + 1, 0);
    vector<long long> nothaveLibDp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        if (lids[i - 1] == '1') {
            haveLibDp[i] = max(haveLibDp[i - 1], nothaveLibDp[i - 1]) + magazines[i - 1];
            if (i > 1) nothaveLibDp[i] = nothaveLibDp[i - 1] + magazines[i - 2];
            else nothaveLibDp[i] = nothaveLibDp[i - 1];
        }
        else {
            haveLibDp[i] = 0;
            nothaveLibDp[i] = max(haveLibDp[i - 1], nothaveLibDp[i - 1]);
        }
    }
    cout << max(haveLibDp[n], nothaveLibDp[n]) << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
