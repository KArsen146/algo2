#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> &v, vector<int> &used, int it)
{
    queue<int> q;
    used[it] = 0;
    q.push(it);
    while (q.size() > 0)
    {
        for(int i = 0; i < v[q.front()].size(); i++)
        {
            if ((used[v[q.front()][i]] == -1) || (used[v[q.front()][i]] > used[q.front()] + 1))
            {









                4 5
                1 2 1
                1 3 2
                3 2 1
                2 4 2
                3 4 1







                q.push(v[q.front()][i]);
                used[v[q.front()][i]] = used[q.front()] + 1;
            }
        }
        q.pop();
    }
}
int main() {
    freopen("pathbge1.in", "r", stdin);
    freopen("pathbge1.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> v(n + 1);
    vector<int> used(n + 1, -1);
    for (auto i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(v, used, 1);
    for (int i = 1; i <= n; i++)
        cout << used[i] << ' ';
    return 0;
}