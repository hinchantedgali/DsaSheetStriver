#include <bits/stdc++.h>
using namespace std;

/*
USE MPP<CHAR,INT>
SIMPLE XOXO

for strings
can't use <int,int> and
can't do typecasting of characters
to int for storing them in charHashmapp
*/

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    getline(cin, s);

    // prefetch using hashmap of <char,int>
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }

    // showing the hashmap
    for (auto it : mpp)
    {
        cout << it.first << "-->" << it.second << endl;
    }

    // taking the query
    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        // fetch
        cout << c << " " << mpp[c] << endl;
    }

    return 0;
}