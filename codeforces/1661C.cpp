#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool criteria(int target, long long days, vector<int> trees) {
    long long budget1 = (days + 1) / 2;
    long long budget2 = days - budget1;
    int n = trees.size();
    for (int i = 0; i < n; ++i) {
        long long diff = target - trees[i];
        long long use2 = min((long long)diff / 2, budget2);
        budget2 -= use2;
        diff -= use2 * 2;
        if (budget1 < diff) return false;
        budget1 -= diff;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    int maxElement = -1;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        maxElement = max(maxElement, v[i]);
    }
    
    long long res = LLONG_MAX;
    vector<int> targets = {maxElement, maxElement + 1};
    for (auto& target : targets) {
        long long left = 0;
        long long right = LLONG_MAX - 2;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (criteria(target, mid, v)) right = mid;
            else left = mid + 1;
        }
        res = min(res, left);
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}