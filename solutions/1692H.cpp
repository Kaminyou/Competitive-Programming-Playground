#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve() {
    int n;
    map<int, vector<int>> mp;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        mp[v[i]].push_back(i);
    }
    int res = 1;
    int number = v[n - 1];
    int left = n - 1;
    int right = n - 1;
    for (auto& element : mp) {
        if (element.second.size() == 1) continue;
        // Kadane's algorithm
        int sum = 1;
        int l = 0;
        int r = 1;
        for (; r < element.second.size(); ++r) {
            sum += 1;
            sum -= (element.second[r] - element.second[r - 1] - 1);
            if (sum < 1) {
                sum = 1;
                l = r;
            }
            if (sum > res) {
                res = sum;
                left = element.second[l];
                right = element.second[r];
                number = element.first;
            }
        }
    }
    cout << number << " " << left + 1 << " " << right + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}