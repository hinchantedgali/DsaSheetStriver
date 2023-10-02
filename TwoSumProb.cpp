#include <bits/stdc++.h>
using namespace std;
void twoSumProbBrute(int arr[], int n, int target)
{
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] + arr[j]) == target)
            {
                flag = true;
                break;
            }
        }
    }

    if (flag)
        cout << "yes";
    else
        cout << "no";
}

string twoSumHashmap(int arr[], int n, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int more = target - num;
        if (mpp.find(more) != mpp.end())
        {
            return "yes"; // return {mpp[more], i};
        }
        mpp[arr[i]] = i;
    }
    return "no"; // return {-1, -1};
}

string twoSumTwoPtrApproach(int arr[], int n, int target)
{
    int l = 0;
    int r = n - 1;
    sort(arr, arr + n);
    while (l < r)
    {
        if (arr[l] + arr[r] == target)
        {
            return "YES";
        }
        else if (arr[l] + arr[r] < target)
        {
            l++;
        }
        else
        {
            r--;
        }
    }
    return "NO";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int target;
    cin >> target;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << twoSumTwoPtrApproach(arr, n, target);

    return 0;
}