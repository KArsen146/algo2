#include <iostream>
#include <vector>
using namespace std;
const long long  INF = 2e18;
struct edge
{
    int to, from;
    long long w;
};
void dfs(vector<edge> &edges, vector<long long> &dist, int i)
{
    dist[i] = -INF;
    for (auto & edge : edges)
    {
        if (edge.from == i)
        {
            if (dist[edge.to] != -INF)
                dfs(edges, dist, edge.to);
        }
    }
}
void ford_bellman(vector<edge> &edges, vector<long long> &dist, int &n, vector<int> &p)
{
    for (int i = 1; i < n; i++)
    {
        for (auto & edge : edges)
        {
            if ((dist[edge.from] != INF) && (dist[edge.to] > dist[edge.from] + edge.w))
            {
                dist[edge.to] = max(-INF, dist[edge.from] + edge.w);
                p[edge.to] = edge.from;
            }
        }
    }
    for (auto & edge : edges)
    {
        if  ((dist[edge.from] != INF) && (dist[edge.to] > dist[edge.from] + edge.w))
        {
            dist[edge.to] = max(-INF, dist[edge.from] + edge.w);
            dfs(edges, dist, edge.from);
        }
    }
}
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    edge tmp;
    vector<edge> edges;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp.from >> tmp.to >> tmp.w;
        edges.push_back(tmp);
    }
    vector<long long> dist(n + 1, INF);
    dist[s] = 0;
    vector<int> p(n + 1, -1);
    ford_bellman(edges, dist, n, p);
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
            cout << '*' << endl;
        if (dist[i] == -INF)
            cout << '-' << endl;
        if ((dist[i] != INF) && (dist[i] != -INF))
            cout << dist[i] << endl;
    }
    return 0;
}