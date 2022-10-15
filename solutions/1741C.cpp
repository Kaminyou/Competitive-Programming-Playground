#include <iostream>
#include <string>
#include <vector>
using namespace std;


void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        sum += v[i];
    }
    int res = n; // max length is equal to the size of arr

    for (int i = 2; i <= n; ++i) {
        if (sum % i != 0) continue;
        long long target = sum / i;
        int thinckness = 0;
        
        long long segmentSum = 0;
        int index = 0;
        bool flag = true;
        for (int j = 0; j < n; ++j) {
            segmentSum += v[j];
            if (segmentSum == target) {
                //cout << index << " " << j << endl;
                thinckness = max(thinckness, j - index + 1);
                index = j + 1;
                segmentSum = 0;
            }
            else if (segmentSum > target) {
                flag = false;
                break;
            }
        }
        if (!flag) continue;
        res = min(res, thinckness);
    }
    cout << res << endl;

}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
