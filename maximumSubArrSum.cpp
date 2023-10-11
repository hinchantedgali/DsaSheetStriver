#include <bits/stdc++.h>
using namespace std;

// better solution
long long maxxSubArrSum(int arr[], int n)
{
    long long maxx = LONG_MIN, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxx = max(maxx, sum);
        }
    }
    return maxx;
}

// Kadane's Algo MaxSubArrSum
long long maxxSubArrSumKadane(int arr[], int n)
{
    long long maxx = LONG_MIN, sum = 0;
    int start = 0, ans_start = -1, ans_end = -1;
    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += arr[i];
        if (sum > maxx)
        {
            maxx = sum;
            ans_start = start, ans_end = i;
        }
        if (sum < 0)
            sum = 0;
    }
    if (maxx < 0)
        maxx = 0;
    cout << "Indices of the sub array: " << ans_start << " " << ans_end << endl;
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

    cout << maxxSubArrSumKadane(arr, n);

    return 0;
}