#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    long long sum = 0;
    int maxFreq = 0;
    map<long long, int> freqs;
    
    int res = 0;
    bool haveZero = false;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 0) {
            if (haveZero) {
                res += maxFreq;
            }
            else res += freqs[0];
            haveZero = true;
            freqs.clear();
            maxFreq = 0;

        }
        sum += x;
        freqs[sum]++;
        maxFreq = max(maxFreq, freqs[sum]);
    }
    if (haveZero) res += maxFreq;
    else res += freqs[0];
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
