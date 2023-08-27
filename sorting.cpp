#include <bits/stdc++.h>
using namespace std;

void myMerge(int arr[], int l, int mid, int h)
{
    vector<int> res;
    int left, right;
    left = l, right = mid + 1;
    while (left <= mid && right <= h)
    {
        if (arr[left] < arr[right])
        {
            res.emplace_back(arr[left]);
            left++;
        }
        else
        {
            res.emplace_back(arr[right]);
            right++;
        }
        while (left <= mid)
        {
            res.emplace_back(arr[left]);
            left++;
        }
        while (right <= h)
        {
            res.emplace_back(arr[right]);
            right++;
        }
    }
    for (int i = l; i <= h; i++)
    {
        arr[i] = res[i - l];
    }
}

void myMergeSort(int arr[], int l, int h)
{
    if (l >= h)
        return;

    int mid = l + (h - l) / 2;
    myMergeSort(arr, l, mid);
    myMergeSort(arr, mid + 1, h);
    myMerge(arr, l, mid, h);
}

int quickPartition(int arr[], int p, int q)
{
    int j;
    int i = p;
    int pivot = arr[p];
    for (j = p + 1; j < q; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i], arr[p]);
    return i;
}

void quickSort(int arr[], int p, int q)
{
    if (p == q)
        return;
    else
    {
        int mid = quickPartition(arr, p, q);
        quickSort(arr, p, mid);
        quickSort(arr, mid + 1, q);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, l = 0;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, l, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}