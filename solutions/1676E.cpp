#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& candies, vector<int>& queries) {
    sort(candies.begin(), candies.end(), greater<int>());
    for (int i = 1; i < candies.size(); i++) {
        candies[i] = candies[i - 1] + candies[i];
    }
    for (auto query : queries) {
        int index = lower_bound(candies.begin(), candies.end(), query) - candies.begin();
        if (index == candies.size()) cout << "-1" << endl;
        else cout << index + 1 << endl;
    }
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, q;
        cin >> n;
        cin >> q;
        vector<int> candies(n, 0);
        vector<int> queries(q, 0);
        for (int i = 0; i < n; i++) {
            cin >> candies[i];
        }
        for (int i = 0; i < q; i++) {
            cin >> queries[i];
        }
        solve(candies, queries);
    }
    return 0;
}