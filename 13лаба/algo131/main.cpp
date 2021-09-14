#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s, s1;
    cin >> s >> s1;
    vector<int> v;
    int k = s1.length() - s.length();
    for (int i = 0; i <= k; i++)
    {
        string s2(s1, i, s.length());
        if (s2 == s)
            v.push_back(i + 1);
    }
    cout << v.size() << endl;
    for (auto &i : v)
        cout << i << ' ';
    return 0;
}