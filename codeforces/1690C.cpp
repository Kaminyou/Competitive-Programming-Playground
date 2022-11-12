#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> received(n, 0);
    vector<int> finished(n, 0);
    for (int i = 0; i < n; ++i) cin >> received[i];
    for (int i = 0; i < n; ++i) cin >> finished[i];

    vector<int> duration(n, 0);
    int currTime = 0;
    for (int i = 0; i < n; ++i) {
        currTime = max(currTime, received[i]);
        int dur = finished[i] - currTime;
        duration[i] = dur;
        currTime = max(currTime, finished[i]);
    }
    for (int i = 0; i < n; ++i) {
        if (i == n - 1) cout << duration[i] << endl;
        else cout << duration[i] << " ";
    }
    
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}