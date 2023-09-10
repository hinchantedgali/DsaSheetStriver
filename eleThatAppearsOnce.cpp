// find the element that appears once.
// given --> other elements apprear twice.

#include <bits/stdc++.h>
using namespace std;

int eleAppearsOnceBrute(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (num == arr[j])
            {
                count++;
            }
        }
        if (count == 1)
            return num;
    }
}

int eleAppearsOnceHash(int arr[], int n)
{
    // find max element of the arr to create hashh

    int maxx = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxx)
        {
            maxx = arr[i];
        }
    }

    // store or prefetch in hash
    int hashh[maxx + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        hashh[arr[i]]++;
    }

    // iterate in hash to find the element appreaing once
    for (int i = 0; i < n; i++)
    {
        if (hashh[arr[i]] == 1)
            return arr[i];
    }
}

int eleAppearsOnceMap(int arr[], int n)
{
    map<int, int> mpp;

    // save it in the hashmap
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // iterate and search once appearing element
    for (auto it : mpp)
    {
        if (it.second == 1)
            return it.first;
    }
}

int eleAppearsOnceXOR(int arr[], int n)
{
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
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
    int num = eleAppearsOnceMap(arr, n);
    cout << num;

    return 0;
}