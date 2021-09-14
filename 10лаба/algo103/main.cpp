#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct edge
{
    int w, st, fin;
};
bool cmp(edge a, edge b)
{
    return a.w < b.w;
}
void Kruscal(vector<int> &graph, vector<edge> &edges, long long &sum)
{
    edge tmp;
    int count = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        tmp = edges[i];
        if ((graph[tmp.st] == -1) && (graph[tmp.fin] == -1))
        {
            count ++;
            graph[tmp.st] = count;
            graph[tmp.fin] = count;
            sum = sum + tmp.w;
        }
        if ((graph[tmp.st] == -1) || (graph[tmp.fin] == -1))
        {
            if (graph[tmp.st] != -1)
                graph[tmp.fin] = graph[tmp.st];
            else
                graph[tmp.st] = graph[tmp.fin];
            sum = sum + tmp.w;
        }
        if (graph[tmp.st] != graph[tmp.fin])
        {
            int color_fin = graph[tmp.fin];
            for (int j = 1; j <= graph.size(); j++)
                if (graph[j] == color_fin)
                    graph[j] = graph[tmp.st];
            sum = sum + tmp.w;
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<edge> edges(2 * m);
    vector<int> graph(n + 1, -1);
    for (int i = 0; i < m; i ++)
    {
        cin >> edges[i].st >> edges[i].fin >> edges[i].w;
        edges[i + m].st = edges[i].st;
        edges[i + m].fin = edges[i].fin;
        edges[i+m].w = edges[i].w;

    }
    sort(edges.begin(), edges.end(), cmp);
    long long sum = 0;
    Kruscal(graph, edges, sum);
    cout << sum;
    return 0;
}