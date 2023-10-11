#include <bits/stdc++.h>
using namespace std;

int buyAndSellStocks(int arr[], int n)
{
    int maxProfit = INT_MIN, cost = 0, mini = arr[0];
    for (int i = 1; i < n; i++)
    {
        cost = arr[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, arr[i]);
    }
    return maxProfit;
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

    cout << buyAndSellStocks(arr, n);

    return 0;
}