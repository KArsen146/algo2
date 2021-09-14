#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool tmp;
void dfs(vector<vector<int>> &g, vector<pair<int,int>> &used, int i)
{
    for (int j = 0; j < g[i].size(); j++)
    {
        if ((used[g[i][j]].first == used[i].first) && (g[i][j] != i) && (used[i].second != g[i][j]))
        {
            if (tmp) {
                cout << "NO";
                tmp = false;
                exit;
            }
        }
        if (used[g[i][j]].first == 0) {
            if (used[i].first == 1)
                used[g[i][j]].first = 2;
            else
                used[g[i][j]].first = 1;
            used[g[i][j]].second = i;
            dfs(g, used, g[i][j]);
        }
    }
}
int main() {
    freopen("bipartite.in", "r", stdin);
    freopen("bipartite.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<pair<int,int>> used(n + 1);
    tmp = true;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        tmp = false;
        for (int i = 0; i < g[a].size(); i++)
            if (g[a][i] = b)
                tmp = true;
        if (!tmp) {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }
    tmp = true;
    for (int i = 1; i <= n; i++)
        if (used[i].first == 0) {
            used[i].first = 1;
            dfs(g, used, i);
        }
    if (tmp)
        cout << "YES";
    return 0;
}