#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> v(n, 0);
    int maxIdx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] == n) maxIdx = i;
    }

    vector<vector<int>> memo(n);
    int idx1 = 0;
    int idx2 = 1;
    // make v[idx2] > v[idx1]
    int time = 1;
    while (idx1 < n && idx2 < n){
        if (idx2 < idx1) swap(idx1, idx2);
        // idx2 > idx1
        // compare
        if (v[idx1] < v[idx2]) {
            // idx2 win
            memo[idx2].push_back(time);
            idx1 = idx2 + 1;
        }
        // v[idx1] > v[idx2]
        else {
            // idx 1 win
            memo[idx1].push_back(time);
            idx2++;
        }
        time++;
    }

    for (int i = 0; i < q; ++i) {
        int athlete, k;
        cin >> athlete >> k;
        athlete--;

        if (athlete == maxIdx) {
            cout << max(0, k - memo[athlete].front() + 1) << endl;
        }
        else {
            auto it = upper_bound(memo[athlete].begin(), memo[athlete].end(), k);
            if (it == memo[athlete].begin()) cout << "0" << endl;
            else {
                it--;
                int res = it - memo[athlete].begin() + 1;
                cout << res << endl;
            }
        }
    }

}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}