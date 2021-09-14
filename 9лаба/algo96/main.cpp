#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void dfs(vector<vector<int>> &g, vector<int> &used, int i, vector<int> &topsort)
{
    used[i] = 1;
    for (int j = 0; j < g[i].size(); j++)
    {
        if (used[g[i][j]] == 0)
            dfs(g, used, g[i][j], topsort);
    }
    topsort.push_back(i);
    used[i] = 2;
}
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n+1);
    vector<vector<int>> g1(n+1);
    vector<int> used(n + 1);
    vector<bool> win(n+1);
    for (int i = 0; i < n; i++)
        win[i] = false;
    vector<int> topsort;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g1[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (used[i] == 0) {
            dfs(g, used, i, topsort);
        }
    for (int i = 0; i < n; i++)
    {
        if (win[topsort[i]] == false)
            for (int j = 0; j < g1[topsort[i]].size(); j++)
                win[g1[topsort[i]][j]] = true;
    }
    if (win[k] == 1)
        cout << "First player wins";
    else
        cout << "Second player wins";
    return 0;
}