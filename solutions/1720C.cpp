#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> matrix(n, vector<bool>(m, false));
    
    int zeros = 0;
    int ones = 0;
    
    for (int i = 0; i < n; ++i) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; ++j) {
            if (temp[j] == '0') {
                zeros++;
                matrix[i][j] = true;
            }
            else {
                ones++;
                matrix[i][j] = false;
            }
            
        }
    }
    if (zeros == 0) {
        cout << (ones - 2) << endl;
        return;
    }
    if (ones == 0) {
        cout << "0" << endl;
        return;
    }
    // check 00
    bool hasContinue = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (matrix[i][j - 1] && matrix[i][j]) {
                hasContinue = true;
                break;
            }
        }
        if (hasContinue) break;
    }
    //cout << "hasContinue " << hasContinue << endl;
    if (!hasContinue) {
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i - 1][j] && matrix[i][j]) {
                    hasContinue = true;
                    break;
                }
            }
            if (hasContinue) break;
        }
    }
    //cout << "hasContinue " << hasContinue << endl;
    if (!hasContinue) {
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i - 1][j - 1] && matrix[i][j]) {
                    hasContinue = true;
                    break;
                }
                if (matrix[i - 1][j] && matrix[i][j - 1]) {
                    hasContinue = true;
                    break;
                }
            }
            if (hasContinue) break;
        }
    }
    //cout << "hasContinue " << hasContinue << endl;
    if (!hasContinue) cout << ones - 1 << endl;
    else cout << ones << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}