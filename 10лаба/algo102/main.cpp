#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;
class PriorityQueue
{
private:
    vector<pair<double, int>> v;
    void sift_up(int num)
    {
        int j = num;
        while ((v[(j - 1) / 2] > v[j]) && (j >=0))
        {
            swap(v[(j - 1) / 2], v[j]);
            j = (j - 1) / 2;
        }
    }
    void sift_down(int num)
    {
        int i = num;
        if ((2 * num + 1 < v.size()) && (v[2 * num + 1] < v[i]))
            i = 2 * i + 1;
        if (2 * num + 2 < v.size() &&(v[2 * num + 2] < v[i]))
            i = 2 * num + 2;
        if (i != num)
        {
            swap(v[i], v[num]);
            sift_down(i);
        }
    }
public:
    PriorityQueue()
    {}
    void push(double x, int num)
    {
        pair<double,int>p;
        p.first = x;
        p.second = num;
        v.push_back(p);
        sift_up(v.size() - 1);
    }
    void decrease_key(double x, int y)
    {
        int i = 0;
        while (v[i].second != y)
            i++;
        if (v[i].first > x)
        {
            v[i].first = x;
            sift_up(i);
        }
    }
    double pop() {
        if (v.size() != 0) {
            double x = v[0].first;
            swap(v[0], v[v.size() - 1]);
            v.resize(v.size() - 1);
            sift_down(0);
            return x;
        }
        else
            return 0;
    }
    int first()
    {
        return v[0].second;
    }

};
double distance(int i, int j, vector<pair<int, int>> &points)
{
    return sqrt(pow((points[i].first - points[j].first), 2) + pow((points[i].second - points[j].second), 2));
}
int main()
{
    //freopen("spantree.in", "r", stdin);
    //freopen("spantree.out", "w", stdout);
    int n;
    cin >> n;
    vector <pair<int,int>> points(n + 1);
    vector <bool> used(n + 1, false);
    int x, y;
    PriorityQueue q;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        pair<int, int> point;
        point.first = x;
        point.second = y;
        points[i] = point;
        q.push(distance(i, 1, points), i);
    }
    int a = q.first();
    used[a] = true;
    double sum = q.pop();
    for (int i = 1; i <= n; i++)
    {
        a = q.first();
        sum = sum + q.pop();
        used[a] = true;
        for (int j = 1; j <= n; j++)
        {
            if (!used[j])
                q.decrease_key(distance(j, a, points), j);
        }
    }
    cout.precision(6);
    cout  << fixed << sum;
    return 0;
}