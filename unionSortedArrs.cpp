#include <bits/stdc++.h>
using namespace std;

void unionOfTwoSortedArrays(int arr1[], int arr2[], int p, int q)
{

    set<int> uni;

    for (int i = 0; i < p; i++)
    {
        uni.insert(arr1[i]);
    }
    for (int i = 0; i < q; i++)
    {
        uni.insert(arr2[i]);
    }
    int n = uni.size();
    int onion[n];
    int i = 0;

    for (auto it : uni)
    {
        onion[i++] = it;
    }

    for (auto it : onion)
    {
        cout << it << " ";
    }
}

vector<int> uniOfSortedArrsOptimal(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0;
    int j = 0;

    vector<int> uni;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (uni.size() == 0 || uni.back() != arr1[i])
            {
                uni.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (uni.size() == 0 || uni.back() != arr2[j])
            {
                uni.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (j < n2)
    {
        if (uni.size() == 0 || uni.back() != arr2[j])
        {
            uni.push_back(arr2[j]);
        }
        j++;
    }

    while (i < n1)
    {
        if (uni.size() == 0 || uni.back() != arr1[i])
        {
            uni.push_back(arr1[i]);
        }
        i++;
    }

    return uni;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int p, q;
    cin >> p >> q;

    int arr1[p];
    int arr2[q];

    for (int i = 0; i < p; i++)
    {
        cin >> arr1[p];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> arr2[q];
    }
    vector<int> res = uniOfSortedArrsOptimal(arr1, arr2, p, q);

    for (auto it : res)
    {
        cout << it << " ";
    }

    return 0;
}