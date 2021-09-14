#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    vector<int> prefix(s.length(), 0);
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
    for (auto i: prefix)
        cout << i << ' ';
}