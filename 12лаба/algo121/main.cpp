#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge{
    int s, f, w;
};

int main()
{
    //freopen("maxflow.in", "r", stdin);
   // freopen("maxflow.out", "w", stdout);
    int n ,m;
    cin >> n >> m;
    vector<edge> edges;
    vector<vector<int>> g(n + 1);
    edge tmp{};
    for (int i = 0; i < m; i++)
    {
        cin >> tmp.s >> tmp.f >> tmp.w;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
        g[tmp.f].push_back(edges.size());
        int tm = tmp.s;
        tmp.s = tmp.f;
        tmp.f = tm;
        tmp.w = 0;
        edges.push_back(tmp);
    }
    vector<int> used(n + 1, false);
    int k;
    int flow = 0;
    int inf = 1e9;
    k = dfs(1, g, edges, used, n, inf);
    while (k > 0)
    {
        flow += k;
        fill(used.begin(), used.end(), false);
        k = dfs(1, g, edges, used, n, inf);
    }
    cout << flow;
    return 0;
}