#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> nums(n, 0);    
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    vector<long long> diff(n, 0);
    diff[0] = nums[0];
    for (int i = 1; i < n; ++i) {
        diff[i] = nums[i] - nums[i - 1];
    }

    long long res = 0;
    for (int i = 1; i < n; ++i) {
        if (diff[i] < 0) {
            res -= diff[i];
            diff[0] += diff[i];
        }
        else {
            res += diff[i];
        }
    }
    res += abs(diff[0]);
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}