#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> prefix;
vector<vector<int>> avtomat;
int prefix_f(string &s, int i, int j)
{
    if (s[i] == j + '0')
        return i + 1;
    if (i == 0)
        return 0;
    int k = prefix[i - 1];
    return avtomat[k][j];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int n;
    cin >> n;
    string s;
    cin >> s;
    avtomat.resize(s.length() + 1, vector<int> (n));
    prefix.resize(s.length(), 0);
    int k;
    for (int i = 1; i < s.length(); i++)
    {
        k = prefix[i - 1];
        while ((s[i] != s[k]) && (k > 0))
            k = prefix[k - 1];
        if (s[i] == s[k])
            k++;
        prefix[i] = k;
    }
    for (int i = 0; i <= s.length(); i++)
    {
        for (int j = 0; j < n; j++)
            avtomat[i][j] = prefix_f(s, i, j);
    }
    for (auto &v : avtomat)
    {
        for (auto& i: v)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}