#include <bits/stdc++.h>
using namespace std;

void removeDupsBrute(int arr[], int n)
{

    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }
    int index = 0;
    for (auto it : st)
    {
        arr[index] = it;
        index++;
    }

    cout << index << endl;

    for (int i = 0; i < index; i++)
    {
        cout << arr[i] << " ";
    }
}

void removeDupsOpt(int arr[], int n)
{
    // using 2 POINTER APPROACH
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[j] != arr[i] && i < j)
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }

    cout << i + 1 << endl;
    for (int s = 0; s <= i; s++)
    {
        cout << arr[s] << " ";
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
    cout << "Enter sorted array to remove dups in place." << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    removeDupsOpt(arr, n);

    return 0;
}