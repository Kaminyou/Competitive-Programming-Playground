#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

void solve() {
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;

    map<long long, long long> mp;
    long long start = s.size() + 1;
    long long l, r;
    for (int i = 0; i < c; ++i) {
        cin >> l >> r;
        mp[start] = l;
        start += (r - l + 1);
    }

    long long k;
    for (int i = 0; i < q; ++i) {
        cin >> k;
        long long target = s.size();
        while (k > target) {
            
            auto lb = mp.upper_bound(k);
            lb--;
            k = k - lb->first + lb->second;
        }
        k--;
        cout << s[k] << endl;
    }   
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}