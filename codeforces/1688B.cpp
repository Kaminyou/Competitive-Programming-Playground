#include <iostream>
#include <math.h> 
using namespace std;

void solve() {
    int n;
    cin >> n;
    int evenCount = 0;
    int oddCount = 0;
    int maxEvenMove = 64;

    int temp;
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        if (temp & 1) oddCount++;
        else {
            evenCount++;
            int lsb = temp & (-temp);
            maxEvenMove = min(maxEvenMove, (int)log2(lsb));
        }
    }
    if (oddCount >= 1) {
        cout << evenCount << endl;
        return;
    }
    else {
        cout << maxEvenMove + evenCount - 1 << endl;
        return;
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}