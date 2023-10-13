#include <bits/stdc++.h>
using namespace std;

// brute take extra Pos and Neg array
void rearrageArray(int arr[], int n)
{
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        if (arr[i] < 0)
            neg.push_back(arr[i]);
    }
    for (int i = 0; i < n / 2; i++)
    {
        arr[2 * i] = pos[i];
        arr[2 * i + 1] = neg[i];
    }
}

void rearrangeArrayOpt(int arr[], int n)
{
    int posIndex = 0, negIndex = 1;
    int ans[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            ans[posIndex] = arr[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = arr[i];
            negIndex += 2;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}
void rearrangeVariation(int arr[], int n)
{
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = 2 * neg.size();
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        int index = 2 * pos.size();
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }
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
    rearrangeVariation(arr, n);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}