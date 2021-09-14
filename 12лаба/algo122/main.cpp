#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge{
    int s, f, w;
};
int dfs(int s, vector<vector<int>> &g, vector<edge> &edges, vector<int> &used, int t, int flow)
{
    if (s == t)
        return flow;
    used[s] = true;
    for (int i = 0; i < g[s].size(); i++)
    {
        int s1 = edges[g[s][i]].f;
        if ((!used[s1]) && (edges[g[s][i]].w > 0)){
            int df = dfs(s1, g, edges, used, g.size() - 1,min(flow, edges[g[s][i]].w));
            if (df > 0)
            {
                edges[g[s][i]].w -= df;
                if ((edges[g[s][i] + 1].f == edges[g[s][i]].s) && (edges[g[s][i] + 1].s == edges[g[s][i]].f))
                    edges[g[s][i] + 1].w += df;
                else
                    edges[g[s][i] - 1].w += df;
                return df;
            }
        }
    }
    return 0;
}
int main()
{
    //freopen("maxflow.in", "r", stdin);
    // freopen("maxflow.out", "w", stdout);
    int n ,m, k;
    cin >> n >> m >> k;
    vector<edge> edges;
    vector<vector<int>> g(n + m + 2);
    edge tmp{};
    for (int i = 0; i < k; i++)
    {
        cin >> tmp.s >> tmp.f;
        tmp.f += n;
        tmp.w = 1;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
        g[tmp.f].push_back(edges.size());
        int tm = tmp.s;
        tmp.s = tmp.f;
        tmp.f = tm;
        tmp.w = 0;
        edges.push_back(tmp);
    }
    for (int i = 1; i <= n; i++)
    {
        tmp.s = 0;
        tmp.f = i;
        tmp.w = 1;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
        g[tmp.f].push_back(edges.size());
        int tm = tmp.s;
        tmp.s = tmp.f;
        tmp.f = tm;
        tmp.w = 0;
        edges.push_back(tmp);
    }
    for (int i = 1; i <= m; i++)
    {
        tmp.s = n + i;
        tmp.f = n + m + 1;
        tmp.w = 1;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
        g[tmp.f].push_back(edges.size());
        int tm = tmp.s;
        tmp.s = tmp.f;
        tmp.f = tm;
        tmp.w = 0;
        edges.push_back(tmp);
    }
    vector<int> used(n + m +  2, false);
    int flow = 0;
    int inf = 1e9;
    k = dfs(0, g, edges, used, n + m + 1, inf);
    while (k > 0)
    {
        flow += k;
        fill(used.begin(), used.end(), false);
        k = dfs(0, g, edges, used, n + m + 1, inf);
    }
    cout << flow;
    return 0;
}