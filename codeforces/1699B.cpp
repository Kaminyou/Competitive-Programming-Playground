#include <iostream>
#include <string>
#include <vector>
using namespace std;

//static const string one = "10011001100110011001100110011001100110011001100110";
//static const string two = "01100110011001100110011001100110011001100110011001";
//static const string three = "01100110011001100110011001100110011001100110011001";
vector<string> v = {"10011001100110011001100110011001100110011001100110",
                    "01100110011001100110011001100110011001100110011001",
                    "01100110011001100110011001100110011001100110011001",
                    "10011001100110011001100110011001100110011001100110"};

void solve(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int mode = i % 4;
        for (int j = 0; j < m; ++j) {
            cout << v[mode][j] << " ";
        }
        cout << endl;
    }
    return;
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
}