#include <iostream>
#include <vector>
using namespace std;
const int inf = 1e9;
void floyd(int n, vector<vector<int>> &a)
{
    for (int k = 1; k <=n; k++)
        for (int i = 1; i <=n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] >  a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
}
int main() {
    int n, m, x, y ,w;
    pair<int, int> tmp;
    cin >> n >> m;
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].resize(n + 1);
        for (int j = 1; j <= n; j++)
            a[i][j] = inf;
        a[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> w;
        a[x][y] = w;
        a[y][x] = w;
    }
    floyd(n, a);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}