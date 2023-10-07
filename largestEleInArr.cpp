#include <bits/stdc++.h>
using namespace std;

int largestele(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

// using better approach
int seclargest(int arr[], int n)
{
    int largest = largestele(arr, n);
    int seclargest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > seclargest && arr[i] != largest)
        {
            seclargest = arr[i];
        }
    }
    return seclargest;
}

vector<int> secLargestOpt(int arr[], int n)
{
    vector<int> res;
    int seclargest = INT_MIN; // or take INT_MIN
    int largest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            seclargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > seclargest)
        {
            seclargest = arr[i];
        }
    }
    res.push_back(largest);
    res.push_back(seclargest);
    return res;
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

    vector<int> pRes = secLargestOpt(arr, n);
    cout << pRes[0] << " " << pRes[1] << endl;
    // cout << secLargestOpt(arr, n);

    return 0;
}