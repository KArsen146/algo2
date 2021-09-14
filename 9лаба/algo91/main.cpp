#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool tmp;
void dfs(vector<vector<int>> &g, vector<int> &used, int i)
{
    used[i] = 1;
    for (int j = 0; j < g[i].size(); j++)
    {
        if (used[g[i][j]] == 1)
        {
            if (tmp) {
                cout << "YES" << endl;
                tmp = false;
                cout << g[i][j] << ' ';
                int l = g[i][j];
                while (l != i) {
                    int k = 0;
                    while (used[g[l][k]] != 1)
                        k++;
                    l = g[l][k];
                    cout << l << ' ';
                }
            }
        }
        if (used[g[i][j]] == 0)
            dfs(g, used, g[i][j]);
    }
    used[i] = 2;
}
int main() {
    freopen("cycle.in", "r", stdin);
    freopen("cycle.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n+1);
    vector<int> used(n + 1);
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
                dfs(g, used, i);
        }
    if (tmp)
        cout << "NO";
    return 0;
}