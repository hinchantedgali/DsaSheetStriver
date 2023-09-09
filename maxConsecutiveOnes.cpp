#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(int arr[], int n)
{
    int maxx = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1)
        {
            cnt++;
            maxx = max(maxx, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    return maxx;
}

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
    int num = maxConsecutiveOnes(arr, n);
    cout << num;
    return 0;
}