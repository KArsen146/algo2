#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void make_graph(vector<vector<pair<char,int>>> &v, int x, int y, int n, int m)
{
    if ((y - 1 > 0) && (v[x][y - 1].first != '#') && (v[x][y - 1].first != 'S'))
    {
        if ((v[x][y - 1].second > v[x][y].second + 1) || (v[x][y-1].second == 0))
        {
            v[x][y - 1].first = 'L';
            v[x][y - 1].second = v[x][y].second + 1;
            make_graph(v, x, y - 1, n ,m);
        }
    }
    if ((y< m) && (v[x][y + 1].first != '#') && (v[x][y + 1].first != 'S'))
    {
        if ((v[x][y + 1].second > v[x][y].second + 1)  || (v[x][y+1].second == 0))
        {
            v[x][y + 1].first = 'R';
            v[x][y + 1].second = v[x][y].second + 1;
            make_graph(v, x, y + 1,n ,m);
        }
    }
    if ((x < n) && (v[x + 1][y].first != '#') && (v[x + 1][y].first != 'S'))
    {
        if ((v[x + 1][y].second > v[x][y].second + 1)  || (v[x+1][y].second == 0))
        {
            v[x + 1][y].first = 'D';
            v[x + 1][y].second = v[x][y].second + 1;
            make_graph(v, x + 1, y, n ,m);
        }
    }
    if ((x - 1 > 0) && (v[x - 1][y].first != '#') && (v[x - 1][y ].first != 'S'))
    {
        if ((v[x - 1][y].second > v[x][y].second + 1)  || (v[x-1][y].second == 0))
        {
            v[x - 1][y].first = 'U';
            v[x - 1][y].second = v[x][y].second + 1;
            make_graph(v, x - 1, y, n ,m);
        }
    }
}

void road(vector<vector<pair<char, int>>> &v, int fx, int fy)
{
    stack<char> st;
    int i = fx, j = fy;
    while(v[i][j].first != 'S')
    {
        st.push(v[i][j].first);
        switch (v[i][j].first)
        {
            case 'D':
                i = i - 1;
                break;
            case 'U':
                i = i + 1;
                break;
            case 'L':
                j = j + 1;
                break;
            case 'R':
                j = j - 1;
        }
    }
    int k = st.size();
    for (int i = 0; i < k; i++)
    {
        cout << st.top();
        st.pop();
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int a, b, fx, fy;
    vector<vector<pair<char, int>>> g;
    g.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        g[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j].first;
            g[i][j].second = 0;
            if (g[i][j].first == 'S') {
                a = i;
                b = j;
            }
            if (g[i][j].first == 'T')
            {
                fx = i;
                fy = j;
            }
        }
    }
    make_graph(g, a, b, n, m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << g[i][j].first << ' ';
        cout << endl;
    }
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << g[i][j].second << ' ';
        cout << endl;
    }
    if (g[fx][fy].second == 0)
    {
        cout << -1;
        return 0;
    }
    cout << g[fx][fy].second << endl;
    stack<char> st;
    road(g, fx, fy);
    int aw = 0;
    for (int i = 0 ; i < INT_MAX; ++ i) {
        aw+= 1;
    }
    exit(0);
    return 0;
}