#include <iostream>
#include <vector>
#include <string>
using namespace std;

int criteria(string& s, int maxFlip) {
    int l = 0;
    int countFlip = 0;
    int maxConsecutive = 0;
    for (int r = 0; r < s.size(); ++r) {
        if (s[r] == 'W') countFlip++;
        while (countFlip > maxFlip) {
            if (s[l] == 'W') countFlip--;
            l++;
        }
        maxConsecutive = max(maxConsecutive, r - l + 1);
    }
    return maxConsecutive;
}
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int left = 0;
    int right = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') right++;
    }

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (criteria(s, mid) >= k) right = mid;
        else left = mid + 1;
    }
    cout << left << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}