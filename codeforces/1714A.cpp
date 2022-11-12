#include <iostream>
using namespace std;

int getDiff(int h, int m, int nextH, int nextM) {
    if (h == nextH && m == nextM) return 0;
    nextH += 24;
    if (nextM < m) {
        nextH--;
        nextM += 60;
    }
    int diff = (nextH - h) * 60 + (nextM - m);
    if (diff >= 1440) diff -= 1440;
    return diff;
}
void solve() {
    int n, h, m;
    cin >> n >> h >> m;
    int res = 1440;
    while (n--) {
        int nextH, nextM;
        cin >> nextH >> nextM;
        int diff =  getDiff(h, m, nextH, nextM);
        //cout << diff << endl;
        res = min(res, diff);
    }
    int resH = res / 60;
    int resM = res % 60;
    cout << resH << " " << resM << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}