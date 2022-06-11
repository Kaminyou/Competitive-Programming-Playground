#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, vector<int>& dp, vector<int>& subtree, vector<vector<int>>& graph) {
    dp[node] = 0;
    subtree[node] = 1;
    int sumDp = 0;
    for (auto& child : graph[node]) {
        if (child == parent) continue;
        dfs(child, node, dp, subtree, graph);
        sumDp += dp[child];
        subtree[node] += subtree[child];
    }
    for (auto& child : graph[node]) {
        if (child == parent) continue;
        dp[node] = max(dp[node], sumDp - dp[child] + subtree[child] - 1);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> dp(n + 1, 0);
    vector<int> subtree(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0, dp, subtree, graph);
    cout << dp[1] << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}