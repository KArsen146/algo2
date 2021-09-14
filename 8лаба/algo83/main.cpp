#include <iostream>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int m;
    int a[1001][1001];
    cin >> n;
    cin >> m;
    int c; int d;
    for (int i = 0; i < m; i++)
    {
        cin >> c >> d;

        if (a[c][d] == 1) {
            cout << "YES";
            return 0;
        }
        a[c][d] = 1;
        a[d][c] = 1;
    }
    cout << "NO";
    return 0;
}