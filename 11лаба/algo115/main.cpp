#include <iostream>
#include <vector>
using namespace std;
const long long  INF = 2e18;
struct edge
{
    int to, from, w;
};
bool ford_bellman(vector<edge> &edges, vector<long long> &dist, int &n, vector<int> &p)
{
    dist[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            if (dist[edges[j].to] > dist[edges[j].from] + edges[j].w)
            {
                dist[edges[j].to] = dist[edges[j].from] + edges[j].w;
                p[edges[j].to] = edges[j].from;
            }
        }
    }
    int tmp = -1;
    for (int j = 0; j < edges.size(); j++)
    {
        if  (dist[edges[j].to] > dist[edges[j].from] + edges[j].w)
        {
            dist[edges[j].to] = dist[edges[j].from] + edges[j].w;
            p[edges[j].to] = edges[j].from;
            tmp = edges[j].from;
            for (int k = 0; k < n; k++)
                tmp = p[tmp];
        }
    }
    edges.resize(0);
    dist.resize(0);
    if (tmp > 0) {
        dist.push_back(tmp);
        tmp = p[tmp];
        dist.push_back(tmp);
        while (dist[dist.size() - 1] != dist[0])
        {
            tmp = p[tmp];
            dist.push_back(tmp);
        }
        return false;
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    edge tmp;
    vector<edge> edges;
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++) {
            cin >> tmp.w;
            if (tmp.w != 1e9)
            {
                tmp.from = i;
                tmp.to = j;
                edges.push_back(tmp);
            }
        }
    }
    vector<long long> dist(n + 1, INF);
    vector<int> p(n + 1, -1);
    if (ford_bellman(edges, dist, n, p))
        cout << "NO";
    else
    {
        cout << "YES\n" << dist.size() << '\n';
        for (int i = dist.size() - 1; i >= 0; i--)
            cout << dist[i] << ' ';
    }
    return 0;
}