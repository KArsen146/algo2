#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct edge{
    int s, f, w;
};
int bfs(vector<vector<int>> &g, vector<edge> &edges, int s, int t, vector<int> &used)
{
    fill(used.begin(), used.end(), -1);
    queue<int> q;
    q.push(s);
    used[s] = 0;
    while (!q.empty())
    {
        for(auto i: g[q.front()])
        {
            int s1 = edges[i].f;
            if ((used[s1]== -1) &&(edges[i].w > 0))
            {
                q.push(s1);
                used[s1] = used[q.front()] + 1;
            }
        }
        q.pop();
    }
    return used[t] != -1;
}
int dfs(int s, vector<vector<int>> &g, vector<edge> &edges, vector<int> &used, int t, int flow, vector<int> & uf)
{
    if ((s == t) || (flow == 0))
        return flow;
    for (int i = uf[s]; i < g[s].size(); i++)
    {
        int s1 = edges[g[s][i]].f;
        if (used[s1] == used[s] + 1)
        {
            int df = dfs(s1, g, edges, used, g.size() - 1,min(flow, edges[g[s][i]].w), uf);
            if (df > 0)
            {
                edges[g[s][i]].w -= df;
                if (g[s][i] > edges.size() / 2)
                    edges[g[s][i] - edges.size() /2].w += df;
                else
                    edges[g[s][i] + edges.size() / 2].w += df;
                return df;
            }
        }
        uf[s]++;
    }
    return 0;
}
int dinica(vector<vector<int>> &g, vector<edge> &edges, int s, int t)
{
    int maxflow = 0, flow = 0;
    vector<int> used(t + 1, -1);
    vector<int> used_f(t + 1, 0);
    while (bfs(g, edges, s, t, used))
    {
        fill(used_f.begin(), used_f.end(), 0);
        flow = dfs(s, g, edges, used, t, INT_MAX, used_f);
        while (flow!=0)
        {
            maxflow += flow;
            flow = dfs(s, g, edges, used, t, INT_MAX, used_f);
        }
    }
    return maxflow;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    vector<vector<int>> g(n + 2);
    edge tmp{};
    int a, b, c;
    int max_flow = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp.s >> tmp.f >> a >> b;
        tmp.w = b - a;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
        c = tmp.s;
        tmp.s = 0;
        tmp.w = a;
        max_flow+=a;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
        tmp.s = c;
        tmp.f = n + 1;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
    }
    int tm;
    for (int i = 0; i < 3 * m; i++)
    {
        tmp = edges[i];
        tm = tmp.s;
        tmp.s = tmp.f;
        tmp.f = tm;
        tmp.w = 0;
        edges.push_back(tmp);
        g[tmp.s].push_back(edges.size() - 1);
    }
    if (dinica(g, edges, 0, n + 1) == max_flow)
    {
        cout << "YES" << endl;
        for (int i = m - 1; i >= 0; i--)
        {
            cout << edges[edges.size() - 3 * i - 2].w + edges[edges.size() - 3 * (i + 1)].w<< endl;
        }
    }
    else
        cout<< "NO";
    return 0;
}