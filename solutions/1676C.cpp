#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve(vector<string>& words) {
    int res = INT_MAX;
    int n = words.size();
    int len = words[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int curr = 0;
            for (int k = 0; k < len; ++k) {
                curr += abs(words[i][k] - words[j][k]);
            }
            res = min(res, curr);
        }
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int m, n;
        cin >> m;
        cin >> n;
        vector<string> words(m);
        for (int i = 0; i < m; i++) {
            cin >> words[i];
        }
        solve(words);
    }
    return 0;
}