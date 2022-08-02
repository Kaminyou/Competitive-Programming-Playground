#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <climits>
using namespace std;

void solve() {
    string target;
    cin >> target;
    int n ;
    cin >> n;
    string temp;
    unordered_map<string, int> st;
    unordered_map<int, string> idx2str;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        st[temp] = i;
        idx2str[i] = temp;
    }

    int m = target.size();
    vector<int> dp(m + 1, INT_MAX / 2);
    vector<int> used(m + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < target.size(); ++i) {
        for (int j = 1; j <= min(10, i + 1); ++j) {
            string extract = target.substr(i - j + 1, j);
            if (st.find(extract) != st.end()) {
                for (int k = 0; k < j; ++k) {
                    if (dp[i - j + 1 + k] + 1 < dp[i + 1]) {
                        dp[i + 1] = dp[i - j + 1 + k] + 1;
                        used[i + 1] = st[extract];
                    }
                }
            }
        }
    }
    if (dp[m] == INT_MAX / 2) {
        cout << "-1" << endl;
        return;
    }
    cout << dp[m] << endl;
    int curr = dp[m];
    for (int i = m; i > 0; --i) {
        if (dp[i] == curr) {
            int length = idx2str[used[i]].size();
            cout << (used[i] + 1) << " " << (i - length + 1) << endl;
            curr--;
        }
    }
    
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}