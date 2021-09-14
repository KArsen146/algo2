#include <iostream>
#include <vector>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    int a[100][100];
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    bool t = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if ((a[i][j] != a[j][i]) || (a[i][i] == 1))
            {
                t = false;
                break;
            }
        }
    if (t)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}