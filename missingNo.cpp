#include <bits/stdc++.h>
using namespace std;

// given N, and array of size N-1, these N-1 nos will be containing
// nos from 1 to N, so find the no which is not there from 1 to N

int findMissingNo(int arr[], int n)
{
    bool flag = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (i == arr[j])
            {
                flag = true;
                break;
            }
        }
        if (flag == false)
            return i;
    }
}

/*int findMissingNoHashh(int arr[], int n)
{
    int hashh[n + 1] = {0};
    // precompute
    for (int i = 0; i < n - 1; i++)
    {
        hashh[arr[i]] = +1;
    }

    // fetch
    for (int i = 1; i < n + 1; i++)
    {
        if (hashh[i] == 0)
            return i;
    }
}*/

int findMissingNoOptUsingSum(int arr[], int n)
{

    int sum = n * (n + 1) / 2;
    int sumArr = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sumArr += arr[i];
    }
    return (sum - sumArr);
}

int findMissingNoOptUsingXOR(int arr[], int n)
{
    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;

    return (xor1 ^ xor2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n - 1];

    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    int num = findMissingNoOptUsingXOR(arr, n);

    cout << num;

    return 0;
}