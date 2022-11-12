#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> prices(n, 0);
    for (int i = 0; i < n; ++i) cin >> prices[i];
    sort(prices.begin(), prices.end());
    vector<long long> prefixSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + prices[i];
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        long long res = prefixSum[n - x + y] - prefixSum[n - x];
        cout << res << endl;
    }

    return 0;
}