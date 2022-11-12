#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> counts(10, 0); // 0-9
    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        temp %= 10;
        counts[temp]++;
    }
    for (int i = 0; i < 10; ++i) {
        counts[i] = min(counts[i], 3);
    }
    bool flag = false;
    // sum = 3
    // case 1 ~ 3
    if (counts[0] >= 2 && counts[3] >= 1) flag = true;
    if (counts[0] >= 1 && counts[1] >= 1 && counts[2] >= 1) flag = true;
    if (counts[1] >= 3) flag = true;
    // sum = 13 
    // case 15
    if (counts[0] >= 1 && counts[4] >= 1 && counts[9] >= 1) flag = true;
    if (counts[0] >= 1 && counts[5] >= 1 && counts[8] >= 1) flag = true;
    if (counts[0] >= 1 && counts[6] >= 1 && counts[7] >= 1) flag = true;
    if (counts[1] >= 1 && counts[3] >= 1 && counts[9] >= 1) flag = true;
    if (counts[1] >= 1 && counts[4] >= 1 && counts[8] >= 1) flag = true;
    if (counts[1] >= 1 && counts[5] >= 1 && counts[7] >= 1) flag = true;
    if (counts[1] >= 1 && counts[6] >= 2) flag = true;
    if (counts[2] >= 2 && counts[9] >= 1) flag = true;
    if (counts[2] >= 1 && counts[3] >= 1 && counts[8] >= 1) flag = true;
    if (counts[2] >= 1 && counts[4] >= 1 && counts[7] >= 1) flag = true;
    if (counts[2] >= 1 && counts[5] >= 1 && counts[6] >= 1) flag = true;
    if (counts[3] >= 2 && counts[7] >= 1) flag = true;
    if (counts[3] >= 1 && counts[4] >= 1 && counts[6] >= 1) flag = true;
    if (counts[3] >= 1 && counts[5] >= 2) flag = true;
    if (counts[4] >= 2 && counts[5] >= 1) flag = true;
    // sum 23
    // case 4
    if (counts[5] >= 1 && counts[9] >= 2) flag = true;
    if (counts[6] >= 1 && counts[8] >= 1 && counts[9] >= 1) flag = true;
    if (counts[7] >= 2 && counts[9] >= 1) flag = true;
    if (counts[7] >= 1 && counts[8] >= 2) flag = true;
    
    if (flag) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}