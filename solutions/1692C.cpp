#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n = 8;
    vector<string> board;
    vector<int> countCol(8, 0);
    vector<int> countRow(8, 0);
    for (int i = 0; i < n; ++i) {
        string row;
        cin >> row;
        board.push_back(row);
    }


    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == '#') {
                countRow[i]++;
                countCol[j]++;
            }
        }
    }

    int row = -1;
    int col = -1;
    for (int i = 1; i < 7; ++i) {
        if (countRow[i - 1] == 2 && countRow[i] == 1 && countRow[i + 1] == 2) {
            row = i;
            break;
        }
    }
    for (int i = 1; i < 7; ++i) {
        if (countCol[i - 1] == 2 && countCol[i] == 1 && countCol[i + 1] == 2) {
            col = i;
            break;
        }
    }
    cout << row + 1 << " " << col + 1 << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}