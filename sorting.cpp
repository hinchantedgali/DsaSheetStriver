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

int quickPartition(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        while (arr[i] <= pivot && i < h - 1)
        {
            i++;
        }
        while (arr[j] >= pivot && j > l + 1)
        {
            j++;
        }
        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[j], arr[l]);
    return j;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int m = quickPartition(arr, l, h);
        quickSort(arr, l, m - 1);
        quickSort(arr, m + 1, h);
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
    quickSort(arr, l, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}