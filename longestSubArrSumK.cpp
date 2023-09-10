#include <bits/stdc++.h>
using namespace std;

int longestSubArrBrute(int arr[], int n, long long k)
{
    int len = 0;
    for (int i = 0; i < n; i++)
    {
        long long s = 0;
        for (int j = i; j < n; j++)
        {
            s = s + arr[j];
            if (s == k)
                len = max(len, (j - i + 1));
        }
    }
    return len;
}

int longestSubArrHashMap(int arr[], int n, long long k)
{

    map<long long, int> preSumMap;
    long long sum = 0;
    int maxLen;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, (i + 1));
        }

        long long rem = sum - k;
        if (preSumMap.find(rem) != preSumMap.end())
        {
            maxLen = max(maxLen, (i - preSumMap[rem]));
        }

        if (preSumMap.find(sum) == preSumMap.end())
        {
            preSumMap[sum] = i;
        }
    }
    return maxLen;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    long long k;
    cin >> n;
    cin >> k;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int num = longestSubArrHashMap(arr, n, k);
    cout << num;

    return 0;
}