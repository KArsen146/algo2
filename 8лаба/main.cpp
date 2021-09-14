#include <iostream>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    int x, y;
    cin >> n >> m;
    int a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}