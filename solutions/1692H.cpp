#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

void solve() {
    int n;
    unordered_map<long long, vector<int>, custom_hash> mp;
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