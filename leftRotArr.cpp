#include <bits/stdc++.h>
using namespace std;

void leftRotateArrByOnePlace(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

void leftRotateArrByKPlaces(int arr[], int n, int d)
{
    int k = d % n;
    int temp[k];

    if (k != 0)
    {
        for (int i = 0; i < k; i++)
        {
            temp[i] = arr[i];
            cout << temp[i] << " " << endl;
        }

        for (int i = k; i < n; i++)
        {
            arr[i - k] = arr[i];
        }
        for (int i = n - k; i < n; i++)
        {
            arr[i] = temp[i - (n - k)];
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
    int k;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    leftRotateArrByKPlaces(arr, n, k);
    for (auto it : arr)
    {
        cout << it << " ";
    }

    return 0;
}