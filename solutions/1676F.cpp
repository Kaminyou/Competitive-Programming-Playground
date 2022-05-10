#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

void solve(vector<int>& nums, int k) {
    map<int, int> mp;
    for (auto num : nums) mp[num]++;
    vector<pair<int, int>> v;
    for (auto element : mp) v.push_back(make_pair(element.first, element.second));

    int n = v.size();
    int index = 0;
    int interval = -1;
    int resStart = -1;
    int resEnd = -1;
    while (index < n) {
        if (v[index].second < k) index++;
        else {
            int start = v[index].first;
            while (index + 1 < n && v[index + 1].second >= k && (v[index + 1].first - v[index].first == 1)) {
                index++;
            }
            int end = v[index].first;
            if (end - start > interval) {
                interval = end - start;
                resStart = start;
                resEnd = end;
            }
            index++;
        }
    }
    if (interval == -1) cout << "-1" << endl;
    else cout << resStart << " " << resEnd << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n, k;
        cin >> n;
        cin >> k;
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        solve(nums, k);
    }
    return 0;
}