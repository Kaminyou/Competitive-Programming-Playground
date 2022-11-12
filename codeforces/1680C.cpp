#include <iostream>
#include <string>
using namespace std;

void solve(string& s) {
    int n = s.size();
    int cnt1 = 0;
    int cnt0 = 0;
    for (auto c : s) {
        if (c == '1') cnt1++;
    }
    int left = 0;
    int right = 0;
    int ans = cnt1;
    while (left < n) {
        while (right < n && cnt0 != cnt1) {
            if (s[right] == '1') cnt1--;
            else cnt0++;
            right++;
        }
        ans = min(ans, max(cnt0, cnt1));
        if (s[left] == '1') cnt1++;
        else cnt0--;
        left++;
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}