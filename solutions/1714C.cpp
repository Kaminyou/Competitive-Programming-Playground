#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> res;
    int curr = 9;
    while (n >= curr && n > 0 && curr > 0) {
        res.push_back(curr);
        n -= curr;
        curr--;
    }
    if (n) res.push_back(n);
    int m = res.size();
    string ans = "";
    for (int i = m - 1; i >= 0; --i) {
        ans.push_back(res[i] + '0');
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}