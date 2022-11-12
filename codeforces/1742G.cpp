#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    vector<int> res(n, -1);
    int maxElement = -1;
    int maxElementIdx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        if (v[i] > maxElement) {
            maxElement = v[i];
            maxElementIdx = i;
        }
    }
    vector<bool> used(n, false);
    int index = 0;
    used[maxElementIdx] = true;
    res[index] = maxElement;
    index++;
    int currentMax = maxElement;

    bool hasFuture = true;
    while (hasFuture) {
        int nextMax = currentMax;
        int nextIdx = -1;
        bool find = false;
        for (int i = 0; i < n; ++i) {
            if (used[i] == false) {
                if ((currentMax | v[i]) > nextMax) {
                    nextMax = currentMax | v[i];
                    nextIdx = i;
                    find = true;
                }
            }
        }
        if (!find) break;
        res[index] = v[nextIdx];
        used[nextIdx] = true;
        index++;
        currentMax = nextMax;
    }
    for (int i = 0; i < n; ++i) {
        if (used[i] == false) {
            res[index] = v[i];
            index++;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}