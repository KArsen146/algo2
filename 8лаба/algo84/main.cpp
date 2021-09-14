#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void bfs(vector<vector<int>> &v, vector<int> &used, int &it, int &count)
{
    queue<int> q;
    used[it] = count;
    q.push(it);
    while (q.size() > 0)
    {
        for(int i = 0; i < v[q.front()].size(); i++)
        {
            if (used[v[q.front()][i]] == 0)
            {
                q.push(v[q.front()][i]);
                used[v[q.front()][i]] = count;
            }
        }
        q.pop();
    }
}
int main() {
    freopen("components.in", "r", stdin);
    freopen("components.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int a, b;
    vector<vector<int>> v(n + 1);
    vector<int> used(n + 1, 0);
    for (auto i = 0; i < m; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int count = 0;
    for (int ind = 1; ind <= n; ind++) {
        if (used[ind] == 0)
        {
            count ++;
            bfs(v, used, ind, count);
        }
    }
    cout << count << endl;
    for (int i = 1; i <= n; i++)
        cout << used[i] << ' ';
    return 0;
}