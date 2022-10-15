#include <iostream>
#include <string>
#include <vector>
using namespace std;

int parseChunk(vector<int>& v, int left, int chunkSize) {
    int length = chunkSize / 2;
    // [left, left + length - 1], [left + length, left + chunkSize - 1]
    int leftPresent = (v[left] - 1) / length;
    int rightPresent = (v[left + length] - 1) / length;
    // for (int i = left; i <= left + chunkSize - 1; ++i) {
    //     cout << ((v[i] - 1) / length) << " ";
    // }
    // cout << endl;
    for (int i = left; i <= left + length - 1; ++i) {
        if (((v[i] - 1) / length) != leftPresent) return -1;
    }
    for (int i = left + length; i <= left + chunkSize - 1; ++i) {
        if (((v[i] - 1) / length) != rightPresent) return -1;
    }
    if (leftPresent < rightPresent) return 0;
    else return 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int sum = 0;
    int chunkSize = 2;
    for (; chunkSize <= n; chunkSize *= 2) {
        //cout << "chunkSize " << chunkSize << endl;
        for (int i = 0; i < n; i += chunkSize) {
            int res = parseChunk(v, i, chunkSize);
            if (res == -1) {
                cout << "-1" << endl;
                return;
            }
            sum += res;
        }
    }
    cout << sum << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
