#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
const int INF = 1e9 * 4;
class PriorityQueue
{
private:
    vector<pair<int, int>> v;
    void sift_up(int num)
    {
        int j = num;
        while ((v[(j - 1) / 2] > v[j]) && (j >=0))
        {
            swap(v[(j - 1) / 2], v[j]);
            j = (j - 1) / 2;
        }
    }
    void sift_down(int num)
    {
        int i = num;
        if ((2 * num + 1 < v.size()) && (v[2 * num + 1] < v[i]))
            i = 2 * i + 1;
        if (2 * num + 2 < v.size() &&(v[2 * num + 2] < v[i]))
            i = 2 * num + 2;
        if (i != num)
        {
            swap(v[i], v[num]);
            sift_down(i);
        }
    }
public:
    PriorityQueue()
    {}
    PriorityQueue(vector <pair<int,int>> &x)
    {
        v = x;
    }
    void push(int x, int num)
    {
        pair<int,int>p;
        p.first = x;
        p.second = num;
        v.push_back(p);
        sift_up(v.size() - 1);
    }
    void decrease_key(int x, int y)
    {
        int i = 0;
        while (v[i].second != y)
            i++;
        if (v[i].first > x)
        {
            v[i].first = x;
            sift_up(i);
        }
    }
    int pop() {
        if (v.size() != 0) {
            int x = v[0].first;
            swap(v[0], v[v.size() - 1]);
            v.resize(v.size() - 1);
            sift_down(0);
            return x;
        }
        else
            return 0;
    }
    int first()
    {
        return v[0].second;
    }
};
void dijkstra(vector<vector<pair<int,int>>> &g, int &n, PriorityQueue &q, vector<int> &dist)
{
    vector<bool> used(n +1, false);
    int ind;
    for (int i = 0; i < n; i++)
    {
        ind = q.first();
        dist[ind] = q.pop();
        used[ind] = true;
        for (int j = 0; j < g[ind].size(); j++) {
            if (!used[g[ind][j].second])
                q.decrease_key(g[ind][j].first + dist[ind], g[ind][j].second);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n, m, x, tmp;
    cin >> n >> m;
    pair<int, int> p;
    vector<vector<pair<int,int>>> g(n +1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> p.second >> p.first;
        g[x].push_back(p);
        tmp = p.second;
        p.second = x;
        x = tmp;
        g[x].push_back(p);
    }
    vector<pair<int, int>> v;
    p.first = 0;
    p.second = 1;
    v.push_back(p);
    for (int i = 1; i < n; i++)
    {
        p.first = INF;
        p.second = i + 1;
        v.push_back(p);
    }

    PriorityQueue q(v);
    vector<int>dist(n + 1, INF);
    dijkstra(g, n, q, dist);
    for (int i = 1; i <=n; i++)
        cout << dist[i] << ' ';
    return 0;
}