#include <bits/stdc++.h>
using namespace std;

void moveZeroesToEndBrute(int arr[], int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            temp.push_back(arr[i]);
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        arr[i] = temp[i];
    }
    for (int i = temp.size(); i < n; i++)
    {
        arr[i] = 0;
    }
}

void moveZeroesToEndOPt(int arr[], int n)
{
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            i++;
            arr[i] = arr[j];
        }
    }
    for (int l = i + 1; l < n; l++)
    {
        arr[l] = 0;
    }
}

void moveZeroesToEndOPtDoosra(int arr[], int n)
{
    int z = -1;
    // loop to find the first ZERO
    for (int j = 0; j < n; j++)
    {
        if (arr[j] == 0)
        {
            z = j;
            break;
        }
    }

    for (int j = z + 1; j < n; j++)
    {
        if (arr[j] != 0)
        { // means nonzero
            swap(arr[z], arr[j]);
            z++;
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

    moveZeroesToEndOPtDoosra(arr, n);
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}