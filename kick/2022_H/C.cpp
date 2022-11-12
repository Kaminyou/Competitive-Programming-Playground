#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int dfs(int parent, int node, vector<vector<int>>& edges, vector<int>& values, vector<int>& memo) {
    if (memo[node] != -1) return memo[node];
    int cnt = 0;
    for (auto& neighbor : edges[node]) {
        if (neighbor == parent) continue;
        if (values[neighbor] >= values[node]) continue;
        cnt += dfs(node, neighbor, edges, values, memo);
    }
    return memo[node] = cnt + 1;
}

int solve() {
    int N;
    cin >> N;
    vector<int> values(N, 0);
    for (int i = 0; i < N; ++i) cin >> values[i];
    vector<vector<int>> edges(N);
    for (int i = 0; i < N - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        edges[v1 - 1].push_back(v2 - 1);
        edges[v2 - 1].push_back(v1 - 1);
    }
    vector<int> memo(N, -1);
    int res = 0;
    for (int i = 0; i < N; ++i) {
        int cnt = dfs(-1, i, edges, values, memo);
        res = max(res, cnt);
    }
    return res;
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int ans = solve();
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
