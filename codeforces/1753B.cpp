#include <iostream>
#include <map>
using namespace std;

void solve() {
    int n;
    int x;
    map<int, int> counts;
    cin >> n >> x;
    while (n--) {
        int temp;
        cin >> temp;
        counts[temp]++;
    }
    while (counts.begin()->first < x) {
        int minElement = counts.begin()->first;
        int minElementCnt = counts.begin()->second;
        if (minElementCnt % (minElement + 1) == 0) {
            counts.erase(counts.find(minElement));
            counts[minElement + 1] += (minElementCnt / (minElement + 1));
        }
        else {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    solve();
    return 0;
}