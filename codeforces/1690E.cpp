#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    long long count = 0;
    long temp;
    vector<int> remain(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        count += (long long)temp / k;
        remain[i] = temp % k;
    }
    sort(remain.begin(), remain.end());
    int left = 0;
    int right = remain.size() - 1;
    while (left < right) {
        if (remain[left] + remain[right] >= k) {
            left++;
            right--;
            count++;
        }
        else left++;
    }
    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}