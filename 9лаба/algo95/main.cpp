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
        if (used[g[i][j]] == 1)
        {
            tmp = false;
            exit;
        }
        if (used[g[i][j]] == 0)
            dfs(g, used, g[i][j], topsort);
    }
    topsort.push_back(i);
    used[i] = 2;
}
int main() {
    //freopen("hamiltonian.in", "r", stdin);
    //freopen("hamiltonian.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<int> used(n + 1);
    vector<int> topsort;
    tmp = true;
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
        if (used[i] == 0) {
            if (tmp)
                dfs(g, used, i, topsort);
        }
    reverse(topsort.begin(), topsort.end());
    if (tmp)
    {
        int i = 0;
        while ((tmp) && (i < n - 1))
        {
            tmp = false;
            for (int j = 0; j < g[topsort[i]].size(); j++)
                if (g[topsort[i]][j] = i + 2)
                    tmp = true;
            i++;
        }
        if (tmp)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";
    return 0;
}