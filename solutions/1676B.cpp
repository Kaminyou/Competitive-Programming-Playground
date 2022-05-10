#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int>& candies) {
    int n = candies.size();
    int minVal = *min_element(candies.begin(), candies.end());
    int sum = 0;
    for (auto candy : candies) sum += (candy - minVal);
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        solve(v);
    }
    return 0;
}