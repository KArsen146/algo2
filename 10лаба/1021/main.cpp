#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
const double MAX_INT = 30000;
void prim(vector<pair<int,int>> g, vector<double> &dist, vector<bool> &used, double &sum, int min_ind, int n)
{
    int tmp;
    for (int k = 1; k <= n; k++) {
        used[min_ind] = true;
        sum = sum + dist[min_ind];
        double min = MAX_INT;
        tmp = min_ind;
        min_ind = -1;
        double way;
        for (int j = 1; j <= n; j++) {
            if (!used[j]) {
                way = sqrt(pow((g[tmp].first - g[j].first), 2) + pow((g[tmp].second - g[j].second), 2));
                if (way < dist[j])
                    dist[j] = way;
                if (dist[j] < min) {
                    min = dist[j];
                    min_ind = j;
                }
            }
        }
    }
}
int main() {
    freopen("spantree.in", "r", stdin);
    freopen("spantree.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int,int>> g(n + 1);
    vector<double> dist(n + 1);
    vector<bool> used(n + 1, false);
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> g[i].first >> g[i].second;
        dist[i] = MAX_INT;
    }
    dist[1] = 0;
    prim(g, dist, used, sum, 1, n);
    cout.precision(6);
    cout  << fixed << sum;
    return 0;
}