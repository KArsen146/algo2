#include <iostream>
#include <vector>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    int a, b;
    cin >> n >> m;
    vector<int> pow(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        pow[a]++;
        pow[b]++;
    }
    for (int i = 1; i <= n; i++)
        cout << pow[i] << ' ';
    return 0;
}