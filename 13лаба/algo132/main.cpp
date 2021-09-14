#include <iostream>
#include <vector>
#include <string>
using namespace std;
const long long q = 1e9 + 7;
const int p = 31;
long long mod_q(long long a)
{
    a = (a % q);
    a += q;
    a = a % q;
    return a;
}
int main()
{
    string s, s1;
    cin >> s >> s1;
    vector<long long> hashp(1, 0);
    vector<long long> pow(1, 1);
    for (auto i:s1)
    {
        hashp.push_back(mod_q(hashp[hashp.size() - 1] * p+ i));
        pow.push_back(mod_q(pow[pow.size() - 1] * p));
    }
    long long  hash = 0;
    for (auto i: s)
        hash = mod_q(hash * p + i);
    int k = s1.size() - s.size();
    vector<int> v;
    long long l;
    for (int i = 1; i <= k + 1; i++)
    {
        if(i == 1)
            l = hashp[s.length()];
        else
          {
            if (i == 10)
              cout << 1;
            l = mod_q (hashp[i + s.length () - 1] - hashp[i - 1] * pow[s.length ()]);
          }
        if (l == hash)
        {
            string s2(s1, i - 1, s.length());
            if ((s2[0] == s[0]) && (s2[s2.length() - 1] == s[s.length() - 1]))
                v.push_back(i);
        }
    }
    cout << hash << ' ';
    int j = 0;
    for (auto i : hashp)
      {
        cout << j << ' ' << i << endl;
        j++;
      }
    cout << endl;
    cout << v.size() << endl;
    for (auto i: v)
        cout << i<< ' ';
    cout << endl << pow[3];
    return 0;
}