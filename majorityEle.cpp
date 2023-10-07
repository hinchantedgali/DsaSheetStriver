#include <bits/stdc++.h>
using namespace std;

// brute by for loop O(n^2)

// hashing O(N*NlogN)
int majorityEle(int arr[], int n)
{
    map<int, int> mpp;

    // for marking the count of elements
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // finding out the maximum occurance value
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
            return it.first;
    }

    return -1;
}

// Moore's Voting Algo
int majorityMooresVotingAlgo(int arr[], int n)
{
    int ele = arr[0];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            count = 1;
            ele = arr[i];
        }
        else if (arr[i] == ele)
            count++;
        else
        {
            count--;
        }
    }

    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
            count1++;
    }
    if (count1 > n / 2)
        return ele;
    return -1;
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
    cout << majorityEle(arr, n);
    return 0;
}