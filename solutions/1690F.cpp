#include <iostream>
#include <vector>
#include <string>
using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int countShiftEqual(string s) {
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        string first = s.substr(0, i);
        string second = s.substr(i);
        if (s == (second + first)) return i;
    }
    return n;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> shift(n, 0);
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> shift[i];
        shift[i]--;
    }

    long long ans = 1;
    int index = 0;
    while (index < n) {
        string temp = "";
        while (!used[index]) {
            used[index] = true;
            temp.push_back(s[index]);
            index = shift[index];
        }
        index++;
        if (temp.size() == 0) continue;
        int move = countShiftEqual(temp);
        ans = ans * move / gcd(ans, move);
    }
    cout << ans << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}