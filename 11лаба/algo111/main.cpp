#include <iostream>
#include <vector>
using namespace std;
const long long inf = 1e14;
int main() {
    freopen("pathmgep.in", "r", stdin);
    freopen("pathmgep.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n, s, f;
    cin >> n >> s >> f;
    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; i++)
    {
        g[i].resize(n+1);
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];
    }
    vector<long long> dist(n + 1, inf);
    vector<bool> visited(n + 1, false);
    dist[s] = 0;
    int tmp, min_ind = s;
    long long min_v;
    for (int i = 1; i <= n; i++)
    {
        tmp = -1;
        min_v = inf;
        visited[min_ind] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!visited[j])
            {
                if (g[min_ind][j] != -1)
                    dist[j] = min(dist[min_ind] + g[min_ind][j], dist[j]);
                if (dist[j] < min_v)
                {
                    min_v = dist[j];
                    tmp = j;
                }
            }
        }
        if ((tmp == -1) || (tmp == f)) {
            if (dist[f] == inf)
                cout << -1;
            else
                cout << dist[f];
            return 0;
        }
        min_ind = tmp;
    }
    if (dist[f] == inf)
        cout << -1;
    else
        cout << dist[f];
    return 0;
}