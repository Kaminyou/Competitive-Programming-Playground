#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    string A, B;
    cin >> A;
    cin >> B;

    int countA = 0;
    int countB = 0;
    vector<bool> isA(26, false);
    vector<bool> isB(26, false);
    vector<int> countChar(26, 0);

    for (int i = 0; i < n; ++i) {
        countChar[A[i] - 'a']++;
        isA[A[i] - 'a'] = true;
        countA++;
    }
    for (int i = 0; i < m; ++i) {
        countChar[B[i] - 'a']++;
        isB[B[i] - 'a'] = true;
        countB++;
    }
    int codaA = k;
    int codaB = k;
    string res = "";
    while (countA && countB) {
        bool isSmall = true;
        for (int i = 0; i < 26; ++i) {
            if (countChar[i]) {
                if (isA[i] && codaA) {
                    int add = min(countChar[i], codaA);
                    if (!isSmall) add = 1;
                    for (int j = 0; j < add; ++j) res.push_back(i + 'a');
                    codaA -= add;
                    countChar[i] -= add;
                    countA -= add;
                    codaB = k;
                    break;
                }
                else if (isB[i] && codaB) {
                    int add = min(countChar[i], codaB);
                    if (!isSmall) add = 1;
                    for (int j = 0; j < add; ++j) res.push_back(i + 'a');
                    codaB -= add;
                    countChar[i] -= add;
                    countB -= add;
                    codaA = k;
                    break;
                }
                isSmall = false;
            }
        }
        
    }
    cout << res << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}