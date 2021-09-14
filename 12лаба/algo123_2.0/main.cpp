#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct edge{
    short int f, num, ind_ref;
    int w;
};
vector<vector<edge>> g;
vector<int> used;
vector<short int> uf;
vector<vector<int>> v1;
int bfs(int& s, int& t)
{
    fill(used.begin(), used.end(), -1);
    queue<short int> q;
    q.push(s);
    used[s] = 0;
    while (!q.empty())
    {
        for(int i = 0; i < g[q.front()].size(); i++)
        {
            int s1 = g[q.front()][i].f;
            if ((used[s1]== -1) &&(g[q.front()][i].w > 0))
            {
                q.push(s1);
                used[s1] = used[q.front()] + 1;
            }
        }
        q.pop();
    }
    return used[t] != -1;
}
int dfs(int& s, int& t, int flow)
{
    if ((s == t) || (flow == 0))
        return flow;
    for (int i = uf[s]; i < g[s].size(); i++)
    {
        int s1 = g[s][i].f;
        if ((used[s1] == used[s] + 1) &&(g[s][i].w > 0))
        {
            int df = dfs(s1,t,min(flow,g[s][i].w));
            if (df > 0)
            {
                g[s][i].w -= df;
                g[g[s][i].f][g[s][i].ind_ref].w += df;
                return df;
            }
        }
        uf[s]++;
    }
    return 0;
}
int dfs2(int s, int& t, int flow)
{
    if (s == t)
        return flow;
    for (auto & i : g[s])
    {
        if (i.w >0)
        {
            v1[v1.size() - 1].emplace_back(i.num);
            int df = dfs2(i.f, t, min(flow, i.w));
            i.w -= df;
            return df;
        }
    }
    return 0;
}
int dinica(int s, int& t)
{
    int flow;
    used.resize(t + 1, -1);
    uf.resize(t + 1, 0);
    while (bfs(s, t))
    {
        fill(uf.begin(), uf.end(), 0);
        flow = dfs(s, t, 1e9);
        while (flow!=0)
        {
            flow = dfs(s,t, 1e9);
        }
    }
    used.clear();
    uf.clear();
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j < g[i].size(); j++)
        {
            if (g[i][j].num == -1)
            {
                g[g[i][j].f][g[i][j].ind_ref].w = g[i][j].w;
                g[i][j].w = 0;
            }
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    short int a, b;
    int c;
    for (short int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        g[a].push_back({b, short(i + 1), short(g[b].size()), c});
        g[b].push_back({a, -1, short(g[a].size() - 1), 0});
    }
    dinica(1, n);
    v1.emplace_back();
    int flow = dfs2(1, n, 1e9);
    while(flow > 0)
    {
        v1[v1.size() - 1].emplace_back(flow);
        v1.emplace_back();
        flow = dfs2(1, n, 1e9);
    }
    cout << v1.size() - 1;
    for (auto &v:v1)
    {
        if (!v.empty())
        {
            cout << endl << v[v.size() - 1] << ' ' << v.size() - 1;
            for (int i = 0; i < v.size() - 1; i++)
                cout << ' ' << v[i];
        }
    }
    return 0;
}