#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int c;
    int f;
    int num;
    int reverse_ind;
};

vector<vector<Edge>> graph;
vector<int> shortest_ways;
vector<vector<int>> ways;
vector<int> ptr;
int s, t;
int k = 0;

int dfs(int v, int delta) {
    if((v == t) || (delta == 0))
        return delta;
    for(ptr[v]; ptr[v] < graph[v].size(); ptr[v]++)
        if((shortest_ways[graph[v][ptr[v]].to] == shortest_ways[v] + 1) && (graph[v][ptr[v]].f < graph[v][ptr[v]].c)) {
            int delta1 = dfs(graph[v][ptr[v]].to, min(delta, graph[v][ptr[v]].c - graph[v][ptr[v]].f));
            if(delta1 > 0) {
                graph[v][ptr[v]].f += delta1;
                graph[graph[v][ptr[v]].to][graph[v][ptr[v]].reverse_ind].f -= delta1;
                return delta1;
            }
        }
    return 0;
}

bool bfs(int v, int n) {
    shortest_ways.assign(n, INT_MAX);
    shortest_ways[s] = 0;
    queue<int> q;
    q.push(v);
    while(!q.empty()) {
        v = q.front();
        q.pop();
        for(auto i : graph[v]) {
            if((shortest_ways[i.to] == INT_MAX) && (i.f < i.c)) {
                q.push(i.to);
                shortest_ways[i.to] = shortest_ways[v] + 1;
            }
        }
    }
    return shortest_ways[t] != INT_MAX;
}

int GetPath(int v, int flow) {
    if(v == t)
        return flow;
    for(auto &i : graph[v])
        if(i.f > 0) {
            ways[k].push_back(i.num);
            int x = GetPath(i.to, min(flow, i.f));
            i.f -= x;
            return x;
        }
    return 0;
}

int main() {
    int n, m;
    cin >> n >> m;
    s = 0;
    t = n - 1;
    graph.resize(n);
    shortest_ways.resize(n);
    ptr.resize(n);
    for(int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a - 1].push_back({b - 1, w, 0, i + 1, (int)graph[b - 1].size()});
        graph[b - 1].push_back({a - 1, 0, 0, 0, (int)graph[a - 1].size() - 1});
    }
    int delta;
    while(bfs(s, n)) {
        ptr.assign(n, 0);
        do delta = dfs(s, INT_MAX);
        while (delta > 0);
    }
    while(true){
        ways.emplace_back();
        int flow = GetPath(s, INT_MAX);
        if(flow == 0)
            break;
        ways[k].push_back(flow);
        k++;
    }
    cout << k << "\n";
    for(int i = 0; i < k; i++) {
        int size = ways[i].size();
        cout << ways[i][size - 1] << " " << size - 1 << " ";
        for(int j = 0; j < size - 1; j++)
            cout << ways[i][j] << " ";
        cout << "\n";
    }
    return 0;
}