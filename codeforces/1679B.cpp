#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> mp; // idx -> value
    int n, q;
    cin >> n;
    cin >> q;
    
    long long sum = 0;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        sum += arr[i];
    }

    vector<vector<int>> queries(q, vector<int>(3, 0));
    int type;
    for (int i = 0; i < q; ++i) {
        cin >> type;
        queries[i][0] = type;
        if (type == 1) {
            for (int j = 1; j < 3; ++j) cin >> queries[i][j];
        }
        else cin >> queries[i][1];
    }

    bool isChange = false;
    int currValue = INT_MIN;
    // calculate
    for (int i = 0; i < q; ++i) {
        if (queries[i][0] == 1) {
            int index = queries[i][1] - 1;
            int value = queries[i][2];
            int diff;
            if (!isChange) {
                diff = value - arr[index];
                arr[index] = value;
            }
            else {
                if (mp.find(index) != mp.end()) diff = value - mp[index];
                else {
                    diff = value - currValue;
                    mp[index] = value;
                }
            }
            sum += diff;
            cout << sum << endl;
        }
        else {
            isChange = true;
            int change = queries[i][1];
            sum = change * (long long)(n);
            currValue = change;
            mp.clear();
            //for (int i = 0; i < n; i++) arr[i] = change;
            cout << sum << endl;
        }
    }
    return 0;
}