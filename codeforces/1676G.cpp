#include <iostream>
#include <vector>
#include <map>
#include <utility>
using namespace std;

vector<int> dfs(vector<vector<int>>& children, int curr, string& colors, int& count) {
    if (children[curr].size() == 0) {
        if (colors[curr - 1] == 'B') return {1, 0};
        else return {0, 1};
    }
    else {
        vector<int> BW = {0, 0};
        for (auto child : children[curr]) {
            vector<int> temp = dfs(children, child, colors, count);
            BW[0] += temp[0];
            BW[1] += temp[1];
        }
        if (colors[curr - 1] == 'B') BW[0]++;
        else BW[1]++;
        if (BW[0] == BW[1]) count++;
        return BW;
    }
}
void solve(vector<int>& parents, string& colors) {

    int n = parents.size();
    vector<vector<int>> children(n + 1); // 1 to n
    for (int i = 1; i < parents.size(); i++) {
        children[parents[i]].push_back(i + 1);
    }
    int count = 0;
    dfs(children, 1, colors, count);
    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<int> parents(n, 0);
        string colors;
        for (int i = 1; i < n; i++) {
            cin >> parents[i];
        }
        cin >> colors;
        solve(parents, colors);
    }
    return 0;
}