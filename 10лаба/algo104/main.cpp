#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct edge
{
    int from, to, w;
};
const int MAXINT = 1e9+1;
int dfs(vector<vector<edge>> &g, vector<int> &comp, int &i)
{
    int res = 1;
    comp[i] = 1;
    for (int j = 0; j < g[i].size(); j++)
        if (comp[g[i][j].to] == 0) {
            res += dfs(g, comp, g[i][j].to);
        }
    return res;
}
void dfs_cond1(vector<vector<edge>> &g, vector<int> &used, int i, vector<int> &topsort)
{
    used[i] = 1;
    for (int j = 0; j < g[i].size(); j++)
    {
        if (used[g[i][j].to] == 0)
            dfs_cond1(g, used, g[i][j].to, topsort);
    }
    topsort.push_back(i);
    used[i] = 2;
}
void dfs_cond2(vector<vector<edge>> &g1, vector<int> &used, int i, int k) {
    used[i] = k;
    for (int j = 0; j < g1[i].size(); j++) {
        if (used[g1[i][j].from] == -1)
            dfs_cond2(g1, used, g1[i][j].from, k);
    }
}
vector <int> condensation(vector<vector<edge>> g, vector<vector<edge>> g1, int &n)
{
    vector<int> used(n + 1);
    vector<int> topsort;
    bool tmp = true;
    for (int i = 1; i <= n; i++)
        if (used[i] == 0) {
            if (tmp)
                dfs_cond1(g, used, i, topsort);
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
            dfs_cond2(g1, used, topsort[i], k);
        }
    n = k;
    return used;
}
long long mst (vector<edge> &edges, int &k, int &n)
{
    long long res = 0;
    vector <int> min(n+1, MAXINT);
    for (int i = 0; i < edges.size(); i++)
        if (min[edges[i].to] > edges[i].w)
            min[edges[i].to] = edges[i].w;
    for (int i = 2; i < min.size(); i++)
        res += min[i];
    vector<vector<edge>> zero_graph_to(n + 1), zero_graph_from(n+1);
    vector<edge> zero_edges;
    for (int i = 0; i < edges.size(); i++)
    {
        edges[i].w -= min[edges[i].to];
        if (edges[i].w == 0) {
            zero_graph_from[edges[i].from].push_back(edges[i]);
            zero_graph_to[edges[i].to].push_back(edges[i]);
            zero_edges.push_back(edges[i]);
        }
    }
    for(int i = 1; i <= n; i++)
        min[i] = 0;
    if (dfs(zero_graph_from, min, k) == n)
        return res;
    vector<int> components = condensation(zero_graph_from, zero_graph_to, n);
    int tmp = components[1];
    for (int i = 1; i <= components.size(); i++)
    {
        if (components[i] == tmp)
            components[i] = 1;
        else
        {
            if (components[i] == 1)
                components[i] = tmp;
        }
    }
    zero_edges.resize(0);
    zero_graph_from.resize(0);
    zero_graph_to.resize(0);
    for (int i = 0; i < edges.size();i ++)
    {
        if ((components[edges[i].to] != components[edges[i].from]) && (components[edges[i].to] != k)) {
            edges[i].to = components[edges[i].to];
            edges[i].from = components[edges[i].from];
            zero_edges.push_back(edges[i]);
        }
    }
    res += mst(zero_edges, k, n);
    return res;
}
int main() {
    freopen("chinese.in", "r", stdin);
    freopen("chinese.out", "w", stdout);
    int n, m;
    edge p;
    cin >> n >> m;
    int k = 1;
    vector<vector<edge>> g(n + 1);
    vector<edge> edges;
    vector<int> comp(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> p.from >> p.to >> p.w;
        if (p.to != k) {
            g[p.from].push_back(p);
            edges.push_back(p);
        }
    }
    if (dfs(g, comp, k) != n)
        cout << "NO";
    else
    {
        cout << "YES\n" << mst(edges, k, n);;
    }
    return 0;
}