#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool tmp;
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
void dfs2(vector<vector<int>> &g1, vector<int> &used, int i, int k)
{
    used[i] = k;
    for (int j = 0; j < g1[i].size(); j++)
    {
        if (used[g1[i][j]] == -1)
            dfs2(g1, used, g1[i][j], k);
    }
}
int main() {
    freopen("cond.in", "r", stdin);
    freopen("cond.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<vector<int>> g1(n+1);
    vector<int> used(n + 1);
    vector<int> topsort;
    tmp = true;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g1[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
        if (used[i] == 0) {
            if (tmp)
                dfs(g, used, i, topsort);
        }
    reverse(topsort.begin(), topsort.end());
    for (int i = 1; i <= n; i++)
    {
        used[i] = -1;
    }
    int k = 0;
    for (int i = 0; i < n; i++)
        if (used[topsort[i]] == -1) {
            k++;
            dfs2(g1, used, topsort[i], k);
        }
    cout << k << endl;
    for (int i = 1; i < n + 1; i++)
        cout << used[i] << ' ';
    return 0;
}