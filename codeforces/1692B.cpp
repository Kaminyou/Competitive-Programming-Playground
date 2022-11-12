#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        mp[temp]++;
    }
    int res = 0;
    int deleteNum = 0;
    for (auto& element : mp) {
        if (element.second > 0) res++;
        deleteNum += (element.second - 1);
    }
    if (deleteNum & 1) cout << res - 1 << endl;
    else cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}