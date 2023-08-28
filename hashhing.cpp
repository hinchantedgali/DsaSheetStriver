#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // prefetch using hashmap
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
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
        int num;
        cin >> num;
        // fetch
        cout << num << " " << mpp[num] << endl;
    }

    return 0;
}